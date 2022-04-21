#include "xc.h"

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


void setup(void) {
        CLKDIVbits.RCDIV = 0;  //Set RCDIV=1:1 (default 2:1) 32MHz or FCY/2=16M
        AD1PCFG = 0xffff;
}

char morseCodeLib(const char s[]) {
    // Given an binary encoded morse character, this function will
    // return the associated character
    // This library handles A-Z and 0-9
    switch(s) {
        case '01':
            return 'A';
        case '1000':
            return 'B';
        case '1010':
            return 'C';
        case '100':
            return 'D';
        case '0':
            return 'E';
        case '0010':
            return 'F';
        case '110':
            return 'G';
        case '0000':
            return 'H';
        case '00':
            return 'I';
        case '0111':
            return 'J';
        case '101':
            return 'K';
        case '0100':
            return 'L';
        case '11':
            return 'M';
        case '10':
            return 'N';
        case '111':
            return 'O';
        case '0110':
            return 'P';
        case '1101':
            return 'Q';
        case '010':
            return 'R';
        case '000':
            return 'S';
        case '1':
            return 'T';
        case '001':
            return 'U';
        case '0001':
            return 'V';
        case '011':
            return 'W';
        case '1001':
            return 'X';
        case '1011':
            return 'Y';
        case '1100':
            return 'Z';
        case '0111':
            return '1';
        case '00111':
            return '2';
        case '00011':
            return '3';
        case '00001':
            return '4';
        case '00000':
            return '5';
        case '10000':
            return '6';
        case '11000':
            return '7';
        case '11100':
            return '8';
        case '11110':
            return '9';
        case '11111':
            return '0';
    }
}


int main(void) {
    setup();
    while(1) {
        
    }
    return 0;
}
