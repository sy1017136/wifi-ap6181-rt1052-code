/*
 * Copyright 2018, Cypress Semiconductor Corporation or a subsidiary of 
 * Cypress Semiconductor Corporation. All Rights Reserved.
 * 
 * This software, associated documentation and materials ("Software"),
 * is owned by Cypress Semiconductor Corporation
 * or one of its subsidiaries ("Cypress") and is protected by and subject to
 * worldwide patent protection (United States and foreign),
 * United States copyright laws and international treaty provisions.
 * Therefore, you may use this Software only as provided in the license
 * agreement accompanying the software package from which you
 * obtained this Software ("EULA").
 * If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
 * non-transferable license to copy, modify, and compile the Software
 * source code solely for use in connection with Cypress's
 * integrated circuit products. Any reproduction, modification, translation,
 * compilation, or representation of this Software except as specified
 * above is prohibited without the express written permission of Cypress.
 *
 * Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress
 * reserves the right to make changes to the Software without notice. Cypress
 * does not assume any liability arising out of the application or use of the
 * Software or any product or circuit described in the Software. Cypress does
 * not authorize its products for use in any products where a malfunction or
 * failure of the Cypress product may reasonably be expected to result in
 * significant property damage, injury or death ("High Risk Product"). By
 * including Cypress's product in a High Risk Product, the manufacturer
 * of such system or application assumes all risk of such use and in doing
 * so agrees to indemnify Cypress against all liability.
 */
#pragma once

#include "platform.h" /* Include the platform to determine if it has buttons */

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************
 *                      Macros
 ******************************************************/

/******************************************************
 *                    Constants
 ******************************************************/

/******************************************************
 *                   Enumerations
 ******************************************************/
typedef enum
{
    BACK_BUTTON,
    FORWARD_BUTTON,
    VOLUME_UP_BUTTON,
    VOLUME_DOWN_BUTTON,
    PLAY_PAUSE_BUTTON,
    MULTI_FUNCTION_BUTTON,
} application_button_t;

typedef enum
{
    NO_ACTION = 0x0,
    ACTION_MULTI_FUNCTION_SHORT_RELEASE = 0x1,
    ACTION_MULTI_FUNCTION_LONG_RELEASE,
    ACTION_PAUSE_PLAY,
    ACTION_STOP,
    ACTION_FORWARD,
    ACTION_BACKWARD,
    ACTION_FAST_FORWARD_HELD,
    ACTION_FAST_FORWARD_RELEASE,
    ACTION_FAST_REWIND_HELD,
    ACTION_FAST_REWIND_RELEASE,
    ACTION_VOLUME_UP,
    ACTION_VOLUME_DOWN,
    ACTION_WLAN_INIT,
    ACTION_WLAN_DEINIT,
    ACTION_WLAN_CONNECT,
    ACTION_WLAN_DISCONNECT,
    ACTION_WLAN_MODE_SWITCH,
    ACTION_EQ_SETTING,
} app_service_action_t;

/******************************************************
 *                 Type Definitions
 ******************************************************/
#ifdef WICED_PLATFORM_BUTTON_COUNT
typedef wiced_result_t (*WICED_APP_BUTTON_HANDLER)( app_service_action_t action );
#endif

/******************************************************
 *                    Structures
 ******************************************************/

/******************************************************
 *                 Global Variables
 ******************************************************/

/******************************************************
 *               Function Declarations
 ******************************************************/

#ifdef WICED_PLATFORM_BUTTON_COUNT

wiced_result_t headset_init_button_interface(void);

#else
/* Default button initialization for platforms without buttons */
wiced_result_t headset_init_button_interface()
{
    return WICED_SUCCESS;
}
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif