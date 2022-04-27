
#include "xc.h"
#include "string.h"
#include "ButtonLibrary.h"

void init_button() {
    TRISBbits.TRISB8 = 1; //sets RB8 to input
    CNPU2bits.CN22PUE = 1; //pull up resitor
    //set up timer 2
    T2CON = 0x0000; //stop timer, clk source, prescaler
    TMR2 = 0;
    PR2 = 62500 - 1; //1s period
    T2CONbits.TCKPS = 0b11; //prescaler = 256
    //set timer 2 interrupt
    IFS0bits.T2IF = 0;
    IEC0bits.T2IE = 1; //turn interrupt on
    //IPC0bits.T1IP = 3;
    
    //setup Input compare
    __builtin_write_OSCCONL(OSCCON & 0xbf); // unlock PPS
    _IC1R = 8;   //IC! <- RB8; See Table 10-2 on P108 of the datasheet
    __builtin_write_OSCCONL(OSCCON | 0x40); // lock   PPS
    IC1CON = 0; // Turn off and reset internal state of IC1
    
    IC1CONbits.ICTMR = 1; // Use Timer 2 for capture source
    IC1CONbits.ICM = 0b001; // Turn on and capture every edge
    _IC1IF = 0;
    _IC1IE = 1;
    T2CONbits.TON = 1; //start timer 2
    //setup timer 4
    T1CON = 0;
    TMR1 = 0;
    PR1 = 31999; //2ms
    T1CONbits.TCKPS = 0b00;
    _T1IF = 0;
    _T1IE = 1;
    T1CONbits.TON = 0; //timer starts off
    
}

//global variables
unsigned long int overflow;
unsigned long int curPeriod, validClick, prevEdge;
int numClick, isValidClick;

void __attribute__((__interrupt__,__auto_psv__)) _T2Interrupt(void) {
    IFS0bits.T2IF = 0;
    overflow++;
}
void __attribute__((__interrupt__,__auto_psv__)) _T1Interrupt(void) {
    _T1IF = 0;
    T1CONbits.TON = 0;
    isValidClick = 1;
}
void __attribute__((__interrupt__,__auto_psv__)) _IC1Interrupt(void) {
    _IC1IF = 0;
    T1CONbits.TON = 0;
    TMR1 = 0;
    T1CONbits.TON = 1;
    isValidClick = 0;
}
