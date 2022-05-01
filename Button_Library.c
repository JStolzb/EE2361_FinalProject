#include "xc.h"
#include "LCD_lib.h"
#include "Button_Library.h"

#define dot 31250
#define dash 62499

volatile unsigned long int overflow = 0;
volatile unsigned long int dutyCycle = 0;
volatile int letter[6];
volatile int posEdge = 0;

void initPushButton(void){
    TRISBbits.TRISB8 = 1;   // RB8 input connected to button
    _CN22PUE = 1;   // pull-up resistor on RB8
    
    I2C2CONbits.I2CEN = 0;
    I2C2BRG = 0x9D; 
    I2C2CONbits.I2CEN = 1;
    IFS3bits.MI2C2IF = 0;
    
    T2CON = 0x0030;                             //Stop Timer, Tcy clk input, PRE 1:256
    TMR2 = 0;                                   // Initialize to zero (also best practice)
    PR2 = 62499;                                // Set period to be larger than max external sig duration (1 sec))
    _T2IE = 1;
    _T2IF = 0;
    
    __builtin_write_OSCCONL(OSCCON & 0xbf); // unlock PPS
    _IC1R = 8;   //IC! <- RB8; See Table 10-2 on P108 of the datasheet
    _IC2R = 8;   //IC! <- RB8; See Table 10-2 on P108 of the datasheet
    __builtin_write_OSCCONL(OSCCON | 0x40); // lock   PPS
    
    IC1CONbits.ICM = 0b010;         // every rising edge
    _IC1IF = 0;
    _IC1IE = 1;
    IC1CONbits.ICTMR = 1;           //select timer 2
    
    IC2CONbits.ICM = 0b011;         // every falling edge
    _IC2IF = 0;
    _IC2IE = 1;
    IC2CONbits.ICTMR = 1;           //select timer 2
    
    T2CONbits.TON = 1;              // Restart 16-bit Timer2
}

void __attribute__((interrupt, auto_psv)) _IC1Interrupt(void){
    _IC1IF = 0;

    TMR2 = 0;
    overflow = 0;
}

void __attribute__((interrupt, auto_psv)) _IC2Interrupt(void){
    _IC2IF = 0;
    
    if ((TMR2 + (unsigned long)((PR2+1) * overflow)) > 325){
        dutyCycle = (TMR2 + (unsigned long)((PR2+1) * overflow));
    }
    
}

void __attribute__((interrupt, auto_psv)) _T2Interrupt(void){
    _T2IF = 0;
    overflow++;
}

void buttonWatch(void){
       
    int i;
    for(i=0;i<6;i++){
        letter[i] = 2;
    }
    i = 0;
    
    while(1){
        if(dutyCycle <= dot && dutyCycle > 325){     //.25 sec
            letter[i] = 0;
            i++;
            dutyCycle = 0;
            TMR2 = 0;
            overflow = 0;
        }
        else if(dutyCycle > dot){       //.75 sec
            letter[i] = 1;
            i++;
            dutyCycle = 0;
            TMR2 = 0;
            overflow = 0;
        }

        if(((TMR2 + (unsigned long)((PR2+1) * overflow))) >= (2 * 62500)){  //2 sec
            dutyCycle = 0;
            break;
        }
    }
}
