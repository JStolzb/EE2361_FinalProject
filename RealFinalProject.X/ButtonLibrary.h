/* 
 * File:   ButtonLibrary.h
 * Author: jacks
 *
 * Created on April 22, 2022, 2:09 PM
 */

#ifndef BUTTONLIBRARY_H
#define	BUTTONLIBRARY_H

#ifdef	__cplusplus
extern "C" {
#endif

void init_button(void);
void __attribute__((__interrupt__,__auto_psv__)) _T2Interrupt(void);
void __attribute__((__interrupt__,__auto_psv__)) _T1Interrupt(void);
void __attribute__((__interrupt__,__auto_psv__)) _IC1Interrupt(void);


#ifdef	__cplusplus
}
#endif

#endif	/* BUTTONLIBRARY_H */

