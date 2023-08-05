/* 
 * File:   application.c
 * Author: Rabeh Mohamed
 *
 * Created on August 5, 2023, 2:14 AM
 */

#include "application.h"



std_ReturnType ret = E_OK;
std_ReturnType clicked = E_NOT_OK;
void app_intialize(void);
uint8 keypad_read_value(void);
uint32 password = 1234;
uint32 enteredPassword = 0;
uint8 presses=0;
uint8 enterValue=0;
uint8 index = 1;

int main(){
    app_intialize();
    
    
    __delay_ms(250);
    ret = lcd_4bit_send_string_pos(&lcd , "Enter Your Password" , 2 , 1);
    __delay_ms(400);
    ret = lcd_4bit_send_command(&lcd,LCD_CLEAR_DISPLAY);
    
    while(1){
        enterValue = keypad_read_value();
        if(presses == 4){
            presses = 0 ;
            if(password == enteredPassword){
                ret = lcd_4bit_send_command(&lcd,LCD_CLEAR_DISPLAY);
                ret = lcd_4bit_send_string(&lcd , "Correct Password");
                 __delay_ms(400);
                ret = lcd_4bit_send_command(&lcd,LCD_CLEAR_DISPLAY);
                ret = lcd_4bit_send_string(&lcd , "Access Granted!");
                 __delay_ms(400);
                ret = lcd_4bit_send_command(&lcd,LCD_CLEAR_DISPLAY);
                ret = lcd_4bit_send_string(&lcd , "Welcome Home ");
                ret = led_turn_on(&led_green);
                ret = dc_motor_move_right(&motor);
            }
            else {
                ret = lcd_4bit_send_command(&lcd,LCD_CLEAR_DISPLAY);
                ret = lcd_4bit_send_string(&lcd , "Incorrect Password");
                 __delay_ms(400);
                ret = lcd_4bit_send_command(&lcd,LCD_CLEAR_DISPLAY);
                ret = lcd_4bit_send_string(&lcd , "Access Granted!");
                ret = led_turn_on(&led_red);
            }
        }
        if(enterValue >= '0' && enterValue <= '9' && enterValue != '#'){
           presses++;
           enteredPassword = (enteredPassword * 10) + (enterValue - '0');
           ret = lcd_4bit_send_data_pos(&lcd , 1 , index , enterValue);
           __delay_ms(200);   
           ret = lcd_4bit_send_data_pos(&lcd , 1 , index , '*');
           index++;
        }       
    }
   
        return 0;
        
    }
       

void app_intialize(void){
    ret = ecu_layer_initialize();
}
