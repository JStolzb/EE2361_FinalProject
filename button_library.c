

#include "xc.h"
#include "string.h"
#include "button_library.h"

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
//int main(void) {
//    unsigned long int tempPeriod, curEdge = 0;
//    int numClick = 0, isFirstEdge = 1;
//    setup();
//    init_servo();
//    init_button();
//    //2000 (cycles/ms)*1.5 (ms) - 1 = 2999
//    //set_servo(2999); // 1.5ms set to middle
//    //delay_ms(2000);
//    while(1) {
//        if (isValidClick == 1) {
//            isValidClick = 0;
//            curEdge = (unsigned long int) (PR2 + 1 )*overflow + TMR2;
//            curPeriod = curEdge - validClick; //update global var if greater than 2ms
//            validClick = curEdge;
//            numClick++;
//            if (isFirstEdge == 1) {
//                isFirstEdge = 0;
//            }
//            else {
//                if (curPeriod < 11000) { //if less than .25s
//                    if (numClick == 5){
//                        set_servo(3599);  //1.8ms 
//                        numClick = 0;
//                        
//                    }   
//                }
//                else {
//                    numClick = 0;
//                }
//            }
//        }
//        if ((unsigned long int)(PR2 + 1) * overflow + TMR2 - validClick > 125000 ) {
//            set_servo(2999); // 1.5ms set to middle
//            overflow = 0;
//            TMR2 = 0;
//            validClick = TMR2;
//            prevEdge = TMR2;
//            numClick = 0;
//            isValidClick = 0;
//            isFirstEdge = 1;
//        }
//    }
//    return 0;
//}
