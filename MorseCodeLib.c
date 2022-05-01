#include "xc.h"
#include "MorseCodeLib.h"
#include "string.h"

extern int letter[6];

char morseCodeLib(void) {
    // Given an binary encoded morse character, this function will
    // return the associated character
    // This library handles A-Z, 0-9, and ?!.,;:+-/=
    
    // Logic blocks commented out represent possible morse code combinations
 
    
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
                            return ' ';          //-....-
                        }
                    }
                    
                    else if(letter[4] == 1){
                        if(letter[5] == 2){
                            return '\n';          //-...-
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
    
}