/*
 *  Symbol built-in
 */

#include "duk_internal.h"

#if defined(DUK_USE_SYMBOL_BUILTIN)

/*
 *  Constructor
 */

DUK_INTERNAL duk_ret_t duk_bi_symbol_constructor_shared(duk_context *ctx) {
	duk_hthread *thr;
	const duk_uint8_t *desc;
	duk_size_t len;
	duk_uint8_t *buf;
	duk_uint8_t *p;
	duk_int_t magic;

	thr = (duk_hthread *) ctx;

	magic = duk_get_current_magic(ctx);
	if (duk_is_undefined(ctx, 0) && (magic == 0)) {
		/* Symbol() accepts undefined and empty string, but they are
		 * treated differently.
		 */
		desc = NULL;
		len = 0;
	} else {
		/* Symbol.for() coerces undefined to 'undefined' */
		desc = (const duk_uint8_t *) duk_to_lstring(ctx, 0, &len);
	}

	/* Maximum symbol data length:
	 *   +1    initial byte (0x80 or 0x81)
	 *   +len  description
	 *   +1    0xff after description, before unique suffix
	 *   +17   autogenerated unique suffix: 'ffffffff-ffffffff' is longest
	 *   +1    0xff after unique suffix for symbols with undefined description
	 */
	buf = (duk_uint8_t *) duk_push_fixed_buffer(ctx, 1 + len + 1 + 17 + 1);
	p = buf + 1;
	DUK_ASSERT(desc != NULL || len == 0);  /* may be NULL if len is 0 */
	DUK_MEMCPY((void *) p, (const void *) desc, len);
	p += len;
	if (magic == 0) {
		/* Symbol(): create unique symbol.  Use two 32-bit values
		 * to avoid dependency on 64-bit types and 64-bit integer
		 * formatting (at least for now).
		 */
		if (++thr->heap->sym_counter[0] == 0) {
			thr->heap->sym_counter[1]++;
		}
		p += DUK_SPRINTF((char *) p, "\xFF" "%lx-%lx",
		                 (unsigned long) thr->heap->sym_counter[1],
		                 (unsigned long) thr->heap->sym_counter[0]);
		if (desc == NULL) {
			/* Special case for 'undefined' description, trailing
			 * 0xff distinguishes from empty string description,
			 * but needs minimal special case handling elsewhere.
			 */
			*p++ = 0xff;
		}
		buf[0] = 0x81;
	} else {
		/* Symbol.for(): create a global symbol */
		buf[0] = 0x80;
	}

	duk_push_lstring(ctx, (const char *) buf, (duk_size_t) (p - buf));
	DUK_DDD(DUK_DDDPRINT("created symbol: %!T", duk_get_tval(ctx, -1)));
	return 1;
}

DUK_LOCAL duk_hstring *duk__auto_unbox_symbol(duk_context *ctx, duk_tval *tv_arg) {
	duk_tval *tv;
	duk_tval tv_val;
	duk_hobject *h_obj;
	duk_hstring *h_str;

	DUK_ASSERT(tv_arg != NULL);

	/* XXX: add internal helper: duk_auto_unbox_tval(ctx, tv, mask); */
	/* XXX: add internal helper: duk_auto_unbox(ctx, tv, idx); */

	tv = tv_arg;
	if (DUK_TVAL_IS_OBJECT(tv)) {
		h_obj = DUK_TVAL_GET_OBJECT(tv);
		DUK_ASSERT(h_obj != NULL);
		if (DUK_HOBJECT_GET_CLASS_NUMBER(h_obj) == DUK_HOBJECT_CLASS_SYMBOL) {
			if (!duk_hobject_get_internal_value(((duk_hthread *) ctx)->heap, h_obj, &tv_val)) {
				return NULL;
			}
			tv = &tv_val;
		} else {
			return NULL;
		}
	}

	if (!DUK_TVAL_IS_STRING(tv)) {
		return NULL;
	}
	h_str = DUK_TVAL_GET_STRING(tv);
	DUK_ASSERT(h_str != NULL);

	if (!DUK_HSTRING_HAS_SYMBOL(h_str)) {
		return NULL;
	}

	return h_str;
}

DUK_INTERNAL duk_ret_t duk_bi_symbol_tostring_shared(duk_context *ctx) {
	duk_hstring *h_str;

	h_str = duk__auto_unbox_symbol(ctx, DUK_HTHREAD_THIS_PTR((duk_hthread *) ctx));
	if (h_str == NULL) {
		return DUK_RET_TYPE_ERROR;
	}

	if (duk_get_current_magic(ctx) == 0) {
		/* .toString() */
		duk_push_symbol_descriptive_string(ctx, h_str);
	} else {
		/* .valueOf() */
	}
	return 1;
}

DUK_INTERNAL duk_ret_t duk_bi_symbol_key_for(duk_context *ctx) {
	duk_hstring *h;
	const duk_uint8_t *p;

	/* Argument must be a symbol but not checked here.  The initial byte
	 * check will catch non-symbol strings.
	 */
	h = duk_require_hstring(ctx, 0);
	DUK_ASSERT(h != NULL);

	p = (const duk_uint8_t *) DUK_HSTRING_GET_DATA(h);
	DUK_ASSERT(p != NULL);

	/* Even for zero length strings there's at least one NUL byte so
	 * we can safely check the initial byte.
	 */
	if (p[0] == 0x80) {
		/* Global symbol, return its key (bytes just after the initial byte). */
		duk_push_lstring(ctx, (const char *) (p + 1), DUK_HSTRING_GET_BYTELEN(h) - 1);
		return 1;
	} else if (p[0] == 0x81 || p[0] == 0xff) {
		/* Local symbol or hidden symbol, return undefined. */
		return 0;
	}

	/* Covers normal strings and unknown initial bytes. */
	return DUK_RET_TYPE_ERROR;
}

DUK_INTERNAL duk_ret_t duk_bi_symbol_toprimitive(duk_context *ctx) {
	duk_hstring *h_str;

	h_str = duk__auto_unbox_symbol(ctx, DUK_HTHREAD_THIS_PTR((duk_hthread *) ctx));
	if (h_str == NULL) {
		return DUK_RET_TYPE_ERROR;
	}
	duk_push_hstring(ctx, h_str);
	return 1;
}

#endif  /* DUK_USE_SYMBOL_BUILTIN */
