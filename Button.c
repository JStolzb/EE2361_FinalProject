// hello world
#include "xc.h"
#include "string.h"
#include "Button.h"

extern unsigned long int overflow;
extern unsigned long int curPeriod, validClick, prevEdge;
extern int numClick, isValidClick;

int letter[6];
int i;

void buttonWatch(void) {
    overflow = 0;
    curPeriod = 0;
    validClick = 0;
    prevEdge = 0;
    numClick = 0;
    isValidClick = 0;
    int isFirstEdge = 1;
    unsigned long int tempPeriod = 0, curEdge = 0;
    
    for(i=0; i < 6; i++){
        letter[i] = 2;
    }
    
    i = 0;
    
    while(1) {
        if (isValidClick == 1) {
            isValidClick = 0;
            curEdge = (unsigned long int) (PR2 + 1 )*overflow + TMR2;
            curPeriod = curEdge - validClick; //update global var if greater than 2ms
//            validClick = curEdge;
            numClick++;
            if (isFirstEdge == 1) {
                isFirstEdge = 0;
            }
            else {
                if (curPeriod < 44000) { //if less than 1 s
                    //short click
                    //lcd_printChar('0');
                    letter[i]  = 0;
                    isFirstEdge = 0;
                    i++;
                }
                else {
                    //long click
                    //lcd_printChar('1');
                    letter[i]  = 1;
                    isFirstEdge = 0;
                    i++;
                }
            }
            validClick = curEdge;
        }
        if ((unsigned long int)(PR2 + 1) * overflow + TMR2 - validClick > 125000 ) {
            //end of letter
            //lcd_printChar('N');
            overflow = 0;
            TMR2 = 0;
            i = 0;
            validClick = TMR2;
            prevEdge = TMR2;
            isValidClick = 0;
            isFirstEdge = 1;
            
            return;
        }
        
    }
}
