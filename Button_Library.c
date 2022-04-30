#include "xc.h"
#include "LCD_lib.h"
#include "Button_Library.h"

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

#define dot 31250
#define dash 62499

volatile unsigned long int overflow = 0;
volatile unsigned long int dutyCycle = 0;
volatile char letter[6];
volatile int posEdge = 0;

void initPushButton(void){
    
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
        letter[i] = 'N';
    }
    i = 0;
    
    while(1){
        if(dutyCycle <= dot && dutyCycle > 325){     //.25 sec
            letter[i] = '0';
            i++;
            dutyCycle = 0;
            TMR2 = 0;
            overflow = 0;
        }
        else if(dutyCycle > dot){       //.75 sec
            letter[i] = '1';
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
