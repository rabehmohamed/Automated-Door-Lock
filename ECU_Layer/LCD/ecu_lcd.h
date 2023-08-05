/* 
 * File:   ecu_lcd.h
 * Author: Rabeh Mohamed
 *
 * Created on August 5, 2023, 2:25 AM
 */

#ifndef ECU_LCD_H
#define	ECU_LCD_H


/*----------INCLUDES--------------*/
#include "ecu_lcd_config.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"

/*----------MACRO DECLARTATIONS----------*/
#define LCD_CLEAR_DISPLAY            0x01
#define LCD_CURSOR_HOME              0x02
#define LCD_ENTRY_MODE               0x06
#define LCD_CURSOR_OFF_DISPLAY_ON    0x0C
#define LCD_CURSOR_OFF_DISPLAY_OFF   0x08
#define LCD_CURSOR_ON_BLINK_ON       0x0F
#define LCD_CURSOR_ON_BLINK_OFF      0x0E
#define LCD_DISPLAY_SHIFT_RIGHT      0x1C
#define LCD_DISPLAY_SHIFT_LEFT       0x18
#define LCD_8BIT_MODE_2_LINE         0x38
#define LCD_4BIT_MODE_2_LINE         0x28
#define CGRAM_START                  0x40
#define DDRAM_START                  0x80

#define ROW1                         1
#define ROW2                         2
#define ROW3                         3
#define ROW4                         4
/*----------MACRO FUNCTION DECLARTIONS-------------*/

/*----------DATA TYPE DECLARTIONS------------------*/
typedef struct {
    pin_config_t lcd_rs;
    pin_config_t lcd_en;
    pin_config_t lcd_data[4];
}lcd_4bit_t;

/*----------FUNCTION DECLARTIONS------------------*/
std_ReturnType lcd_4bit_initialize(const lcd_4bit_t *lcd);
std_ReturnType lcd_4bit_send_command(const lcd_4bit_t *lcd , uint8 command);
std_ReturnType lcd_4bit_send_char_data(const lcd_4bit_t *lcd , uint8 data);
std_ReturnType lcd_4bit_send_data_pos(const lcd_4bit_t *lcd ,uint8 row , uint8 column, uint8 data);
std_ReturnType lcd_4bit_send_string(const lcd_4bit_t *lcd ,uint8 *str);
std_ReturnType lcd_4bit_send_string_pos(const lcd_4bit_t *lcd ,uint8 *str , uint8 row , uint8 column);
std_ReturnType lcd_4bit_send_cutsom_char(const lcd_4bit_t *lcd , const uint8 _chr[] , uint8 row , uint8 column , uint8 mem_pos);

std_ReturnType convert_uint8_to_string(uint8 value , uint8 *str);
std_ReturnType convert_uint16_to_string(uint16 value , uint8 *str);
std_ReturnType convert_uint32_to_string(uint32 value , uint8 *str);

#endif	/* ECU_LCD_H */

