/*
 * File:   main.c
 * Author: megad
 *
 * Created on April 14, 2022, 1:49 PM
 */
#include "xc.h"
#include "string.h"
#include "button_library.h"
#include "lcd_library.h"
#include "string.h"

// CW1: FLASH CONFIGURATION WORD 1 (see PIC24 Family Reference Manual 24.1)
#pragma config ICS = PGx1          // Comm Channel Select (Emulator EMUC1/EMUD1 pins are shared with PGC1/PGD1)
#pragma config FWDTEN = OFF        // Watchdog Timer Enable (Watchdog Timer is disabled)
#pragma config GWRP = OFF          // General Code Segment Write Protect (Writes to program memory are allowed)
#pragma config GCP = OFF           // General Code Segment Code Protect (Code protection is disabled)
#pragma config JTAGEN = OFF        // JTAG Port Enable (JTAG port is disabled)


// CW2: FLASH CONFIGURATION WORD 2 (see PIC24 Family Reference Manual 24.1)
#pragma config I2C1SEL = PRI       // I2C1 Pin Location Select (Use default SCL1/SDA1 pins)
#pragma config IOL1WAY = OFF       // IOLOCK Protection (IOLOCK may be changed via unlocking seq)
#pragma config OSCIOFNC = ON       // Primary Oscillator I/O Function (CLKO/RC15 functions as I/O pin)
#pragma config FCKSM = CSECME      // Clock Switching and Monitor (Clock switching is enabled, 
                                       // Fail-Safe Clock Monitor is enabled)
#pragma config FNOSC = FRCPLL      // Oscillator Select (Fast RC Oscillator with PLL module (FRCPLL))

extern unsigned long int overflow;
extern unsigned long int curPeriod, validClick, prevEdge;
extern int numClick, isValidClick;




int main(void) {
    pic24Init();
    init_button();
    lcd_init();
    int isFirstEdge = 1;
    overflow = 0;
    curPeriod = 0;
    validClick = 0;
    prevEdge = 0;
    numClick = 0;
    isValidClick = 0;
    unsigned long int tempPeriod = 0, curEdge = 0;
    
    char letter[6];
    int i = 0;
    
    while(1) {
        if (isValidClick == 1) {
            isValidClick = 0;
            curEdge = (unsigned long int) (PR2 + 1 )*overflow + TMR2;
            curPeriod = curEdge - validClick; //update global var if greater than 2ms
//            validClick = curEdge;
            numClick++;
            if (isFirstEdge == 1) {
                isFirstEdge = 0;
            }
            else {
                i++;
                if (curPeriod < 44000) { //if less than 1 s
                    //short click
                    lcd_print('0');
                    letter[i]  += '0';
                    isFirstEdge = 0;
                }
                else {
                    //long click
                    lcd_print('1');
                    letter[i]  += '1';
                    isFirstEdge = 0;
                    
                }
            }
            validClick = curEdge;
        }
        if ((unsigned long int)(PR2 + 1) * overflow + TMR2 - validClick > 125000 ) {
            //end of letter
            lcd_print('N');
            overflow = 0;
            TMR2 = 0;
            validClick = TMR2;
            prevEdge = TMR2;
            isValidClick = 0;
            isFirstEdge = 1;
        }
        
    }
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
//                    if (numClick == 1){ //1 clicks
//                        lcd_print('1');
//                        numClick = 0; 
//                    } 
//                    if (numClick == 3){ //2 clicks
//                        lcd_print('2');
//                        numClick = 0; 
//                    } 
//                    if (numClick == 5){ //3 clicks
//                        lcd_print('3');
//                        numClick = 0; 
//                    }
//                    if (numClick == 7){ //4 clicks
//                        lcd_print('4');
//                        numClick = 0; 
//                    }  
//                    else {
//                        numClick = 0;
//                    }
//                }
//                else {
//                    //not valid 
//                }
//            }
//        }
//        
//        //letter complete
//        if ((unsigned long int)(PR2 + 1) * overflow + TMR2 - validClick > 125000 ) {
//            overflow = 0;
//            TMR2 = 0;
//            validClick = TMR2;
//            prevEdge = TMR2;
//            //get letter
//            
//            //send to lcd
//            
//            numClick = 0;
//            isValidClick = 0;
//            isFirstEdge = 1;
//        }
//    }
    return 0;
}
