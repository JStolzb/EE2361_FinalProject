#include "xc.h"
#include "string.h"
#include "MorseCodeLib.h"
#include "Button.h"
#include "ButtonLibrary.h"
#include "LCD_Lib.h"
#include "UART_Adafruit.h"

extern char letter[6];

char morseCodeLib(void) {
    // Given an binary encoded morse character, this function will
    // return the associated character
    // This library handles A-Z, 0-9, and .,?
    
        if (!strcmp(letter, "01NNNN")){
            return 'A';
        }
        else if (!strcmp(letter, "1000NN")){
            return 'B';
        }
        else if (!strcmp(letter, "1010NN")){
            return 'C';
        }
        else if (!strcmp(letter, "100NNN")){
            return 'D';
        }
        else if (!strcmp(letter, "0NNNNN")){
            return 'E';
        }
        else if (!strcmp(letter, "0010NN")){
            return 'F';
        }
        else if (!strcmp(letter, "110NNN")){
            return 'G';
        }
        else if (!strcmp(letter, "0000NN")){
            return 'H';
        }
        else if (!strcmp(letter, "00NNNN")){
            return 'I';
        }
        else if (!strcmp(letter, "0111NN")){
            return 'J';
        }
        else if (!strcmp(letter, "101NNN")){
            return 'K';
        }
        else if (!strcmp(letter, "0100NN")){
            return 'L';
        }
        else if (!strcmp(letter, "11NNNN")){
            return 'M';
        }
        else if (!strcmp(letter, "10NNNN")){
            return 'N';
        }
        else if (!strcmp(letter, "111NNN")){
            return 'O';
        }
        else if (!strcmp(letter, "0110NN")){
            return 'P';
        }
        else if (!strcmp(letter, "1101NN")){
            return 'Q';
        }
        else if (!strcmp(letter, "010NNN")){
            return 'R';
        }
        else if (!strcmp(letter, "000NNN")){
            return 'S';
        }
        else if (!strcmp(letter, "1NNNNN")){
            return 'T';
        }
        else if (!strcmp(letter, "001NNN")){
            return 'U';
        }
        else if (!strcmp(letter, "0001NN")){
            return 'V';
        }
        else if (!strcmp(letter, "011NNN")){
            return 'W';
        }
        else if (!strcmp(letter, "1001NN")){
            return 'X';
        }
        else if (!strcmp(letter, "1011NN")){
            return 'Y';
        }
        else if (!strcmp(letter, "1100NN")){
            return 'Z';
        }
        else if (!strcmp(letter, "0111NN")){
            return '1';
        }
        else if (!strcmp(letter, "00111N")){
            return '2';
        }
        else if (!strcmp(letter, "00011N")){
            return '3';
        }
        else if (!strcmp(letter, "00001N")){
            return '4';
        }
        else if (!strcmp(letter, "00000N")){
            return '5';
        }
        else if (!strcmp(letter, "10000N")){
            return '6';
        }
        else if (!strcmp(letter, "11000N")){
            return '7';
        }
        else if (!strcmp(letter, "11100N")){
            return '8';
        }
        else if (!strcmp(letter, "11110N")){
            return '9';
        }
        else if (!strcmp(letter, "11111N")){
            return '0';
        }
        else if (!strcmp(letter, "010101")){
            return '.';
        }
        else if (!strcmp(letter, "110011")){
            return ',';
        }
        else if (!strcmp(letter, "001100")){
            return '?';
        }
        else{
            return '#';
        }
}