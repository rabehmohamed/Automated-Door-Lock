/* 
 * File:   ecu_dc_motor.c
 * Author: Rabeh Mohamed
 *
 * Created on August 5, 2023, 6:33 AM
 */
#include "ecu_dc_motor.h"


/**
 * 
 * @param motor
 * @return 
 */
std_ReturnType dc_motor_initialize(const dc_motor_t * motor){
    std_ReturnType ret = E_OK;
    if(motor == NULL){
        ret = E_NOT_OK;
    }
    else{
        gpio_pin_initialize(&(motor->dc_motor[0]));
        gpio_pin_initialize(&(motor->dc_motor[1]));
        ret = E_OK;
    }
    return ret;
};
/**
 * 
 * @param motor
 * @return 
 */
std_ReturnType dc_motor_move_right(const dc_motor_t * motor){
    std_ReturnType ret = E_OK;
    if(motor == NULL){
        ret = E_NOT_OK;
    } 
    else {
         gpio_pin_write_logic(&(motor->dc_motor[0]) , GPIO_HIGH);
         gpio_pin_write_logic(&(motor->dc_motor[1]) , GPIO_LOW);
         ret = E_OK;
    }
    return ret;
}
/**
 * 
 * @param motor
 * @return 
 */
std_ReturnType dc_motor_move_left(const dc_motor_t * motor){
     std_ReturnType ret = E_OK;
    if(motor == NULL){
        ret = E_NOT_OK;
    } 
    else {
        gpio_pin_write_logic(&(motor->dc_motor[0]) , GPIO_LOW);
        gpio_pin_write_logic(&(motor->dc_motor[1]) , GPIO_HIGH);
        ret = E_OK;
    }
    return ret;
}
/**
 * 
 * @param motor
 * @return 
 */
std_ReturnType dc_motor_stop(const dc_motor_t * motor){
     std_ReturnType ret = E_OK;
    if(motor == NULL){
        ret = E_NOT_OK;
    } 
    else {
        gpio_pin_write_logic(&(motor->dc_motor[0]) , GPIO_LOW);;
        gpio_pin_write_logic(&(motor->dc_motor[1]) , GPIO_LOW);
        ret = E_OK;
    }
    return ret;
}