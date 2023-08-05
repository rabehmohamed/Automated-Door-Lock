/* 
 * File:   hal_gpio.h
 * Author: Rabeh Mohamed
 *
 * Created on August 5, 2023, 2:16 AM
 */

#ifndef HAL_GPIO_H
#define	HAL_GPIO_H

/*----------INCLUDES--------------*/
#include "../pic18.h"
#include "hal_gpio_config.h"
#include "../device_config.h"
#include "../mcal_std_types.h"
/*----------MACRO DECLARTATIONS----------*/
#define BIT_MASK            (uint8)1
#define PORT_MASK           0xFF
#define PIN_MAX             8
#define PORT_MAX            8

#define GPIO_PIN_CONFIG     CONFIG_ENABLE
#define GPIO_PORT_CONFIG    CONFIG_ENABLE

/*----------MACRO FUNCTION DECLARTIONS-------------*/
#define HWREG8(_X)        (*((volatile uint8 *)(_X)))

#define SET_BIT(REG_ADDR , BIT_POSITION)          (REG_ADDR |=  (BIT_MASK << BIT_POSITION))
#define TOGGLE_BIT(REG_ADDR , BIT_POSITION)       (REG_ADDR ^= (BIT_MASK << BIT_POSITION))
#define CLEAR_BIT(REG_ADDR , BIT_POSITION)        (REG_ADDR &=  ~(BIT_MASK << BIT_POSITION))
#define READ_BIT(REG_ADDR , BIT_POSITION)         ((REG_ADDR >> BIT_POSITION) & BIT_MASK )

/*----------DATA TYPE DECLARTIONS------------------*/
typedef enum {
    GPIO_LOW = 0,
    GPIO_HIGH     
}logic_t;

typedef enum {
    GPIO_DIRECTION_OUTPUT = 0,
    GPIO_DIRECTION_INPUT     
}direction_t;

typedef enum {
    GPIO_PIN0 = 0 ,
    GPIO_PIN1,
    GPIO_PIN2,
    GPIO_PIN3,
    GPIO_PIN4,
    GPIO_PIN5,
    GPIO_PIN6,
    GPIO_PIN7,            
}pin_index_t;


typedef enum {
    PORTA_INDEX = 0 ,
    PORTB_INDEX,
    PORTC_INDEX,
    PORTD_INDEX,
    PORTE_INDEX
}port_index;

typedef struct {
    uint8 port : 3;          /*@ref port_index*/
    uint8 pin : 3;          /*@ref pin_index_t*/
    uint8 direction : 1;    /*@ref direction_t*/
    uint8 logic : 1;         /*@ref logic_t*/
}pin_config_t;


/*----------FUNCTION DECLARTIONS-------------------*/
std_ReturnType gpio_pin_direction_initialize(const pin_config_t * pin_config);
std_ReturnType gpio_pin_get_direction_status(const pin_config_t * pin_config , direction_t *direction_status);
std_ReturnType gpio_pin_write_logic(const pin_config_t * pin_config , logic_t logic);
std_ReturnType gpio_pin_read_logic(const pin_config_t * pin_config , logic_t *logic);
std_ReturnType gpio_pin_toggle_logic(const pin_config_t * pin_config);
std_ReturnType gpio_pin_initialize(const pin_config_t * pin_config);


std_ReturnType gpio_port_direction_initialize(port_index port , uint8 direction);
std_ReturnType gpio_port_get_direction_status(port_index port ,direction_t *direction_status );
std_ReturnType gpio_port_write_logic(port_index port , uint8 logic);
std_ReturnType gpio_port_read_logic(port_index port , logic_t *logic);
std_ReturnType gpio_port_toggle_logic(port_index port);




#endif	/* HAL_GPIO_H */

