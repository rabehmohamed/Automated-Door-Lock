/* 
 * File:   ecu_keypad.h
 * Author: Rabeh Mohamed
 *
 * Created on August 5, 2023, 3:46 AM
 */

#ifndef ECU_KEYPAD_H
#define	ECU_KEYPAD_H

/*----------INCLUDES--------------*/
#include "../../MCAL_Layer/GPIO/hal_gpio.h"
/*----------MACRO DECLARTATIONS----------*/
#define ECU_KEYPAD_ROWS 4
#define ECU_KEYPAD_COLUMNS 3
/*---------Macro Functions Declarations-----------*/

/*--------Data type Declarations------------------*/
typedef struct{
    pin_config_t keypad_rows_pins[ECU_KEYPAD_ROWS];
    pin_config_t keypad_columns_pins[ECU_KEYPAD_COLUMNS];
}keypad_t;
/*--------Function Declarations*/
std_ReturnType keypad_initialize(const keypad_t * keypad);
std_ReturnType keypad_get_value(const keypad_t * keypad , uint8 * value);
std_ReturnType keypad_read_whole_value(const keypad_t * keypad , uint8 * value);

 
#endif	/* ECU_KEYPAD_H */

