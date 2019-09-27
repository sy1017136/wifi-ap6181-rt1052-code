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

/** @file
 * Defines peripherals available for use on CY8CKIT_062 board
 */
#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

/******************************************************
 *                   Enumerations
 ******************************************************/

typedef enum
{
    WICED_GPIO_1,
    WICED_GPIO_2,
    WICED_GPIO_3,
    WICED_GPIO_4,
    WICED_GPIO_5,
    WICED_GPIO_6,
    WICED_GPIO_7,
    WICED_GPIO_8,
    WICED_GPIO_9,
    WICED_GPIO_10,
    WICED_GPIO_11,
    WICED_GPIO_12,
    WICED_GPIO_13,
    WICED_GPIO_14,
    WICED_GPIO_15,
    WICED_GPIO_16,
    WICED_GPIO_17,
    WICED_GPIO_18,
    WICED_GPIO_19,
    WICED_GPIO_20,
    WICED_GPIO_21,
    WICED_GPIO_22,
    WICED_GPIO_23,
    WICED_GPIO_24,
    WICED_GPIO_25,
    WICED_GPIO_26,
    WICED_GPIO_27,
    WICED_GPIO_28,
    WICED_GPIO_29,
    WICED_GPIO_30,
    WICED_GPIO_31,
    WICED_GPIO_32,
    WICED_GPIO_33,
    WICED_GPIO_34,
    WICED_GPIO_35,
    WICED_GPIO_36,
    WICED_GPIO_37,
    WICED_GPIO_38,
    WICED_GPIO_39,
    WICED_GPIO_40,
    WICED_GPIO_41,
    WICED_GPIO_42,
    WICED_GPIO_43,
    WICED_GPIO_44,
    WICED_GPIO_45,
    WICED_GPIO_46,
    WICED_GPIO_47,
    WICED_GPIO_48,
    WICED_GPIO_49,
    WICED_GPIO_50,
    WICED_GPIO_51,
    WICED_GPIO_52,
    WICED_GPIO_53,
    WICED_GPIO_54,
    WICED_GPIO_55,
    WICED_GPIO_56,
    WICED_GPIO_57,
    WICED_GPIO_58,
    WICED_GPIO_59,
    WICED_GPIO_60,
    WICED_GPIO_61,
    WICED_GPIO_62,
    WICED_GPIO_63,
    WICED_GPIO_64,
    WICED_GPIO_65,
    WICED_GPIO_66,
    WICED_GPIO_67,
    WICED_GPIO_68,
    WICED_GPIO_69,
    WICED_GPIO_70,
    WICED_GPIO_71,
    WICED_GPIO_72,
    WICED_GPIO_73,
    WICED_GPIO_74,
    WICED_GPIO_75,
    WICED_GPIO_76,
    WICED_GPIO_77,
    WICED_GPIO_78,
    WICED_GPIO_79,
    WICED_GPIO_80,
    WICED_GPIO_81,
    WICED_GPIO_82,
    WICED_GPIO_83,
    WICED_GPIO_84,
    WICED_GPIO_85,
    WICED_GPIO_86,
    WICED_GPIO_87,
    WICED_GPIO_88,
    WICED_GPIO_89,
    WICED_GPIO_90,
    WICED_GPIO_91,
    WICED_GPIO_92,
    WICED_GPIO_93,
    WICED_GPIO_94,
    WICED_GPIO_95,
    WICED_GPIO_96,
    WICED_GPIO_97,
    WICED_GPIO_98,
    WICED_GPIO_99,
    WICED_GPIO_100,
    WICED_GPIO_MAX, /* Denotes the total number of GPIO port aliases. Not a valid GPIO alias */
    WICED_GPIO_32BIT = 0x7FFFFFFF,
} wiced_gpio_t;

typedef enum
{
    WICED_SPI_1,
    WICED_SPI_2,
    WICED_SPI_3,
    WICED_SPI_4,
    WICED_SPI_5,
    WICED_SPI_6,
    WICED_SPI_7,
    WICED_SPI_8,
    WICED_SPI_MAX, /* Denotes the total number of SPI port aliases. Not a valid SPI alias */
    WICED_SPI_32BIT = 0x7FFFFFFF,
} wiced_spi_t;

typedef enum
{
    WICED_I2C_1,
    WICED_I2C_2,
    WICED_I2C_3,
    WICED_I2C_4,
    WICED_I2C_5,
    WICED_I2C_6,
    WICED_I2C_7,
    WICED_I2C_8,
    WICED_I2C_MAX, /* Denotes the total number of I2C port aliases. Not a valid I2C alias */
    WICED_I2C_32BIT = 0x7FFFFFFF,
} wiced_i2c_t;

typedef enum
{
    WICED_I2S_1,
    WICED_I2S_2,
    WICED_I2S_MAX, /* Denotes the total number of I2S port aliases.  Not a valid I2S alias */
    WICED_I2S_32BIT = 0x7FFFFFFF
} wiced_i2s_t;

typedef enum
{
    WICED_PWM_1,
    WICED_PWM_2,
    WICED_PWM_3,
    WICED_PWM_4,
    WICED_PWM_5,
    WICED_PWM_6,
    WICED_PWM_7,
    WICED_PWM_8,
    WICED_PWM_9,
    WICED_PWM_10,
    WICED_PWM_11,
    WICED_PWM_12,
    WICED_PWM_13,
    WICED_PWM_14,
    WICED_PWM_15,
    WICED_PWM_16,
    WICED_PWM_17,
    WICED_PWM_18,
    WICED_PWM_19,
    WICED_PWM_20,
    WICED_PWM_21,
    WICED_PWM_22,
    WICED_PWM_23,
    WICED_PWM_24,
    WICED_PWM_25,
    WICED_PWM_26,
    WICED_PWM_27,
    WICED_PWM_28,
    WICED_PWM_29,
    WICED_PWM_30,
    WICED_PWM_31,
    WICED_PWM_32,
    WICED_PWM_MAX, /* Denotes the total number of PWM port aliases. Not a valid PWM alias */
    WICED_PWM_32BIT = 0x7FFFFFFF,
} wiced_pwm_t;

