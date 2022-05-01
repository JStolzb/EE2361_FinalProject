
#include "xc.h"
#include "LCD_Lib.h"

extern int letter[6];

void delay(unsigned int ms) {
    while (ms-- > 0) {
        asm("repeat #15998");
        asm("nop");
    }
}

void lcd_cmd(char Package) {
    // Send START
    IFS3bits.MI2C2IF = 0;
    I2C2CONbits.SEN = 1;
    while (I2C2CONbits.SEN == 1); // specific to start
//    while(IFS3bits.MI2C2IF == 0); // general purpose
    IFS3bits.MI2C2IF = 0;
    
    // send Address and Write command
    I2C2TRN = 0b01111100; // 8-bits consisting of the slave address and the R/nW bit
    
    while(IFS3bits.MI2C2IF == 0);
    IFS3bits.MI2C2IF = 0;
    
    // Send high byte
    I2C2TRN = 0b00000000; // control byte RS = CO = 0
    
    while(IFS3bits.MI2C2IF == 0);
    IFS3bits.MI2C2IF = 0;
    
    // Send data
    I2C2TRN = Package; // data byte
    
    while(IFS3bits.MI2C2IF == 0);
    IFS3bits.MI2C2IF = 0;
    
    // Send stop
    I2C2CONbits.PEN = 1;
    
    while(I2C2CONbits.PEN == 1);
}

void lcd_init(void) {
    I2C2CONbits.I2CEN = 0; // IC2 disable first (good practice)
    I2C2BRG = 157; // CLK frequency of 100 kHz (little off, actual number is 157.4)
    IFS3bits.MI2C2IF = 0; // clear interrupt flag
    I2C2CONbits.I2CEN = 1; // IC2 Enable
    
    delay(50);
    
    lcd_cmd(0b00111000); // function set
    lcd_cmd(0b00111001); // function set, advanced instruction mode
    lcd_cmd(0b00010100); // interval osc
    lcd_cmd(0b01110000); // contrast low
    lcd_cmd(0b01010110);
    lcd_cmd(0b01101100); // follower control
    
    delay(200);
    
    lcd_cmd(0b00111000); // function set
    lcd_cmd(0b00001100); // display on
    lcd_cmd(0b00000001); // clear display
    
    delay(1);
}

void lcd_printChar(char Package) {
    // Send START
    IFS3bits.MI2C2IF = 0;
    I2C2CONbits.SEN = 1;
    while (I2C2CONbits.SEN == 1); // specific to start
//    while(IFS3bits.MI2C2IF == 0); // general purpose
    IFS3bits.MI2C2IF = 0;
    
    // send Address and Write command
    I2C2TRN = 0b01111100; // 8-bits consisting of the slave address and the R/nW bit
    
    while(IFS3bits.MI2C2IF == 0);
    IFS3bits.MI2C2IF = 0;
    
    // Send high byte
    I2C2TRN = 0b01000000; // control byte RS = 1
    
    while(IFS3bits.MI2C2IF == 0);
    IFS3bits.MI2C2IF = 0;
    
    // Send data
    I2C2TRN = Package; // data byte
    
    while(IFS3bits.MI2C2IF == 0);
    IFS3bits.MI2C2IF = 0;
    
    // Send stop
    I2C2CONbits.PEN = 1;
    
    while(I2C2CONbits.PEN == 1);
}

void lcd_printStr(const char s[], int length) {
    int i;
    
    // Send START
    IFS3bits.MI2C2IF = 0;
    I2C2CONbits.SEN = 1;
    while (I2C2CONbits.SEN == 1); // specific to start
//    while(IFS3bits.MI2C2IF == 0); // general purpose
    IFS3bits.MI2C2IF = 0;
    
    // send Address and Write command
    I2C2TRN = 0b01111100; // 8-bits consisting of the slave address and the R/nW bit
    
    while(IFS3bits.MI2C2IF == 0);
    IFS3bits.MI2C2IF = 0;
    
    // if the data bit is the last bit, set CO = 0, otherwise, CO = 1
    // this saves on overhead so we only have to send one set of start,
    // stop, and address bytes
    for(i = 0; i < length; i++) {
        // send control byte
        if (i == length-1) {
            // control byte CO = 0, RS = 1 - last data bit is being sent
            I2C2TRN = 0b01000000; 
        } else {
            // control byte CO = RS = 1 - for sending additional data after
            I2C2TRN = 0b11000000; 
        }
        
        while(IFS3bits.MI2C2IF == 0);
        IFS3bits.MI2C2IF = 0;
        
        // Send data
        I2C2TRN = s[i]; // data byte
    
        while(IFS3bits.MI2C2IF == 0);
        IFS3bits.MI2C2IF = 0;
    }
    
    // Send stop
    I2C2CONbits.PEN = 1;
    
    while(I2C2CONbits.PEN == 1);
}

void lcd_setCursor(char x, char y) {
    // set cursor location with x 0-7 and y 0-1
    lcd_cmd((0x40)*y + x + 0x80);
}

void lcd_printWrappedStr(const char s[], int length) {
    int i;
    
    // memory addresses wrap after 5 times through 8 bits
    // i.e. sections of dram for lcd display designated to first row and second row
    // this fills the whole set of dram set for top and bot rows and can be shifted thru
    for(i = 0; i < 5; i++) {
        lcd_printStr(s, length);
    }
    
}

char int_to_char(int num) { // converts the int in letter to values in binary
    if (num == 0) {
        return '0';
    } else if (num == 1) {
        return '1';
    } else if (num == 2) {
        return 'N';
    }
}

void print_binary_code_to_lcd(void) {   // prints the binary string to the LCD
    lcd_printChar(int_to_char(letter[0]));
    delay_ms(50);
    lcd_printChar(int_to_char(letter[1]));
    delay_ms(50);
    lcd_printChar(int_to_char(letter[2]));
    delay_ms(50);
    lcd_printChar(int_to_char(letter[3]));
    delay_ms(50);
    lcd_printChar(int_to_char(letter[4]));
    delay_ms(50);
    lcd_printChar(int_to_char(letter[5]));
    delay_ms(50);
}
