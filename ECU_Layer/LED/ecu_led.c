
/* 
 * File:   ecu_led.c
 * Author: Rabeh Mohamed
 *
 * Created on August 5, 2023, 6:36 AM
 */

#include "ecu_led.h"

/**
 * 
 * @param led
 * @return Status of function 
 *          (E_OK) : the function done successfully
 *          (E_NOT_OK) : issue
 */
std_ReturnType led_initialize(const led_t *led){
    std_ReturnType ret = E_OK;

    if(led == NULL){
        ret = E_NOT_OK;
    }
    else
    {
        pin_config_t led_pin = {
        .port = led->port ,
        .pin = led->pin ,
        .direction = GPIO_DIRECTION_OUTPUT ,
        .logic = led->led_status};
        gpio_pin_direction_initialize(&led_pin);
    }
    return ret;
}

/**
 * 
 * @param led
 * @return Status of function 
 *          (E_OK) : the function done successfully
 *          (E_NOT_OK) : issue
 */
std_ReturnType led_turn_on(const led_t *led){
    std_ReturnType ret = E_OK;
    if(led == NULL){
        ret = E_NOT_OK;
    }
    else
    {
       pin_config_t led_pin = {
        .port = led->port ,
        .pin = led->pin ,
        .direction = GPIO_DIRECTION_OUTPUT ,
        .logic = led->led_status};
       gpio_pin_write_logic (&led_pin , GPIO_HIGH);
    }
    return ret;
}

/**
 * 
 * @param led
 * @return Status of function 
 *          (E_OK) : the function done successfully
 *          (E_NOT_OK) : issue
 */
std_ReturnType led_turn_off(const led_t *led){
    std_ReturnType ret = E_OK;
    if(led == NULL){
        ret = E_NOT_OK;
    }
    else
    {
       pin_config_t led_pin = {
        .port = led->port ,
        .pin = led->pin ,
        .direction = GPIO_DIRECTION_OUTPUT ,
        .logic = led->led_status};
       gpio_pin_write_logic (&led_pin , GPIO_LOW);
    }
    return ret;
}

/**
 * 
 * @param led
 * @return Status of function 
 *          (E_OK) : the function done successfully
 *          (E_NOT_OK) : issue
 */
std_ReturnType led_toggle(const led_t *led){
    std_ReturnType ret = E_OK;
    if(led == NULL){
        ret = E_NOT_OK;
    }
    else
    {
       pin_config_t led_pin = {
        .port = led->port ,
        .pin = led->pin ,
        .direction = GPIO_DIRECTION_OUTPUT ,
        .logic = led->led_status};
       gpio_pin_toggle_logic (&led_pin);
    }
    return ret;
}