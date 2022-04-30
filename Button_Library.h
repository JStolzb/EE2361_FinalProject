/* 
 * File:   Button_Library.h
 * Author: johns
 *
 * Created on April 30, 2022, 1:32 PM
 */

#ifndef BUTTON_LIBRARY_H
#define	BUTTON_LIBRARY_H

#ifdef	__cplusplus
extern "C" {
#endif

void initPushButton(void);
void __attribute__((interrupt, auto_psv)) _IC1Interrupt(void);
void __attribute__((interrupt, auto_psv)) _IC2Interrupt(void);
void __attribute__((interrupt, auto_psv)) _T2Interrupt(void);
void buttonWatch(void);



#ifdef	__cplusplus
}
#endif

#endif	/* BUTTON_LIBRARY_H */

