/* 
 * File:   ecu_layer_initialize.c
 * Author: Rabeh Mohamed
 *
 * Created on August 5, 2023, 3:38 AM
 */

#include "ecu_layer_initialize.h"

lcd_4bit_t lcd = {
  .lcd_rs.port = PORTC_INDEX , 
  .lcd_rs.pin = GPIO_PIN0,
  .lcd_rs.logic = GPIO_LOW,
  .lcd_rs.direction = GPIO_DIRECTION_OUTPUT,
  
  .lcd_en.port = PORTC_INDEX , 
  .lcd_en.pin = GPIO_PIN1,
  .lcd_en.logic = GPIO_LOW,
  .lcd_en.direction = GPIO_DIRECTION_OUTPUT,
  
  .lcd_data[0].port = PORTC_INDEX,
  .lcd_data[0].pin = GPIO_PIN2 , 
  .lcd_data[0].direction = GPIO_DIRECTION_OUTPUT,
  .lcd_data[0].logic = GPIO_LOW,   
  .lcd_data[1].port = PORTC_INDEX,
  .lcd_data[1].pin = GPIO_PIN3 , 
  .lcd_data[1].direction = GPIO_DIRECTION_OUTPUT,
  .lcd_data[1].logic = GPIO_LOW,  
  .lcd_data[2].port = PORTC_INDEX,
  .lcd_data[2].pin = GPIO_PIN4 , 
  .lcd_data[2].direction = GPIO_DIRECTION_OUTPUT,
  .lcd_data[3].logic = GPIO_LOW, 
  .lcd_data[3].port = PORTC_INDEX,
  .lcd_data[3].pin = GPIO_PIN5 , 
  .lcd_data[3].direction = GPIO_DIRECTION_OUTPUT,
  .lcd_data[3].logic = GPIO_LOW,  
};

keypad_t keypad = {
    .keypad_rows_pins[0].port = PORTD_INDEX,
    .keypad_rows_pins[0].pin = GPIO_PIN0,
    .keypad_rows_pins[0].direction = GPIO_DIRECTION_OUTPUT ,
    .keypad_rows_pins[0].logic = GPIO_LOW,  
    .keypad_rows_pins[1].port = PORTD_INDEX,
    .keypad_rows_pins[1].pin = GPIO_PIN1,
    .keypad_rows_pins[1].direction = GPIO_DIRECTION_OUTPUT ,
    .keypad_rows_pins[1].logic = GPIO_LOW,    
    .keypad_rows_pins[2].port = PORTD_INDEX,
    .keypad_rows_pins[2].pin = GPIO_PIN2,
    .keypad_rows_pins[2].direction = GPIO_DIRECTION_OUTPUT ,
    .keypad_rows_pins[2].logic = GPIO_LOW,    
    .keypad_rows_pins[3].port = PORTD_INDEX,
    .keypad_rows_pins[3].pin = GPIO_PIN3,
    .keypad_rows_pins[3].direction = GPIO_DIRECTION_OUTPUT ,
    .keypad_rows_pins[3].logic = GPIO_LOW,
    
    .keypad_columns_pins[0].port = PORTD_INDEX,
    .keypad_columns_pins[0].pin = GPIO_PIN4,
    .keypad_columns_pins[0].direction = GPIO_DIRECTION_INPUT,
    .keypad_columns_pins[0].logic = GPIO_LOW,
    .keypad_columns_pins[1].port = PORTD_INDEX,
    .keypad_columns_pins[1].pin = GPIO_PIN5,
    .keypad_columns_pins[1].direction = GPIO_DIRECTION_INPUT,
    .keypad_columns_pins[1].logic = GPIO_LOW,           
    .keypad_columns_pins[2].port = PORTD_INDEX,
    .keypad_columns_pins[2].pin = GPIO_PIN6,
    .keypad_columns_pins[2].direction = GPIO_DIRECTION_INPUT,
    .keypad_columns_pins[2].logic = GPIO_LOW,

};

led_t led_green = {
  .port = PORTC_INDEX,
  .pin = GPIO_PIN6,
  .led_status = LED_OFF
};

led_t led_red = {
  .port = PORTC_INDEX,
  .pin = GPIO_PIN7,
  .led_status = LED_OFF
};

dc_motor_t motor = {
  .dc_motor[0].port = PORTA_INDEX,
  .dc_motor[0].pin = GPIO_PIN0,
  .dc_motor[0].direction = GPIO_DIRECTION_OUTPUT,
  .dc_motor[0].logic = GPIO_LOW,
  
  .dc_motor[1].port = PORTA_INDEX,
  .dc_motor[1].pin = GPIO_PIN1,
  .dc_motor[1].direction = GPIO_DIRECTION_OUTPUT,
  .dc_motor[1].logic = GPIO_LOW,
};
std_ReturnType ret = E_OK;
std_ReturnType ecu_layer_initialize(void){
   
    
    ret = lcd_4bit_initialize(&lcd);
    ret = keypad_initialize(&keypad);
    ret = dc_motor_initialize(&motor);
    ret = led_initialize(&led_green);
    ret = led_initialize(&led_red);
    
}
uint8 keypad_read_value(void)
{
    uint8 firstVal;
    
    ret = keypad_get_value(&keypad, &firstVal);
    __delay_ms(150);
    if('\0' == firstVal){
        return 0;
    }
    uint8 secondVal;
    ret = keypad_get_value(&keypad, &secondVal);
    
    if (firstVal == secondVal){
        return secondVal;
    }
    return 0;  
}