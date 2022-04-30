#include "xc.h"
#include "MorseCodeLib.h"
#include "Button_Library.h"
#include "string.h"

extern int letter[6];

char morseCodeLib(void) {
    // Given an binary encoded morse character, this function will
    // return the associated character
    // This library handles A-Z, 0-9, and ?!.,;:+-/=
 
    
    if(letter[0] == 0){
        
        if(letter[1] == 2){
            return 'E';             //.
        }
        
        else if(letter[1] == 0){
            if(letter[2] == 2){
                return 'I';          //..
            }
            
            else if(letter[2] == 0){
                if(letter[3] == 2){
                    return 'S';          //...
                }
                
                else if(letter[3] == 0){
                    if(letter[4] == 2){
                        return 'H';          //....
                    }
                    
                    else if(letter[4] == 0){
                        if(letter[5] == 2){
                            return '5';          //.....
                        }
                        
//                        else if(letter[5] == 0){
//                            return '';          //......
//                        }
//                        
//                        else if(letter[5] == 1){
//                            return '';          //.....-
//                        }
                    }
                    
                    else if(letter[4] == 1){
                        if(letter[5] == 2){
                            return '4';          //....-
                        }
                        
//                        else if(letter[5] == 0){
//                            return '';          //....-.
//                        }
                        
//                        else if(letter[5] == 1){
//                            return '';          //....--
//                        }
                    }
                    
                }
                
                else if(letter[3] == 1){
                    if(letter[4] == 2){
                        return 'V';          //...-
                    }
                    
//                    else if(letter[4] == 0){
//                        if(letter[5] == 2){
//                            return '';          //...-.
//                        }
//                        
//                        else if(letter[5] == 0){
//                            return '';          //...-..
//                        }
//                        
//                        else if(letter[5] == 1){
//                            return '';          //...-.-
//                        }
//                    }
                    
                    else if(letter[4] == 1){
                        if(letter[5] == 2){
                            return '3';          //...--
                        }
                        
//                        else if(letter[5] == 0){
//                            return '';          //...--.
//                        }
//                        
//                        else if(letter[5] == 1){
//                            return '';          //...---
//                        }
                    }
                    
                }
            
            }
            
            else if(letter[2] == 1){
                if(letter[3] == 2){
                    return 'U';          //..-
                }
                
                else if(letter[3] == 0){
                    if(letter[4] == 2){
                        return 'F';          //..-.
                    }
                    
//                    else if(letter[4] == 0){
//                        if(letter[5] == 2){
//                            return '';          //..-..
//                        }
//                        
//                        else if(letter[5] == 0){
//                            return '';          //..-...
//                        }
//                        
//                        else if(letter[5] == 1){
//                            return '';          //..-..-
//                        }
//                    }
                    
//                    else if(letter[4] == 1){
//                        if(letter[5] == 2){
//                            return '';          //..-.-
//                        }
//                        
//                        else if(letter[5] == 0){
//                            return '';          //..-.-.
//                        }
//                        
//                        else if(letter[5] == 1){
//                            return '';          //..-.--
//                        }
//                    }
                    
                }
                
                else if(letter[3] == 1){
//                    if(letter[4] == 2){
//                        return '';          //..--
//                    }
                    
                    if(letter[4] == 0){
//                        if(letter[5] == 2){
//                            return '';          //..--.
//                        }
                        
                        if(letter[5] == 0){
                            return '?';          //..--..
                        }
                        
//                        else if(letter[5] == 1){
//                            return '';          //..--.-
//                        }
                    }
                    
                    else if(letter[4] == 1){
                        if(letter[5] == 2){
                            return '2';          //..---
                        }
                        
//                        else if(letter[5] == 0){
//                            return '';          //..---.
//                        }
//                        
//                        else if(letter[5] == 1){
//                            return '';          //..----
//                        }
                    }
                }
            }
        }
        
        else if(letter[1] == 1){    
            if(letter[2] == 2){
                return 'A';          //.-
            }
            
            else if(letter[2] == 0){
                if(letter[3] == 2){
                    return 'R';          //.-.
                }
                
                else if(letter[3] == 0){
                    if(letter[4] == 2){
                        return 'L';          //.-..
                    }
                    
//                    else if(letter[4] == 0){
//                        if(letter[5] == 2){
//                            return '';          //.-...
//                        }
//                        
//                        else if(letter[5] == 0){
//                            return '';          //.-....
//                        }
//                        
//                        else if(letter[5] == 1){
//                            return '';          //.-...-
//                        }
//                    }
                    
//                    else if(letter[4] == 1){
//                        if(letter[5] == 2){
//                            return '';          //.-..-
//                        }
//                        
//                        else if(letter[5] == 0){
//                            return '';          //.-..-.
//                        }
//                        
//                        else if(letter[5] == 1){
//                            return '';          //.-..--
//                        }
//                    }
                    
                }
                
                else if(letter[3] == 1){
//                    if(letter[4] == 2){
//                        return '';          //.-.-
//                    }
                    
                    if(letter[4] == 0){
                        if(letter[5] == 2){
                            return '+';          //.-.-.
                        }
                        
//                        else if(letter[5] == 0){
//                            return '';          //.-.-..
//                        }
                        
                        else if(letter[5] == 1){
                            return '.';          //.-.-.-
                        }
                    }
                    
//                    else if(letter[4] == 1){
//                        if(letter[5] == 2){
//                            return '';          //.-.--
//                        }
//                        
//                        else if(letter[5] == 0){
//                            return '';          //.-.--.
//                        }
//                        
//                        else if(letter[5] == 1){
//                            return '';          //.-.---
//                        }
//                    }
                    
                }
            
            }
            
            else if(letter[2] == 1){
                if(letter[3] == 2){
                    return 'W';          //.--
                }
                
                else if(letter[3] == 0){
                    if(letter[4] == 2){
                        return 'P';          //.--.
                    }
                    
//                    else if(letter[4] == 0){
//                        if(letter[5] == 2){
//                            return '';          //.--..
//                        }
//                        
//                        else if(letter[5] == 0){
//                            return '';          //.--...
//                        }
//                        
//                        else if(letter[5] == 1){
//                            return '';          //.--..-
//                        }
//                    }
//                    
//                    else if(letter[4] == 1){
//                        if(letter[5] == 2){
//                            return '';          //.--.-
//                        }
//                        
//                        else if(letter[5] == 0){
//                            return '';          //.--.-.
//                        }
//                        
//                        else if(letter[5] == 1){
//                            return '';          //.--.--
//                        }
//                    }
                    
                }
                
                else if(letter[3] == 1){
                    if(letter[4] == 2){
                        return 'J';          //.---
                    }
                    
//                    else if(letter[4] == 0){
//                        if(letter[5] == 2){
//                            return '';          //.---.
//                        }
//                        
//                        else if(letter[5] == 0){
//                            return '';          //.---..
//                        }
//                        
//                        else if(letter[5] == 1){
//                            return '';          //.---.-
//                        }
//                    }
                    
                    else if(letter[4] == 1){
                        if(letter[5] == 2){
                            return '1';          //.----
                        }
                        
//                        else if(letter[5] == 0){
//                            return '';          //.----.
//                        }
//                        
//                        else if(letter[5] == 1){
//                            return '';          //.-----
//                        }
                    }
                }
            }
        }
    }
    
    else if(letter[0] == 1){
        
        if(letter[1] == 2){
            return 'T';             //-
        }
        
        else if(letter[1] == 0){
            if(letter[2] == 2){
                return 'N';          //-.
            }
            
            else if(letter[2] == 0){
                if(letter[3] == 2){
                    return 'D';          //-..
                }
                
                else if(letter[3] == 0){
                    if(letter[4] == 2){
                        return 'B';          //-...
                    }
                    
                    else if(letter[4] == 0){
                        if(letter[5] == 2){
                            return '6';          //-....
                        }
                        
//                        else if(letter[5] == 0){
//                            return '';          //-.....
//                        }
                        
                        else if(letter[5] == 1){
                            return '-';          //-....-
                        }
                    }
                    
                    else if(letter[4] == 1){
                        if(letter[5] == 2){
                            return '=';          //-...-
                        }
                        
//                        else if(letter[5] == 0){
//                            return '';          //-...-.
//                        }
//                        
//                        else if(letter[5] == 1){
//                            return '';          //-...--
//                        }
                    }
                    
                }
                
                else if(letter[3] == 1){
                    if(letter[4] == 2){
                        return 'X';          //-..-
                    }
                    
                    else if(letter[4] == 0){
                        if(letter[5] == 2){
                            return '/';          //-..-.
                        }
                        
//                        else if(letter[5] == 0){
//                            return '';          //-..-..
//                        }
//                        
//                        else if(letter[5] == 1){
//                            return '';          //-..-.-
//                        }
                    }
                    
//                    else if(letter[4] == 1){
//                        if(letter[5] == 2){
//                            return '';          //-..--
//                        }
//                        
//                        else if(letter[5] == 0){
//                            return '';          //-..--.
//                        }
//                        
//                        else if(letter[5] == 1){
//                            return '';          //-..---
//                        }
//                    }
                    
                }
            
            }
            
            else if(letter[2] == 1){
                if(letter[3] == 2){
                    return 'K';          //-.-
                }
                
                else if(letter[3] == 0){
                    if(letter[4] == 2){
                        return 'C';          //-.-.
                    }
                    
//                    else if(letter[4] == 0){
//                        if(letter[5] == 2){
//                            return '';          //-.-..
//                        }
//                        
//                        else if(letter[5] == 0){
//                            return '';          //-.-...
//                        }
//                        
//                        else if(letter[5] == 1){
//                            return '';          //-.-..-
//                        }
//                    }
                    
                    else if(letter[4] == 1){
//                        if(letter[5] == 2){
//                            return '';          //-.-.-
//                        }
                        
                        if(letter[5] == 0){
                            return ';';          //-.-.-.
                        }
                        
                        else if(letter[5] == 1){
                            return '!';          //-.-.--
                        }
                    }
                    
                }
                
                else if(letter[3] == 1){
                    if(letter[4] == 2){
                        return 'Y';          //-.--
                    }
                    
//                    else if(letter[4] == 0){
//                        if(letter[5] == 2){
//                            return '';          //-.--.
//                        }
//                        
//                        else if(letter[5] == 0){
//                            return '';          //-.--..
//                        }
//                        
//                        else if(letter[5] == 1){
//                            return '';          //-.--.-
//                        }
//                    }
                    
//                    else if(letter[4] == 1){
//                        if(letter[5] == 2){
//                            return '';          //-.---
//                        }
//                        
//                        else if(letter[5] == 0){
//                            return '';          //-.---.
//                        }
//                        
//                        else if(letter[5] == 1){
//                            return '';          //-.----
//                        }
//                    }
                }
            }
        }
        
        else if(letter[1] == 1){    
            if(letter[2] == 2){
                return 'M';          //--
            }
            
            else if(letter[2] == 0){
                if(letter[3] == 2){
                    return 'G';          //--.
                }
                
                else if(letter[3] == 0){
                    if(letter[4] == 2){
                        return 'Z';          //--..
                    }
                    
                    else if(letter[4] == 0){
                        if(letter[5] == 2){
                            return '7';          //--...
                        }
                        
//                        else if(letter[5] == 0){
//                            return '';          //--....
//                        }
//                        
//                        else if(letter[5] == 1){
//                            return '';          //--...-
//                        }
                    }
                    
                    else if(letter[4] == 1){
//                        if(letter[5] == 2){
//                            return '';          //--..-
//                        }
//                        
//                        else if(letter[5] == 0){
//                            return '';          //--..-.
//                        }
                        
                        if(letter[5] == 1){
                            return ',';          //--..--
                        }
                    }
                    
                }
                
                else if(letter[3] == 1){
                    if(letter[4] == 2){
                        return 'Q';          //--.-
                    }
                    
//                    else if(letter[4] == 0){
//                        if(letter[5] == 2){
//                            return '';          //--.-.
//                        }
//                        
//                        else if(letter[5] == 0){
//                            return '';          //--.-..
//                        }
//                        
//                        else if(letter[5] == 1){
//                            return '';          //--.-.-
//                        }
//                    }
//                    
//                    else if(letter[4] == 1){
//                        if(letter[5] == 2){
//                            return '';          //--.--
//                        }
//                        
//                        else if(letter[5] == 0){
//                            return '';          //--.--.
//                        }
//                        
//                        else if(letter[5] == 1){
//                            return '';          //--.---
//                        }
//                    }
                    
                }
            
            }
            
            else if(letter[2] == 1){
                if(letter[3] == 2){
                    return 'O';          //---
                }
                
                else if(letter[3] == 0){
//                    if(letter[4] == 2){
//                        return '';          //---.
//                    }
                    
                    if(letter[4] == 0){
                        if(letter[5] == 2){
                            return '8';          //---..
                        }
                        
                        else if(letter[5] == 0){
                            return ':';          //---...
                        }
                        
//                        else if(letter[5] == 1){
//                            return '';          //---..-
//                        }
                    }
                    
//                    else if(letter[4] == 1){
//                        if(letter[5] == 2){
//                            return '';          //---.-
//                        }
//                        
//                        else if(letter[5] == 0){
//                            return '';          //---.-.
//                        }
//                        
//                        else if(letter[5] == 1){
//                            return '';          //---.--
//                        }
//                    }
                    
                }
                
                else if(letter[3] == 1){
//                    if(letter[4] == 2){
//                        return '';          //----
//                    }
                    
                    if(letter[4] == 0){
                        if(letter[5] == 2){
                            return '9';          //----.
                        }
                        
//                        else if(letter[5] == 0){
//                            return '';          //----..
//                        }
//                        
//                        else if(letter[5] == 1){
//                            return '';          //----.-
//                        }
                    }
                    
                    else if(letter[4] == 1){
                        if(letter[5] == 2){
                            return '0';          //-----
                        }
                        
//                        else if(letter[5] == 0){
//                            return '';          //-----.
//                        }
//                        
//                        else if(letter[5] == 1){
//                            return '';          //------
//                        }
                    }
                }
            }
        }
    }
    
  
    

//    if (!strcmp(s, "01NNNN")){
//            return 'A';
//        }
//        else if (!strcmp(s, "1000NN")){
//            return 'B';
//        }
//        else if (!strcmp(s, "1010NN")){
//            return 'C';
//        }
//        else if (!strcmp(s, "100NNN")){
//            return 'D';
//        }
//        else if (!strcmp(s, "0NNNNN")){
//            return 'E';
//        }
//        else if (!strcmp(s, "0010NN")){
//            return 'F';
//        }
//        else if (!strcmp(s, "110NNN")){
//            return 'G';
//        }
//        else if (!strcmp(s, "0000NN")){
//            return 'H';
//        }
//        else if (!strcmp(s, "00NNNN")){
//            return 'I';
//        }
//        else if (!strcmp(s, "0111NN")){
//            return 'J';
//        }
//        else if (!strcmp(s, "101NNN")){
//            return 'K';
//        }
//        else if (!strcmp(s, "0100NN")){
//            return 'L';
//        }
//        else if (!strcmp(s, "11NNNN")){
//            return 'M';
//        }
//        else if (!strcmp(s, "10NNNN")){
//            return 'N';
//        }
//        else if (!strcmp(s, "111NNN")){
//            return 'O';
//        }
//        else if (!strcmp(s, "0110NN")){
//            return 'P';
//        }
//        else if (!strcmp(s, "1101NN")){
//            return 'Q';
//        }
//        else if (!strcmp(s, "010NNN")){
//            return 'R';
//        }
//        else if (!strcmp(s, "000NNN")){
//            return 'S';
//        }
//        else if (!strcmp(s, "1NNNNN")){
//            return 'T';
//        }
//        else if (!strcmp(s, "001NNN")){
//            return 'U';
//        }
//        else if (!strcmp(s, "0001NN")){
//            return 'V';
//        }
//        else if (!strcmp(s, "011NNN")){
//            return 'W';
//        }
//        else if (!strcmp(s, "1001NN")){
//            return 'X';
//        }
//        else if (!strcmp(s, "1011NN")){
//            return 'Y';
//        }
//        else if (!strcmp(s, "1100NN")){
//            return 'Z';
//        }
//        else if (!strcmp(s, "0111NN")){
//            return '1';
//        }
//        else if (!strcmp(s, "00111N")){
//            return '2';
//        }
//        else if (!strcmp(s, "00011N")){
//            return '3';
//        }
//        else if (!strcmp(s, "00001N")){
//            return '4';
//        }
//        else if (!strcmp(s, "00000N")){
//            return '5';
//        }
//        else if (!strcmp(s, "10000N")){
//            return '6';
//        }
//        else if (!strcmp(s, "11000N")){
//            return '7';
//        }
//        else if (!strcmp(s, "11100N")){
//            return '8';
//        }
//        else if (!strcmp(s, "11110N")){
//            return '9';
//        }
//        else if (!strcmp(s, "11111N")){
//            return '0';
//        }
//        else if (!strcmp(s, "010101")){
//            return '.';
//        }
//        else if (!strcmp(s, "110011")){
//            return ',';
//        }
//        else if (!strcmp(s, "001100")){
//            return '?';
//        }
//        else{
//            return '#';
//        }
}