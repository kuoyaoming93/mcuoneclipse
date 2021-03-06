/*
 * IncludeMcuLibConfig.h
 *
 *  Created on: 17.02.2019
 *      Author: Erich Styger
 */

/* header file is included with -include compiler option */

#ifndef INCLUDEMCULIBCONFIG_H_
#define INCLUDEMCULIBCONFIG_H_

#define TINYK22_HAT_VERSION  (3)  /* 3 or 4 */

#define McuLib_CONFIG_SDK_VERSION_USED  McuLib_CONFIG_SDK_MCUXPRESSO_2_0

/* ------------------- RTOS ---------------------------*/
/* Note: set configTOTAL_HEAP_SIZE to 16k in FreeRTOSConfig.h */
#define configTOTAL_HEAP_SIZE   (16*1024)
#define McuLib_CONFIG_SDK_USE_FREERTOS       (1)
#define configUSE_SEGGER_SYSTEM_VIEWER_HOOKS (1)

/* ------------------- I2C ---------------------------*/
#define McuGenericI2C_CONFIG_USE_ON_ERROR_EVENT (0)
#define McuGenericI2C_CONFIG_USE_MUTEX          (1 && McuLib_CONFIG_SDK_USE_FREERTOS)

#define McuGenericSWI2C_CONFIG_DO_YIELD (0 && McuLib_CONFIG_SDK_USE_FREERTOS) /* because of Yield in GenericSWI2C */
#define McuGenericSWI2C_CONFIG_DELAY_NS (0)
/* I2C Pin Muxing */
#define SDA1_CONFIG_DO_PIN_MUXING (1)
#define SCL1_CONFIG_DO_PIN_MUXING (1)

/* --------------------  HAT Differences -------------*/
#if TINYK22_HAT_VERSION==3
  /*
   * HAT V3:
   *
   * I2C SCL: PTA12
   * I2C SDA: PTA13
   *
   * up:    PTB0
   * down:  PTB1
   * left:  PTB3
   * right: PTB2
   * push:  PTB16
   */
  #define SCL1_CONFIG_GPIO_NAME     GPIOA
  #define SCL1_CONFIG_PORT_NAME     PORTA
  #define SCL1_CONFIG_PIN_NUMBER    12u

  #define SDA1_CONFIG_GPIO_NAME     GPIOA
  #define SDA1_CONFIG_PORT_NAME     PORTA
  #define SDA1_CONFIG_PIN_NUMBER    13u

  #define PINS_HATNAVUP_GPIO      GPIOB
  #define PINS_HATNAVUP_PORT      PORTB
  #define PINS_HATNAVUP_PIN       0u

  #define PINS_HATNAVDOWN_GPIO    GPIOB
  #define PINS_HATNAVDOWN_PORT    PORTB
  #define PINS_HATNAVDOWN_PIN     1u

  #define PINS_HATNAVLEFT_GPIO    GPIOB
  #define PINS_HATNAVLEFT_PORT    PORTB
  #define PINS_HATNAVLEFT_PIN     3u

  #define PINS_HATNAVRIGHT_GPIO   GPIOB
  #define PINS_HATNAVRIGHT_PORT   PORTB
  #define PINS_HATNAVRIGHT_PIN    2u

  #define PINS_HATNAVPUSH_GPIO    GPIOB
  #define PINS_HATNAVPUSH_PORT    PORTB
  #define PINS_HATNAVPUSH_PIN     16u
