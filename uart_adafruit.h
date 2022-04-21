/* 
 * File:   uart_adafruit.h
 * Author: devonuram
 *
 * Created on April 21, 2022, 1:11 PM
 */

#ifndef UART_ADAFRUIT_H
#define	UART_ADAFRUIT_H

#ifdef	__cplusplus
extern "C" {
#endif
    
void __attribute__((__interrupt__,__auto_psv__)) _U1TXInterrupt(void);
void delay_ms(unsigned int ms);
void init_UART(void);
void sendChar(char c);
void hello_world(void);

#ifdef	__cplusplus
}
#endif

#endif	/* UART_ADAFRUIT_H */

