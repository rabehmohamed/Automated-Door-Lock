/* 
 * File:   hal_gpio.c
 * Author: Rabeh Mohamed
 *
 * Created on August 5, 2023, 2:18 AM
 */


#include "hal_gpio.h"

volatile uint8 *tris_register[] = {&TRISA , &TRISB , &TRISC ,&TRISD ,&TRISE};
volatile uint8 *lat_register[] = {&LATA , &LATB , &LATC ,&LATD ,&LATE};
volatile uint8 *port_register[] = {&PORTA , &PORTB , &PORTC ,&PORTD ,&PORTE};

/**
 * 
 * @param pin_config
 * @return status of function
 *           E_OK : function done successfully
 *           E_NOT_OK : issue
 */
#if GPIO_PIN_CONFIG==CONFIG_ENABLE
std_ReturnType gpio_pin_direction_initialize(const pin_config_t *pin_config){
    std_ReturnType ret = E_OK;
    
    if(pin_config == NULL || pin_config->pin > PIN_MAX-1){
        ret = E_NOT_OK;
    }
    else {
        switch (pin_config->direction){
            case GPIO_DIRECTION_OUTPUT : 
                CLEAR_BIT(*tris_register[pin_config->port] , pin_config->pin);
                break;
            case GPIO_DIRECTION_INPUT: 
                SET_BIT(*tris_register[pin_config->port] , pin_config->pin);
                break;
            default : ret = E_NOT_OK;
        } 
    }
    return ret;
}
#endif

/**
 * 
 * @param pin_config
 * @param direction_status
 * @return status of function
 *           E_OK : function done successfully
 *           E_NOT_OK : issue
 */
#if GPIO_PIN_CONFIG==CONFIG_ENABLE
std_ReturnType gpio_pin_get_direction_status(const pin_config_t * pin_config , direction_t *direction_status){
    std_ReturnType ret = E_OK;
    if(pin_config == NULL || direction_status == NULL || pin_config->pin > PIN_MAX-1){
        ret = E_NOT_OK;
    }
    else {
        *direction_status = READ_BIT(*tris_register[pin_config->port] , pin_config->pin);
	}
    return ret;
    
}
#endif

/**
 * 
 * @param pin_config
 * @param logic
 * @return status of function
 *           E_OK : function done successfully
 *           E_NOT_OK : issue
 */
#if GPIO_PIN_CONFIG==CONFIG_ENABLE
std_ReturnType gpio_pin_write_logic(const pin_config_t * pin_config , logic_t logic){
    std_ReturnType ret = E_OK;
    if(pin_config == NULL || pin_config->pin > PIN_MAX-1){
        ret = E_NOT_OK;
    }
    else {
        switch(logic){
            case GPIO_LOW :
                CLEAR_BIT(*lat_register[pin_config->port] , pin_config->pin);
                break;
            case GPIO_HIGH :
                SET_BIT(*lat_register[pin_config->port] , pin_config->pin);
                break;
            default : ret = E_NOT_OK;
        }
	}
    return ret;
}
#endif
/**
 * 
 * @param pin_config
 * @param logic
 * @return status of function
 *           E_OK : function done successfully
 *           E_NOT_OK : issue
 */
#if GPIO_PIN_CONFIG==CONFIG_ENABLE
std_ReturnType gpio_pin_read_logic(const pin_config_t * pin_config , logic_t *logic){
    std_ReturnType ret = E_OK;
    if(pin_config == NULL || logic == NULL || pin_config->pin > PIN_MAX-1){
        ret = E_NOT_OK;
    }
    else {
        *logic = READ_BIT(*port_register[pin_config->port] , pin_config->pin);
	}
    return ret;
}
#endif

/**
 * 
 * @param pin_config
 * @return status of function
 *           E_OK : function done successfully
 *           E_NOT_OK : issue
 */
#if GPIO_PIN_CONFIG==CONFIG_ENABLE
std_ReturnType gpio_pin_initialize(const pin_config_t * pin_config){
    std_ReturnType ret = E_OK;
    if(pin_config == NULL || pin_config->pin > PIN_MAX-1){
        ret = E_NOT_OK;
    }
    else {
        gpio_pin_direction_initialize(pin_config);
        gpio_pin_write_logic(pin_config , pin_config->logic);
	}
    
    return ret;
}
#endif

/**
 * 
 * @param pin_config 
 * @return status of function
 *           E_OK : function done successfully
 *           E_NOT_OK : issue
 */
#if GPIO_PIN_CONFIG==CONFIG_ENABLE
std_ReturnType gpio_pin_toggle_logic(const pin_config_t * pin_config){
    std_ReturnType ret = E_OK;
    if(pin_config == NULL || pin_config->pin > PIN_MAX-1){
        ret = E_NOT_OK;
    }
    else {
        TOGGLE_BIT(*lat_register[pin_config->port] , pin_config->pin);
	}
    return ret;
}
#endif

/**
 * 
 * @param port
 * @param direction
 * @return status of function
 *           E_OK : function done successfully
 *           E_NOT_OK : issue
 */
#if GPIO_PIN_CONFIG==CONFIG_ENABLE
std_ReturnType gpio_port_direction_initialize(port_index port , uint8 direction){
    std_ReturnType ret = E_OK;
    if(port > PORT_MAX-1){
        ret = E_NOT_OK;
    }
    else {
        *tris_register[port] = direction;
    }
    return ret;
}
#endif

/**
 *  
 * @param port
 * @param direction_status
 * @return status of function
 *           E_OK : function done successfully
 *           E_NOT_OK : issue
 */
#if GPIO_PIN_CONFIG==CONFIG_ENABLE
std_ReturnType gpio_port_get_direction_status(port_index port ,direction_t *direction_status ){
    std_ReturnType ret = E_OK;
    if((port > PORT_MAX-1) && (direction_status == NULL) ){
        ret = E_NOT_OK;
    }
    else {
       *direction_status = *tris_register[port];
    }
    return ret;
}
#endif

/**
 * 
 * @param port
 * @param logic
 * @return status of function
 *           E_OK : function done successfully
 *           E_NOT_OK : issue
 */

#if GPIO_PIN_CONFIG==CONFIG_ENABLE
std_ReturnType gpio_port_write_logic(port_index port , uint8 logic){
    std_ReturnType ret = E_OK;
    if((port > PORT_MAX-1)){
        ret = E_NOT_OK;
    }
    else {
        *lat_register[port] = logic;
    }
    return ret;
}
#endif

/**
 * 
 * @param port
 * @param logic
 * @return status of function
 *           E_OK : function done successfully
 *           E_NOT_OK : issue
 */
#if GPIO_PIN_CONFIG==CONFIG_ENABLE
std_ReturnType gpio_port_read_logic(port_index port , logic_t *logic){
    std_ReturnType ret = E_OK;
    if((port > PORT_MAX-1) && (logic == NULL) ){
        ret = E_NOT_OK;
    }
    else {
        *logic = *lat_register[port];
    }
    return ret;
}
#endif

#if GPIO_PIN_CONFIG==CONFIG_ENABLE
std_ReturnType gpio_port_toggle_logic(port_index port){
    std_ReturnType ret = E_OK;
    if((port > PORT_MAX-1)){
        ret = E_NOT_OK;
    }
    else {
        *lat_register[port]^= PORT_MASK;
    }
    return ret;
}
#endif


