/* 
 * File:   LCD_Lib.h
 * Author: jacks
 *
 * Created on April 22, 2022, 2:10 PM
 */

#ifndef LCD_LIB_H
#define	LCD_LIB_H

#ifdef	__cplusplus
extern "C" {
#endif

    void lcd_cmd(char Package);
    void lcd_init(void);
    void lcd_printChar(char Package);
    void lcd_printStr(const char s[], int length);
    void lcd_setCursor(char x, char y);
    void lcd_printWrappedStr(const char s[], int length);
    char int_to_char(int num);
    void print_binary_code_to_lcd(void);


#ifdef	__cplusplus
}
#endif

#endif	/* LCD_LIB_H */

