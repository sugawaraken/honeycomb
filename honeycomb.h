/************************************************************************/
/* honeycomb                                                            */
/*                                                                      */
/* honeycomb.h                                                          */
/*                                                                      */
/* Nicholas Dale Farrow                                                 */
/*                                                                      */
/* Copyright (c) 2012 Nicholas Dale Farrow                              */
/*                                                                      */
/* Permission is hereby granted, free of charge, to any person          */
/* obtaining a copy of this software and associated documentation       */
/* files(the "Software"), to deal in the Software without restriction,  */
/* including without limitation the rights to use, copy, modify, merge, */
/* publish, distribute, sublicense, and/or sell copies of the Software, */
/* and to permit persons to whom the Software is furnished to do so,    */
/* subject to the following conditions:                                 */
/*                                                                      */
/* The above copyright notice and this permission notice shall be       */
/* included in all copies or substantial portions of the Software.      */
/*                                                                      */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,      */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF   */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND                */
/* NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  */
/* BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN   */
/* ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN    */
/* CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE     */
/* SOFTWARE.                                                            */
/*                                                                      */
/************************************************************************/

#ifndef __HONEYCOMB_H
#define __HONEYCOMB_H

#include <math.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include <stdio.h>

#include "board.h"
#include "usart.h"
#include "spi.h"
#include "i2c.h"
#include "eeprom.h"
#include "xgrid.h"
#include "servo.h"

#include "../xboot/xbootapi.h"

// Build information
extern char   __BUILD_DATE;
extern char   __BUILD_NUMBER;


// defines
#define prt_flt3(f)	(int16_t)f,(int16_t)((fabs(f)-(int16_t)(fabs(f)))*1000)			// use %i.%i inside print_f in place of %f

// typedefs

// Prototypes
void init(void);
int main(void);
uint8_t SP_ReadCalibrationByte( uint8_t index );
uint8_t SP_ReadUserSigRow( uint8_t index );

// for the user
unsigned long getJiffies();
void xgrid_send_packet(Xgrid::Packet *pkt_ptr);
void usart_stream_fprintf_P(const char *fmt, ...);

// user prototypes (user.cpp)
void setup();
void loop();
void rx_pkt(Xgrid::Packet *pkt);
void keyPressed(char key);

#ifndef ADCACAL0_offset

#define ADCACAL0_offset 0x20
#define ADCACAL1_offset 0x21
#define ADCBCAL0_offset 0x24
#define ADCBCAL1_offset 0x25

#endif

#endif // __HONEYCOMB_H



