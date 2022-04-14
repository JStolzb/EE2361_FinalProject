/* 
 * File:   button_library.h
 * Author: megad
 *
 * Created on April 14, 2022, 1:45 PM
 */

#ifndef BUTTON_LIBRARY_H
#define	BUTTON_LIBRARY_H

#ifdef	__cplusplus
extern "C" {
#endif

void init_button(void);

void __attribute__((__interrupt__,__auto_psv__)) _T2Interrupt(void);

void __attribute__((__interrupt__,__auto_psv__)) _T1Interrupt(void);

void __attribute__((__interrupt__,__auto_psv__)) _IC1Interrupt(void);

//volatile unsigned long int overflow;
//volatile unsigned long int curPeriod;
//volatile unsigned long int validClick;
//volatile unsigned long int prevEdge;
//volatile int numClicks;
//volatile int isValidClick;

#ifdef	__cplusplus
}
#endif

#endif	/* BUTTON_LIBRARY_H */

