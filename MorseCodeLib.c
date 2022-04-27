#include "xc.h"
#include "MorseCodeLib.h"
#include "string.h"

char morseCodeLib(void) {
    // Given an binary encoded morse character, this function will
    // return the associated character
    // This library handles A-Z, 0-9, and .,?
    
    extern char letter[6];
    
        if (letter == "01"){
            return 'A';
        }
        else if (letter == "1000"){
            return 'B';
        }
        else if (letter == "1010"){
            return 'C';
        }
        else if (letter == "100"){
            return 'D';
        }
        else if (letter == "0"){
            return 'E';
        }
        else if (letter == "0010"){
            return 'F';
        }
        else if (letter == "110"){
            return 'G';
        }
        else if (letter == "0000"){
            return 'H';
        }
        else if (letter == "00"){
            return 'I';
        }
        else if (letter == "0111"){
            return 'J';
        }
        else if (letter == "101"){
            return 'K';
        }
        else if (letter == "0100"){
            return 'L';
        }
        else if (letter == "11"){
            return 'M';
        }
        else if (letter == "10"){
            return 'N';
        }
        else if (letter == "111"){
            return 'O';
        }
        else if (letter == "0110"){
            return 'P';
        }
        else if (letter == "1101"){
            return 'Q';
        }
        else if (letter == "010"){
            return 'R';
        }
        else if (letter == "000"){
            return 'S';
        }
        else if (letter == "1"){
            return 'T';
        }
        else if (letter == "001"){
            return 'U';
        }
        else if (letter == "0001"){
            return 'V';
        }
        else if (letter == "011"){
            return 'W';
        }
        else if (letter == "1001"){
            return 'X';
        }
        else if (letter == "1011"){
            return 'Y';
        }
        else if (letter == "1100"){
            return 'Z';
        }
        else if (letter == "0111"){
            return '1';
        }
        else if (letter == "00111"){
            return '2';
        }
        else if (letter == "00011"){
            return '3';
        }
        else if (letter == "00001"){
            return '4';
        }
        else if (letter == "00000"){
            return '5';
        }
        else if (letter == "10000"){
            return '6';
        }
        else if (letter == "11000"){
            return '7';
        }
        else if (letter == "11100"){
            return '8';
        }
        else if (letter == "11110"){
            return '9';
        }
        else if (letter == "11111N"){
            return '0';
        }
        else if (letter == "010101"){
            return '.';
        }
        else if (letter == "110011"){
            return ',';
        }
        else if (letter == "001100"){
            return '?';
        }
}