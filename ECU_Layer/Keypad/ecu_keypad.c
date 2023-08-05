/* 
 * File:   ecu_keypad.c
 * Author: Rabeh Mohamed
 *
 * Created on August 5, 2023, 3:49 AM
 */

#include "ecu_keypad.h"

static const uint8 btn_values [ECU_KEYPAD_ROWS][ECU_KEYPAD_COLUMNS] = {
    {'1' , '2' , '3' },
    {'4' , '5' , '6' },
    {'7' , '8' , '9' },
    {'*' , '0' , '#' },
};

/**
 * 
 * @param pointer to keypad struct 
 * @return status of function 
 *              E_OK : function done successfully
 *              E_NOT_OK : function has issue 
 */
std_ReturnType keypad_initialize(const keypad_t * keypad){
    std_ReturnType ret = E_OK;
    if(keypad == NULL){
        ret = E_NOT_OK;
    }
    else {
        for(uint8 row_counter = 0 ; row_counter < ECU_KEYPAD_ROWS ; row_counter++){
            ret = gpio_pin_initialize(&(keypad->keypad_rows_pins[row_counter]));      
        }
        for(uint8 col_counter = 0 ; col_counter < ECU_KEYPAD_COLUMNS ; col_counter++){
            ret = gpio_pin_direction_initialize(&(keypad->keypad_columns_pins[col_counter]));      
        }   
    }
    return ret;
}

/**
 * 
 * @param keypad
 * @param value
 * @return status of function 
 *              E_OK : function done successfully
 *              E_NOT_OK : function has issue 
 */
std_ReturnType keypad_get_value(const keypad_t * keypad , uint8 * value){
    std_ReturnType ret = E_OK;
    uint8 col_logic = 0;
    if((keypad == NULL) || (value == NULL)){
        ret = E_NOT_OK;
    }
    else {
        for(uint8 row_counter=0; row_counter < ECU_KEYPAD_ROWS ; row_counter++){
            for(uint8 row_counter2 = 0; row_counter2 < ECU_KEYPAD_ROWS ; row_counter2++){
                ret = gpio_pin_write_logic(&(keypad->keypad_rows_pins[row_counter2]) , GPIO_LOW );
            }
            gpio_pin_write_logic(&(keypad->keypad_rows_pins[row_counter]) , GPIO_HIGH);     
            for(uint8 col_counter = 0 ; col_counter < ECU_KEYPAD_COLUMNS ; col_counter++){
                 ret = gpio_pin_read_logic(&(keypad->keypad_columns_pins[col_counter]),&col_logic);
                 if(col_logic == GPIO_HIGH){
                     *value = btn_values[row_counter][col_counter];
                 }
            }     
        }
    }
    return ret;
}
