/*
 * File:   final_proj_2361_v001.c
 * Author: devonuram
 *
 * Created on April 14, 2022, 12:28 PM
 */


#include "xc.h"

#pragma config ICS = PGx1
#pragma config FWDTEN = OFF
#pragma config GWRP = OFF
#pragma config GCP = OFF
#pragma config JTAGEN = OFF

#pragma config I2C1SEL = PRI
#pragma config IOL1WAY = OFF
#pragma config OSCIOFNC = ON
#pragma config FCKSM = CSECME

#pragma config FNOSC = FRCPLL

void delay_ms(unsigned int ms) {
    while (ms-- > 0) {
        asm("repeat #15998");
        asm("nop");
    }
}

void pic24_init(void) { // initializes the PIC
    _RCDIV = 0; // sets frequency of 16 MHz
    AD1PCFG = 0x9fff;   // sets all pins digital
    
}

void init_UART(void) {
    _TRISB6 = 0;  // U1TX output
    _TRISB10 = 1; // U1RX input
    
    U1MODE = 0;
    //U1MODEbits.UARTEN = 1;  // enables UART1
    //U1STAbits.UTXEN = 1;    // UART1 transmitter enable
    U1MODEbits.PDSEL = 0b00;    // 8-bit data, no parity
    U1MODEbits.STSEL = 0;   // 1 stop bit
    
    U1MODEbits.BRGH = 0;    // BRG generates 16 clocks per bit period (standard)
    U1BRG = 103; // 9600 baud (check the calculation with the datasheet, pg. 160)
                // using equation 17-1 (BRGH = 0)
    U1MODEbits.UEN = 0; // U1TX and U1RX pins are enabled and used
    U1MODEbits.UARTEN = 1;  // enables UART1, only enables receive side
    U1STAbits.UTXEN = 1;    // enables UART1 transmit side only

    // Peripheral Pin Select 
    __builtin_write_OSCCONL(OSCCON & 0xbf); // unlock PPS
    _RP6R = 0x0003;   //RB6->UART1:U1TX; See Table 10-3 on P109 of the datasheet
    _U1RXR = 10;   //RB10->UART1:U1RX;
    __builtin_write_OSCCONL(OSCCON | 0x40); // lock   PPS

    IFS0bits.U1RXIF = 0;    // reset receiver interrupt flag
    IFS0bits.U1TXIF = 0;    // reset transmitter interrupt flag
    //IEC0bits.U1RXIE = 1;    // enable interrupt flag, need this to utilize ISR
    
    U1STAbits.UTXISEL0 = 0; // interrupt after one TX character is transmitted
    U1STAbits.UTXISEL1 = 0;
    
    _U1TXIE = 1;    // enable UART TX interrupt
}

/*void PPutch(const unsigned char c)
{
    while (!IFS0bits.U1TXIF);
    IFS0bits.U1TXIF = 0;
    U1TXREG = c;
}*/

void __attribute__((__interrupt__,__auto_psv__)) _U1TXInterrupt(void) {
    _U1TXIF = 0;
    //U1TXREG = 'b';
    //delay_ms(1000);
}

int main(void) {
    pic24_init();
    init_UART();
    
    delay_ms(500);  // need to wait at least 105 us (1/9600) before sending the
                    // first char
    //U1TXREG = 'a';
    
    while(1) {
        U1TXREG = 'H';
        delay_ms(100);
        U1TXREG = 'e';
        delay_ms(100);
        U1TXREG = 'l';
        delay_ms(100);
        U1TXREG = 'l';
        delay_ms(100);
        U1TXREG = 'o';
        delay_ms(100);
        U1TXREG = ' ';
        delay_ms(100);
        U1TXREG = 'W';
        delay_ms(100);
        U1TXREG = 'o';
        delay_ms(100);
        U1TXREG = 'r';
        delay_ms(100);
        U1TXREG = 'l';
        delay_ms(100);
        U1TXREG = 'd';
        delay_ms(100);
        U1TXREG = '!';
        delay_ms(1000);
        U1TXREG = 0x0D;
        U1TXREG = 0x0A;
        
    }
    
    return 0;
}
