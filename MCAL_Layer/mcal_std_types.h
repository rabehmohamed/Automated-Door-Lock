/* 
 * File:   mcal_std_types.h
 * Author: Rabeh Mohamed
 *
 * Created on August 5, 2023, 2:08 AM
 */

#ifndef MCAL_STD_TYPES_H
#define	MCAL_STD_TYPES_H

/*----------INCLUDES--------------*/
#include "compiler.h"
#include <string.h>
#include <stdio.h>
/*----------DATA TYPE DECLARTIONS------------------*/
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef signed char sint8;
typedef signed short sint16;
typedef signed int sint32;

typedef uint8 std_ReturnType;


/*----------MACRO DECLARTATIONS----------*/
#define STD_HIGH       0x01
#define STD_LOW        0x00

#define STD_ON         0x01
#define STD_OFF        0x00

#define STD_ACTIVE     0x01
#define STD_DILE       0x00

#define E_NOT_OK      (std_ReturnType)0x00
#define E_OK          (std_ReturnType)0x01
#define _XTAL_FREQ 8000000UL



#endif	/* MCAL_STD_TYPES_H */

