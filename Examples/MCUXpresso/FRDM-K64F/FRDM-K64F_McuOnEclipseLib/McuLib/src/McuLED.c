/*
 * led.c
 *
 */
#include "McuLibconfig.h"
#include "McuLED.h"
#include "McuGPIO.h"
#include "fsl_gpio.h"
#if McuLib_CONFIG_CPU_IS_KINETIS
  #include "fsl_port.h"
#endif
#include <stddef.h>
#include <string.h> /* for memset */
#include <assert.h>
#include <McuLEDconfig.h>

/* default configuration, used for initializing the config */
static const McuLED_Config_t defaultConfig =
{
    .isLowActive = false,
    .isOnInit = false,
    .gpio = NULL,
#if McuLib_CONFIG_CPU_IS_KINETIS
    .port = NULL,
#elif McuLib_CONFIG_CPU_IS_LPC
    .port = 0,
#endif
    .pin = 0,
};

typedef struct {
  McuGPIO_Handle_t gpio;
  bool isLowActive;
} McuLED_t;

void McuLED_GetDefaultConfig(McuLED_Config_t *config) {
  assert(config!=NULL);
  memcpy(config, &defaultConfig, sizeof(*config));
}

McuLED_Handle_t McuLED_InitLed(McuLED_Config_t *config) {
  McuGPIO_Config_t gpio_config; /* config for the SDK */
  McuGPIO_Handle_t gpio;
  McuLED_t *handle;

  assert(config!=NULL);
  McuGPIO_GetDefaultConfig(&gpio_config);
  gpio_config.isInput = false; /* LED is output only */
  gpio_config.gpio = config->gpio;
  gpio_config.port = config->port;
  gpio_config.pin = config->pin;
  if (config->isLowActive) {
    gpio_config.isLowOnInit = config->isOnInit;
  } else {
    gpio_config.isLowOnInit = !config->isOnInit;
  }
  gpio = McuGPIO_InitGPIO(&gpio_config); /* create gpio handle */
  handle = (McuLED_t*)malloc(sizeof(McuLED_t)); /* get a new device descriptor */
  assert(handle!=NULL);
  if (handle!=NULL) { /* if malloc failed, will return NULL pointer */
    memset(handle, 0, sizeof(McuLED_t)); /* init all fields */
    handle->gpio = gpio;
    handle->isLowActive = config->isLowActive;
  }
	return handle;
}

McuLED_Handle_t McuLED_DeinitLed(McuLED_Handle_t led) {
  assert(led!=NULL);
  McuGPIO_DeinitGPIO(((McuLED_t*)led)->gpio);
  free(led);
  return NULL;
}

void McuLED_On(McuLED_Handle_t led) {
  assert(led!=NULL);
  McuLED_t *desc = (McuLED_t*)led;

  if (desc->isLowActive) {
    McuGPIO_Low(desc->gpio);
  } else {
    McuGPIO_High(desc->gpio);
  }
}

void McuLED_Off(McuLED_Handle_t led) {
  assert(led!=NULL);
  McuLED_t *desc = (McuLED_t*)led;

  if (desc->isLowActive) {
    McuGPIO_High(desc->gpio);
  } else {
    McuGPIO_Low(desc->gpio);
  }
}

void McuLED_Neg(McuLED_Handle_t led) {
  assert(led!=NULL);
  McuLED_t *desc = (McuLED_t*)led;

  McuGPIO_Neg(desc->gpio);
}

bool McuLED_Get(McuLED_Handle_t led) {
  assert(led!=NULL);
  McuLED_t *desc = (McuLED_t*)led;

  if (desc->isLowActive) {
    return McuGPIO_Get(desc->gpio)==false;
  } else {
    return McuGPIO_Get(desc->gpio)!=false;
 }
}

void McuLED_Set(McuLED_Handle_t led, bool isOn) {
  if (isOn) {
    McuLED_On(led);
  } else {
    McuLED_Off(led);
  }
}

void McuLED_Init(void) {
  /* nothing to do */
}

void McuLED_Deinit(void) {
  /* nothing to do */
}
