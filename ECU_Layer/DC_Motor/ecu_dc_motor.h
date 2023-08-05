/* 
 * File:   ecu_dc_motor.h
 * Author: Rabeh Mohamed
 *
 * Created on August 5, 2023, 6:31 AM
 */

#ifndef ECU_DC_MOTOR_H
#define	ECU_DC_MOTOR_H

/*---------Includes-----------*/
#include "../../MCAL_Layer/GPIO/hal_gpio.h"
/*---------Macros Declarations----------*/
#define DC_MOTOR_ON_STATUS 0x01U
#define DC_MOTOR_OFF_STATUS 0x00U 
/*---------Macro Functions Declarations-----------*/

/*--------Data type Declarations------------------*/
typedef struct {
    pin_config_t dc_motor[2];
}dc_motor_t;
/*--------Function Declarations*/
std_ReturnType dc_motor_initialize(const dc_motor_t * motor);
std_ReturnType dc_motor_move_right(const dc_motor_t * motor);
std_ReturnType dc_motor_move_left(const dc_motor_t * motor);
std_ReturnType dc_motor_stop(const dc_motor_t * motor);


#endif	/* ECU_DC_MOTOR_H */

