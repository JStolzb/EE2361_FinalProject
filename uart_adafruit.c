/* Configures UART with the PIC24 and Adafruit Bluefruit LE
 *
 * by: Devon Uram, Jack Smith, John Stolzberg-Shray, & Megan Adamek
 *
 * emails: uram0283@umn.edu, smi01223@umn.edu, stolz050@umn.edu, &
 *  adame473@umn.edu
 * 
 * date: 4/21/22
 */

#include "xc.h"
#include "uart_adafruit.h"

void __attribute__((__interrupt__,__auto_psv__)) _U1TXInterrupt(void) {
    _U1TXIF = 0;
}

void delay_ms(unsigned int ms) {
    while (ms-- > 0) {
        asm("repeat #15998");
        asm("nop");
    }
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

void hello_world(void) {    // prints "Hello World!\n" onto Adafruit app
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


