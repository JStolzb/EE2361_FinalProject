/*
 * File:   FinalProjectMain.c
 * Author: jacks
 *
 * Created on April 14, 2022, 1:02 PM
 */


#include "xc.h"

int dot = 0;
int dash = 1;
int dataBuffer[5];
int numClicks = 0;
char message;

void oneClick(void){
    if (dataBuffer[0] == dot){
        message = 'E';
    }
    else{
        message = 'T';
    }
}

void first_is_dot(void){
    if(numClicks == 2){
        if(dataBuffer[1] == dot){
            message = 'I';                                            //. .
        }
        else{
            message = 'A';                                            //. -
        }
    }
    else if(numClicks == 3){
        if(dataBuffer[1] == dot){
            if(dataBuffer[2] == dot){
                message = 'S';                                            //. . .
            }
            else{
                message = 'U';                                            //. . -
            }
        }
        else{
            if(dataBuffer[2] == dot){
                message = 'R';                                            //. - .    
            }
            else{
                message = 'W';                                            //. - -  
            }
        }
    }
    else if(numClicks == 4){
        if(dataBuffer[1] == dot){
            if(dataBuffer[2] == dot){
                if(dataBuffer[3] == dot){
                    message = 'H';                                       //. . . .
                }
                else{
                    message = 'V';                                       //. . . -
                }
            }
            else{
                if(dataBuffer[3] == dot){
                    message = 'F';                                       //. . - .
                }
                else{
                    message = '-';                                       //. . - -
                }
            }
        }
        else{
            if(dataBuffer[2] == dot){
               if(dataBuffer[3] == dot){
                    message = 'L';                                       //. - . .
                }
                else{
                    message = '!';                                       //. - . -
                }   
            }
            else{
                if(dataBuffer[3] == dot){
                    message = 'P';                                       //. - - .
                }
                else{
                    message = 'J';                                       //. - - -
                } 
            }
        }
    }
    else if(numClicks == 5){
        if(dataBuffer[1] == dot){
            if(dataBuffer[2] == dot){
                if(dataBuffer[3] == dot){
                    if(dataBuffer[4] == dot){
                        message = '5';                                       //. . . . .
                    }
                    else{
                        message = '4';                                       //. . . . -
                    }
                }
                else{
                    if(dataBuffer[4] == dash){
                        message = '3';                                       //. . . - -
                    }
                }
            }
            else{
                if(dataBuffer[3] == dot){
                    if(dataBuffer[4] == dash){
                        message = '2';                                       //. . - . -
                    }
                }
            }
        }
        else{
            if(dataBuffer[2] == dash){
                if(dataBuffer[3] == dash){
                    if(dataBuffer[4] == dash){
                        message = '1';                                       //. - - - -
                    }
                }
            }
        }
    }
}

void first_is_dash(void){
    if(numClicks == 2){
        if(dataBuffer[1] == dot){
            message = 'N';                                            //- .
        }
        else{
            message = 'M';                                            //- -
        }
    }
    else if(numClicks == 3){
        if(dataBuffer[1] == dot){
            if(dataBuffer[2] == dot){
                message = 'D';                                            //- . .
            }
            else{
                message = 'K';                                            //- . -
            }
        }
        else{
            if(dataBuffer[2] == dot){
                message = 'G';                                            //- - .    
            }
            else{
                message = 'O';                                            //- - -  
            }
        }
    }
    else if(numClicks == 4){
        if(dataBuffer[1] == dot){
            if(dataBuffer[2] == dot){
                if(dataBuffer[3] == dot){
                    message = 'B';                                       //- . . .
                }
                else{
                    message = 'X';                                       //- . . -
                }
            }
            else{
                if(dataBuffer[3] == dot){
                    message = 'C';                                       //- . - .
                }
                else{
                    message = 'Y';                                       //- . - -
                }
            }
        }
        else{
            if(dataBuffer[2] == dot){
               if(dataBuffer[3] == dot){
                    message = 'Z';                                       //- - . .
                }
                else{
                    message = 'Q';                                       //- - . -
                }   
            }
            else{
                if(dataBuffer[3] == dot){
                    message = '.';                                       //- - - .
                }
                else{
                    message = '?';                                       //- - - -
                } 
            }
        }
    }
    else if(numClicks == 5){
        if(dataBuffer[1] == dot){
            if(dataBuffer[2] == dot){
                if(dataBuffer[3] == dot){
                    if(dataBuffer[4] == dot){
                        message = '6';                                       //- . . . .
                    }
                }
            }
        }
        else{
            if(dataBuffer[2] == dot){
               if(dataBuffer[3] == dot){
                    if(dataBuffer[4] == dot){
                        message = '7';                                       //- - . . .
                    }  
                }
            }
            else{
                if(dataBuffer[3] == dot){
                    if(dataBuffer[4] == dot){
                        message = '8';                                       //- - - . .
                    }
                }
                else{
                    if(dataBuffer[4] == dot){
                        message = '9';                                       //- - - - .
                    }
                    else{
                        message = '0';                                       //- - - - -
                    }
                }
            }
        }
    }
}
    

int main(void) {
    
    if(numClicks == 1){
        oneClick();
    }
    else{
        if (dataBuffer[0] == dot){
            first_is_dot();
        }
        else{
            first_is_dash();
        }
    }
    
    return 0;
}