#elif TINYK22_HAT_VERSION==4
  /*
   * HAT V4:
   *
   * I2C SCL: PTB0
   * I2C SDA: PTB1
   *
   * up:    PTB3
   * down:  PTB2
   * left:  PTA13
   * right: PTA12
   * push:  PTB16
   */
  #define SCL1_CONFIG_GPIO_NAME     GPIOB
  #define SCL1_CONFIG_PORT_NAME     PORTB
  #define SCL1_CONFIG_PIN_NUMBER    0u

  #define SDA1_CONFIG_GPIO_NAME     GPIOB
  #define SDA1_CONFIG_PORT_NAME     PORTB
  #define SDA1_CONFIG_PIN_NUMBER    1u

  #define PINS_HATNAVUP_GPIO      GPIOB
  #define PINS_HATNAVUP_PORT      PORTB
  #define PINS_HATNAVUP_PIN       3u

  #define PINS_HATNAVDOWN_GPIO    GPIOB
  #define PINS_HATNAVDOWN_PORT    PORTB
  #define PINS_HATNAVDOWN_PIN     2u

  #define PINS_HATNAVLEFT_GPIO    GPIOA
  #define PINS_HATNAVLEFT_PORT    PORTA
  #define PINS_HATNAVLEFT_PIN     13u

  #define PINS_HATNAVRIGHT_GPIO   GPIOA
  #define PINS_HATNAVRIGHT_PORT   PORTA
  #define PINS_HATNAVRIGHT_PIN    12u

  #define PINS_HATNAVPUSH_GPIO    GPIOB
  #define PINS_HATNAVPUSH_PORT    PORTB
  #define PINS_HATNAVPUSH_PIN     16u
#else
  #error "unknown configuration"
#endif
/* -------------------------------------------------*/
/* tinyK22 blue: PTC2
 * HAT LED blue: PTC8
 * HAT LED green: PTC9
 * HAT LED yellow: PTC10
 * HAT LED red: PTC11
 */
#define PINS_LEDBLUE_GPIO       GPIOC
#define PINS_LEDBLUE_PORT       PORTC
#define PINS_LEDBLUE_PIN        2U

#define PINS_HATLEDBLUE_GPIO    GPIOC
#define PINS_HATLEDBLUE_PORT    PORTC
#define PINS_HATLEDBLUE_PIN     8U

#define PINS_HATLEDGREEN_GPIO   GPIOC
#define PINS_HATLEDGREEN_PORT   PORTC
#define PINS_HATLEDGREEN_PIN    9U

#define PINS_HATLEDYELLOW_GPIO  GPIOC
#define PINS_HATLEDYELLOW_PORT  PORTC
#define PINS_HATLEDYELLOW_PIN   10U

#define PINS_HATLEDRED_GPIO     GPIOC
#define PINS_HATLEDRED_PORT     PORTC
#define PINS_HATLEDRED_PIN      11U

#define PINS_ALERT_GPIO     GPIOD
#define PINS_ALERT_PORT     PORTD
#define PINS_ALERT_PIN      3U
/* -------------------------------------------------*/
/* SHT pin, used for Raspy Powerdown */
#define PINS_ALERT_GPIO     GPIOD
#define PINS_ALERT_PORT     PORTD
#define PINS_ALERT_PIN      3U
/* -------------------------------------------------*/
/* LPUART to OpenSDA */
#define PINS_LPUART0_RX_PORT PORTC
#define PINS_LPUART0_RX_PIN  3U

#define PINS_LPUART0_TX_PORT PORTC
#define PINS_LPUART0_TX_PIN  4U
/* -------------------------------------------------*/
#if 1 /* type of OLED */
  #define McuSSD1306_CONFIG_SSD1306_DRIVER_TYPE  (1106)
#else
  #define McuSSD1306_CONFIG_SSD1306_DRIVER_TYPE  (1306)
#endif
//#define McuSSD1306_CONFIG_SSD1306_START_COLUMN_OFFSET (0) /* needed for 1.3" Banggood display */
#define McuSSD1306_CONFIG_SSD1306_I2C_DELAY_US   (0)
/* -------------------------------------------------*/
/* Shell */
#define McuShell_CONFIG_PROJECT_NAME_STRING "Raspberry Pi UPS and Gateway"

#define LV_CONFIG_DISPLAY_WIDTH        (128)
#define LV_CONFIG_DISPLAY_HEIGHT       (64)
#define LV_CONFIG_COLOR_DEPTH          (1)
#define LV_CONFIG_DPI                  (25)


#endif /* INCLUDEMCULIBCONFIG_H_ */

