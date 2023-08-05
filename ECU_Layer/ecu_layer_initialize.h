/* 
 * File:   ecu_layer_initialize.h
 * Author: Rabeh Mohamed
 *
 * Created on August 5, 2023, 3:37 AM
 */

#ifndef ECU_LAYER_INITIALIZE_H
#define	ECU_LAYER_INITIALIZE_H


/*----------INCLUDES--------------*/
#include "../MCAL_Layer/GPIO/hal_gpio.h"
#include "LCD/ecu_lcd.h"
#include "Keypad/ecu_keypad.h"
#include "DC_Motor/ecu_dc_motor.h"
#include "LED/ecu_led.h"
/*----------DATA TYPE DECLARTIONS------------------*/
extern lcd_4bit_t lcd;
extern keypad_t keypad;
extern led_t led_green;
extern led_t led_red;
extern dc_motor_t motor;
/*----------FUNCTION DECLARTIONS------------------*/
std_ReturnType ecu_layer_initialize(void);
uint8 keypad_read_value(void);
#endif	/* ECU_LAYER_INITIALIZE_H */

