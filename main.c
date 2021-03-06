#include "xc.h"
#include "string.h"
#include "Button_Library.h"
#include "MorseCodeLib.h"
#include "LCD_Lib.h"
#include "UART_Adafruit.h"

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


extern int letter[6];

void pic24Init(void) { // initializes the PIC
    _RCDIV = 0; // sets frequency of 16 MHz
    AD1PCFG = 0x9fff;   // sets all pins digital
}

int main(void) {
    pic24Init();
    initPushButton();
    lcd_init();
    init_UART();
    
    char sendToBlu = '0';   // initializes character that will be sent to the Bluefruit
    
    delay_ms(500); //need to wait at least 105 us (1/9600) before sending the first char
    //lcd_setCursor(0,0);
    
    
    while(1){
        
        buttonWatch();
        sendToBlu = morseCodeLib();
        lcd_setCursor(0,0);
        //lcd_printChar(sendToBlu);
        print_binary_code_to_lcd();
        
        sendChar(sendToBlu);
        delay_ms(1000);
    }
    return 0;
}