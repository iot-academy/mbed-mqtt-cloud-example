/* mbed Microcontroller Library
 *******************************************************************************
 * Copyright (c) 2018, STMicroelectronics
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. Neither the name of STMicroelectronics nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *******************************************************************************
 */

#ifndef MBED_PINNAMES_H
#define MBED_PINNAMES_H

#include "cmsis.h"
#include "PinNamesTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    ALT0  = 0x100,
    ALT1  = 0x200,
    ALT2  = 0x300,
    ALT3  = 0x400
} ALTx;

typedef enum {
    PA_0  = 0x00,
    PA_1  = 0x01,
    PA_1_ALT0 = PA_1 | ALT0,
    PA_1_ALT1 = PA_1 | ALT1,
    PA_2  = 0x02,
    PA_3  = 0x03,
    PA_4  = 0x04,
    PA_4_ALT0 = PA_4 | ALT0,
    PA_5  = 0x05,
    PA_6  = 0x06,
    PA_6_ALT0 = PA_6 | ALT0,
    PA_7  = 0x07,
    PA_7_ALT0 = PA_7 | ALT0,
    PA_7_ALT1 = PA_7 | ALT1,
    PA_7_ALT2 = PA_7 | ALT2,
    PA_8  = 0x08,
    PA_9  = 0x09,
    PA_10 = 0x0A,
    PA_11 = 0x0B,
    PA_12 = 0x0C,
    PA_13 = 0x0D,
    PA_14 = 0x0E,
    PA_15 = 0x0F,
    PA_15_ALT0 = PA_15 | ALT0,

    PB_0  = 0x10,
    PB_1  = 0x11,
    PB_2  = 0x12,
    PB_3  = 0x13,
    PB_3_ALT0 = PB_3 | ALT0,
    PB_4  = 0x14,
    PB_4_ALT0 = PB_4 | ALT0,
    PB_4_ALT1 = PB_4 | ALT1,
    PB_5  = 0x15,
    PB_5_ALT0 = PB_5 | ALT0,
    PB_5_ALT1 = PB_5 | ALT1,
    PB_6  = 0x16,
    PB_7  = 0x17,
    PB_8  = 0x18,
    PB_8_ALT0 = PB_8 | ALT0,
    PB_8_ALT1 = PB_8 | ALT1,
    PB_9  = 0x19,
    PB_9_ALT0 = PB_9 | ALT0,
    PB_9_ALT1 = PB_9 | ALT1,
    PB_10 = 0x1A,
    PB_11 = 0x1B,
    PB_12 = 0x1C,
    PB_13 = 0x1D,
    PB_14 = 0x1E,
    PB_15 = 0x1F,

    PC_0  = 0x20,
    PC_1  = 0x21,
    PC_2  = 0x22,
    PC_3  = 0x23,
    PC_4  = 0x24,
    PC_5  = 0x25,
    PC_6  = 0x26,
    PC_7  = 0x27,
    PC_8  = 0x28,
    PC_9  = 0x29,
    PC_10 = 0x2A,
    PC_10_ALT0 = PC_10 | ALT0,
    PC_11 = 0x2B,
    PC_11_ALT0 = PC_11 | ALT0,
    PC_12 = 0x2C,
    PC_13 = 0x2D,
    PC_14 = 0x2E,
    PC_15 = 0x2F,

    PD_2  = 0x32,

    PH_0  = 0x70,
    PH_1  = 0x71,

    // ADC internal channels
    ADC_TEMP = 0xF0,
    ADC_VREF = 0xF1,

    // STDIO for console print
#if defined(MBED_CONF_TARGET_STDIO_UART_TX)
#define CONSOLE_TX MBED_CONF_TARGET_STDIO_UART_TX
#else
#define CONSOLE_TX PA_9
#endif
#if defined(MBED_CONF_TARGET_STDIO_UART_RX)
#define CONSOLE_RX MBED_CONF_TARGET_STDIO_UART_RX
#else
#define CONSOLE_RX PA_10
#endif

    // Generic signals namings
    LED1        = PB_0,
    USER_BUTTON = PB_1,
    // Standardized button names
    BUTTON1     = USER_BUTTON,
    // Standardized serial interface
    SERIAL_TX   = CONSOLE_TX,
    SERIAL_RX   = CONSOLE_RX,
//    USBTX       = CONSOLE_TX,
//    USBRX       = CONSOLE_RX,
    // Standardized I2C interface
    I2C1_SCL    = PB_8,
    I2C1_SDA    = PB_9,
    I2C2_SCL    = PB_10,
    I2C2_SDA    = PB_11,
    I2C_SCL     = I2C2_SCL,
    I2C_SDA     = I2C2_SDA,
    // Standardized SPI interface
    SPI1_MOSI   = PA_7,
    SPI1_MISO   = PA_6,
    SPI1_SCK    = PA_5,
    SPI1_CS     = PA_4,
    SPI2_MOSI   = PB_15,
    SPI2_MISO   = PB_14,
    SPI2_SCK    = PB_13,
    SPI2_CS     = PB_12,
    SPI_MOSI    = SPI1_MOSI,
    SPI_MISO    = SPI1_MISO,
    SPI_SCK     = SPI1_SCK,
    SPI_CS      = SPI1_CS,

    PWM_OUT     = PA_5, // RIOT UNWD: PA_5, PA_1, PA_2, PA_3, PA_6, PA_7, PB_8, PB_9

    /**** OSCILLATOR pins ****/
    RCC_OSC32_IN  = PC_14,
    RCC_OSC32_OUT = PC_15,
    RCC_OSC_IN    = PH_0,
    RCC_OSC_OUT   = PH_1,

    /**** DEBUG pins ****/
    SYS_JTCK_SWCLK    = PA_14,
    SYS_JTDI          = PA_15,
    SYS_JTDO_TRACESWO = PB_3,
    SYS_JTMS_SWDIO    = PA_13,
    SYS_JTRST         = PB_4,
//  SYS_PVD_IN = PB_7,
//  SYS_V_REF_OUT = PB_0,
//  SYS_V_REF_OUT_ALT0 = PB_1,
//  SYS_WKUP1 = PA_0,
//  SYS_WKUP2 = PC_13,

    /** UNWD GPIO Ports */
    UNWD_GPIO_1 = PB_1,  // Safe button
    UNWD_GPIO_2 = PA_10, // STDIO_RX
    UNWD_GPIO_3 = PA_9,  // STDIO_TX
    UNWD_GPIO_4 = PA_4,  // (?) ADC ch. 4
    UNWD_GPIO_5 = PA_5,  // (?) ADC ch. 5, PWM ch. 0-3
    UNWD_GPIO_6 = PB_8,  // I2C SCL, PWM ch. 2-0
    UNWD_GPIO_7 = PB_9,  // I2C SDA, PWM ch. 2-1
    UNWD_GPIO_8 = PA_13, // JTAG TMS
    UNWD_GPIO_9 = PA_14, // JTAG TCK
    UNWD_GPIO_16 = PB_3, // JTAG JTDO
    UNWD_GPIO_17 = PA_15,// JTAG JTDI

    UNWD_GPIO_30 = PB_11,// I2C SDA
    UNWD_GPIO_29 = PB_10,// I2C SCL
    UNWD_GPIO_28 = PA_7, // (?) ADC ch. 7, PWM ch. 1-1
    UNWD_GPIO_27 = PA_6, // (?) ADC ch. 6, PWM ch. 1-0
    UNWD_GPIO_26 = PA_3, // UART RX, ADC ch. 3, PWM ch. 0-2
    UNWD_GPIO_25 = PA_2, // UART TX, ADC ch. 2, PWM ch. 0-1
    UNWD_GPIO_24 = PA_1, // (?) ADC ch. 1, PWM ch. 0-0

    /* LoRa */
    LORA_MOSI   = SPI2_MOSI,
    LORA_MISO   = SPI2_MISO,
    LORA_SCK    = SPI2_SCK,
    LORA_NSS    = SPI2_CS,
    LORA_RESET  = PA_8,
    LORA_DIO0   = PA_12,
    LORA_DIO1   = PC_13,
    LORA_DIO2   = PA_0,
    LORA_DIO3   = PB_6, /* CadDone */
    LORA_DIO4   = PB_7, /* CadDetect */
    ANT_SWITCH  = PA_11, /* LORA_RFSWITCH - RF on/off switching pin*/

    // Not connected
    NC = (int)0xFFFFFFFF
} PinName;

#ifdef __cplusplus
}
#endif

#endif
