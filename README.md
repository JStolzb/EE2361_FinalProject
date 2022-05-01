# EE2361_FinalProject

## Introduction/Rundown
This is our final project for EE2361

This project implements an "Adafruit Bluefruit LE UART Friend - Bluetooth Low Energy (BLE)" bluetooth module
that connects to a cellular device that displays a message written out by pressing a button on the breadboard
and this message will be using morse code.

The Microcontroller communicates with the bluetooth module using UART and sends 8-bit data containing letters
that are represented as their ascii character codes.

With the morse code, any press shorter than .5 seconds is a dot and anything longer is a dash. The LCD display
can either show the character returned from the morse code interpretation or the binary code gotten from the button.

## Public Functions

### UART:
* void delay_ms(unsigned int ms)
  * Waits an inputted number of ms to continue program
* void sendChar(char c)
  * Sends one character to the Adafruit Bluefruit LE UART Friend
* void init_UART(void)
  * Initializes UART so that the PIC24 can communicate with the Adafruit Bluefruit LE UART Friend
* void hello_world(void)
  * Prints “Hello World!\n” onto the app that comes with the Adafruit Bluefruit LE UART Friend
    
    
### Morse Code Lib
* char morseCodeLib(void)
  * Takes in a series of long and short pulses and translates them to the english alphabet
    
    
### Button Library
* void initPushButton(void)
  * Sets up the button on pin RB8 on the pic24
* void buttonWatch(void)
  * Watches the button for a series of long and short pulses
    
    
### LCD Library
* void delay(unsigned int ms)
  * Waits an inputted number of ms to continue the program
* void lcd_cmd(char Package)
  * Send a command to the LCD
* void lcd_init(void)
  * Sets up the lcd display to take characters
* void lcd_printChar(char Package)
  * Prints a character on the lcd display
* void lcd_printStr(const char s[], int length)
  * Prints a string on the lcd display
* void lcd_setCursor(char x, char y)
  * Sets the cursor for where the given character is printed
* char int_to_char(int num) 
  * Returns a character when given an int value (in order to print to lcd)
* void lcd_printWrappedStr(const char s[], int length)
  * Prints a string on the lcd display
* char int_to_char(int num)
  * Converts the integer value in the letter array to a character
* void print_binary_code_to_lcd(void)
  * Prints the integer value that is being converted with the Morse Code decoder library to the LCD
    
    
### Main
* void pic24Init(void)
  * Initializes the PIC24 (16 MHz frequency and digital I/O)


## Examples on how to use this project

### Basic Usage
To test the basic usage of this project, a long click and a short click can be tested. First, the should click (less than 0.5s) would be inputted into the system and the letter ‘E’ would be sent to the bluetooth module. For a long click, the button must be held for longer than 0.5s and then the letter ‘T’ will be sent to the bluetooth. 

### Advanced Usage Example
In order to demonstrate the advanced usage of this design a button is pressed in a sequence of, long and short duration, clicks to represent the bit values of an English character in the form of morse code. This was then performed multiple times to send a series of characters through the bluetooth module and create a whole word. For example, the button would be pressed in the following order,
* Short-Short-Short-Short		“H”
* Short					“E”
* Short-Long-Short-Short		“L”
* Short-Long-Short-Short		“L”
* Long-Long-Long			“O”
* Long-Short-Long-Short-Long-Long	“!”

The display on the user's phone would then read out, “HELLO!”.