typedef enum
{
    WICED_ADC_1,
    WICED_ADC_2,
    WICED_ADC_3,
    WICED_ADC_4,
    WICED_ADC_5,
    WICED_ADC_6,
    WICED_ADC_7,
    WICED_ADC_8,
    WICED_ADC_9,
    WICED_ADC_10,
    WICED_ADC_11,
    WICED_ADC_12,
    WICED_ADC_13,
    WICED_ADC_14,
    WICED_ADC_15,
    WICED_ADC_16,
    WICED_ADC_MAX, /* Denotes the total number of ADC port aliases. Not a valid ADC alias */
    WICED_ADC_32BIT = 0x7FFFFFFF,
} wiced_adc_t;

typedef enum
{
    WICED_UART_1,
    WICED_UART_2,
    WICED_UART_3,
    WICED_UART_4,
    WICED_UART_5,
    WICED_UART_6,
    WICED_UART_7,
    WICED_UART_8,
    WICED_UART_MAX, /* Denotes the total number of UART port aliases. Not a valid UART alias */
    WICED_UART_32BIT = 0x7FFFFFFF,
} wiced_uart_t;

/* Logical Button-ids which map to physical buttons on the board */
typedef enum
{
    PLATFORM_BUTTON_1,   /* Default placeholder, to be defined per platform */
    PLATFORM_BUTTON_MAX, /* Denotes the total number of Buttons on the board. Not a valid Button Alias */
} platform_button_t;

/* Logical LED-ids which map to physical gpio LEDs on the board (see platform_gpio_leds[] in platform.c)*/
typedef enum
{
    PLATFORM_LED_1,   /* Red Led */
    PLATFORM_LED_2,   /* Green Led */
    PLATFORM_LED_3,   /* Blue Led */
    PLATFORM_LED_MAX, /* Denotes the total number of LEDs on the board. Not a valid alias */
} platform_led_t;

/******************************************************
 *                    Constants
 ******************************************************/

/* Define number of buttons present on the platform */
/* Default placeholder, to be defined per platform */
#define WICED_PLATFORM_BUTTON_COUNT  ( 1 )

/* Define UART port used for standard I/O */
/* Default placeholder, to be defined per platform */
#define STDIO_UART ( WICED_UART_6 )

/* Define if SPI flash is present on the platform */
/* Default placeholder, to be defined per platform */
/* #define WICED_PLATFORM_INCLUDES_SPI_FLASH */
#define WICED_SPI_FLASH_CS   (WICED_GPIO_NONE) /* No GPIO available, must use controller */

/* Components connected to external I/Os */
/* Default placeholder, to be defined per platform */
/* Platform has RGB LED shown as 3 LEDs below */
#define PLATFORM_LED_COUNT ( 3 )
#define WICED_LED1         ( WICED_GPIO_4 )
#define WICED_LED2         ( WICED_GPIO_8 )
#define WICED_LED3         ( WICED_GPIO_78 )
#define WICED_BUTTON1      ( WICED_GPIO_5 )

/* I/O connection <-> Peripheral Connections */
/* Default placeholder, to be defined per platform */
#define WICED_LED1_JOINS_PWM        ( WICED_PWM_1 )
#define WICED_THERMISTOR_JOINS_ADC  ( WICED_ADC_1 )

/* Common audio device defines */
#ifndef PLATFORM_AUDIO_CODEC_NONE
#define PLATFORM_DEFAULT_AUDIO_INPUT    AUDIO_DEVICE_ID_AK4954_ADC_LINE
#define PLATFORM_AUDIO_NUM_INPUTS       1
#define PLATFORM_DEFAULT_AUDIO_OUTPUT   AUDIO_DEVICE_ID_AK4954_DAC_LINE
#define PLATFORM_AUDIO_NUM_OUTPUTS      1
#else
#define PLATFORM_DEFAULT_AUDIO_INPUT    AUDIO_DEVICE_ID_NONE
#define PLATFORM_AUDIO_NUM_INPUTS       1
#define PLATFORM_DEFAULT_AUDIO_OUTPUT   AUDIO_DEVICE_ID_OUTPUT_NONE
#define PLATFORM_AUDIO_NUM_OUTPUTS      1
#endif

/* Bootloader OTA and OTA2 factory reset during settings */
/* Default placeholder, to be defined per platform */
#define PLATFORM_FACTORY_RESET_BUTTON_INDEX     ( PLATFORM_BUTTON_1 )
#define PLATFORM_FACTORY_RESET_TIMEOUT          ( 10000 )

/* Generic button checking defines */
/* Default placeholder, to be defined per platform */
#define PLATFORM_BUTTON_PRESS_CHECK_PERIOD      ( 100 )
#define PLATFORM_BUTTON_PRESSED_STATE           (   0 )

/* Default placeholder, to be defined per platform */
#define PLATFORM_RED_LED_INDEX                ( WICED_LED_INDEX_1 )
#define PLATFORM_GREEN_LED_INDEX              ( WICED_LED_INDEX_2 )
#define PLATFORM_BLUE_LED_INDEX               ( WICED_LED_INDEX_3 )

#ifdef __cplusplus
} /*extern "C" */
#endif
