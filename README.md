# EE2361_FinalProject
This is our final project for EE2361

This project implements an "Adafruit Bluefruit LE UART Friend - Bluetooth Low Energy (BLE)" bluetooth module
that connects to a cellular device that displays a message written out by pressing a button on the breadboard
and this message will be using morse code.

The Microcontroller communicates with the bluetooth module using UART and sends 8-bit data containing letters
that are represented as their ascii character codes.

With the morse code, any press shorter than .5 seconds is a dot and anything longer is a dash. The LCD display
can either show the character returned from the morse code interpretation or the binary code gotten from the button.

Below is a rundown of all of the public functions used to make this project work:
Corresponding to UART:
  void delay_ms(unsigned int ms)
    Waits an inputted number of ms to continue program
  void sendChar(char c)
    Sends one character to the Adafruit Bluefruit LE UART Friend
  void init_UART(void)
    Initializes UART so that the PIC24 can communicate with the Adafruit Bluefruit LE UART Friend
  void hello_world(void)
    Prints “Hello World!\n” onto the app that comes with the Adafruit Bluefruit LE UART Friend
Corresponding to the Morse Code decoder:
  char morseCodeLib(void)
    Takes in a series of long and short pulses and translates them to the english alphabet
Corresponding to the button:
  void initPushButton(void)
    Sets up the button on pin RB8 on the pic24
  void buttonWatch(void)
    Watches the button for a series of long and short pulses
Corresponding to the LCD:
  void delay(unsigned int ms)
    Waits an inputted number of ms to continue the program
  void lcd_cmd(char Package)
    Send a command to the LCD
  void lcd_init(void)
    Sets up the lcd display to take characters
  void lcd_printChar(char Package)
    Prints a character on the lcd display
  void lcd_printStr(const char s[], int length)
    Prints a string on the lcd display
  void lcd_setCursor(char x, char y)
    Sets the cursor for where the given character is printed
  char int_to_char(int num) 
    Returns a character when given an int value (in order to print to lcd)
  void lcd_printWrappedStr(const char s[], int length)
    Prints a string on the lcd display
  char int_to_char(int num)
    Converts the integer value in the letter array to a character
  void print_binary_code_to_lcd(void)
    Prints the integer value that is being converted with the Morse Code decoder library to the LCD
In main:
  void pic24Init(void)
    Initializes the PIC24 (16 MHz frequency and digital I/O)

