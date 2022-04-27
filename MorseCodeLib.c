#include "xc.h"
#include "MorseCodeLib.h"
#include "string.h"

char morseCodeLib(void) {
    // Given an binary encoded morse character, this function will
    // return the associated character
    // This library handles A-Z, 0-9, and .,?
    
    extern char letter[6];
    
        if (letter == "01NNNN"){
            return 'A';
        }
        else if (letter == "1000NN"){
            return 'B';
        }
        else if (letter == "1010NN"){
            return 'C';
        }
        else if (letter == "100NNN"){
            return 'D';
        }
        else if (letter == "0NNNNN"){
            return 'E';
        }
        else if (letter == "0010NN"){
            return 'F';
        }
        else if (letter == "110NNN"){
            return 'G';
        }
        else if (letter == "0000NN"){
            return 'H';
        }
        else if (letter == "00NNNN"){
            return 'I';
        }
        else if (letter == "0111NN"){
            return 'J';
        }
        else if (letter == "101NNN"){
            return 'K';
        }
        else if (letter == "0100NN"){
            return 'L';
        }
        else if (letter == "11NNNN"){
            return 'M';
        }
        else if (letter == "10NNNN"){
            return 'N';
        }
        else if (letter == "111NNN"){
            return 'O';
        }
        else if (letter == "0110NN"){
            return 'P';
        }
        else if (letter == "1101NN"){
            return 'Q';
        }
        else if (letter == "010NN"){
            return 'R';
        }
        else if (letter == "000NNN"){
            return 'S';
        }
        else if (letter == "1NNNNN"){
            return 'T';
        }
        else if (letter == "001NNN"){
            return 'U';
        }
        else if (letter == "0001NN"){
            return 'V';
        }
        else if (letter == "011NNN"){
            return 'W';
        }
        else if (letter == "1001NN"){
            return 'X';
        }
        else if (letter == "1011NN"){
            return 'Y';
        }
        else if (letter == "1100NN"){
            return 'Z';
        }
        else if (letter == "0111NN"){
            return '1';
        }
        else if (letter == "00111N"){
            return '2';
        }
        else if (letter == "00011N"){
            return '3';
        }
        else if (letter == "00001N"){
            return '4';
        }
        else if (letter == "00000N"){
            return '5';
        }
        else if (letter == "10000N"){
            return '6';
        }
        else if (letter == "11000N"){
            return '7';
        }
        else if (letter == "11100N"){
            return '8';
        }
        else if (letter == "11110N"){
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