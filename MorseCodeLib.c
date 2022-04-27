#include "xc.h"
#include "MorseCodeLib.h"

char morseCodeLib(const char s[]) {
    // Given an binary encoded morse character, this function will
    // return the associated character
    // This library handles A-Z, 0-9, and .,?
        if (s == "01"){
            return 'A';
        }
        else if (s == "1000"){
            return 'B';
        }
        else if (s == "1010"){
            return 'C';
        }
        else if (s == "100"){
            return 'D';
        }
        else if (s == "0"){
            return 'E';
        }
        else if (s == "0010"){
            return 'F';
        }
        else if (s == "110"){
            return 'G';
        }
        else if (s == "0000"){
            return 'H';
        }
        else if (s == "00"){
            return 'I';
        }
        else if (s == "0111"){
            return 'J';
        }
        else if (s == "101"){
            return 'K';
        }
        else if (s == "0100"){
            return 'L';
        }
        else if (s == "11"){
            return 'M';
        }
        else if (s == "10"){
            return 'N';
        }
        else if (s == "111"){
            return 'O';
        }
        else if (s == "0110"){
            return 'P';
        }
        else if (s == "1101"){
            return 'Q';
        }
        else if (s == "010"){
            return 'R';
        }
        else if (s == "000"){
            return 'S';
        }
        else if (s == "1"){
            return 'T';
        }
        else if (s == "001"){
            return 'U';
        }
        else if (s == "0001"){
            return 'V';
        }
        else if (s == "011"){
            return 'W';
        }
        else if (s == "1001"){
            return 'X';
        }
        else if (s == "1011"){
            return 'Y';
        }
        else if (s == "1100"){
            return 'Z';
        }
        else if (s == "0111"){
            return '1';
        }
        else if (s == "00111"){
            return '2';
        }
        else if (s == "00011"){
            return '3';
        }
        else if (s == "00001"){
            return '4';
        }
        else if (s == "00000"){
            return '5';
        }
        else if (s == "10000"){
            return '6';
        }
        else if (s == "11000"){
            return '7';
        }
        else if (s == "11100"){
            return '8';
        }
        else if (s == "11110"){
            return '9';
        }
        else if (s == "11111"){
            return '0';
        }
        else if (s == "010101"){
            return '.';
        }
        else if (s == "110011"){
            return ',';
        }
        else if (s == "001100"){
            return '?';
        }
}