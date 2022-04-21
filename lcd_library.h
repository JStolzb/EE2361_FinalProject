/* 
 * File:   stolz050_lab5_lcdFuncs_v001.h
 * Author: johns
 *
 * Created on April 11, 2022, 11:40 AM
 */

#ifndef LCD_LIBRARY_H
#define	LCD_LIBRARY_H

#include <xc.h>

#ifdef	__cplusplus
extern "C" {
#endif
    void lcd_cmd(char Package);
    void lcd_init(void);
    void lcd_printChar(char Package);
    void lcd_printStr(const char s[], int length);
    void lcd_setCursor(char x, char y);
    void lcd_printWrappedStr(const char s[], int length);


#ifdef	__cplusplus
}
#endif

#endif

