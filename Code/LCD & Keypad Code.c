/*
 * LCD & Keypad Code.c
 *
 * Created: 12/21/2023 4:12:22 PM
 * Author: Yousry Essam
 */
#include <mega16.h>
#include <alcd.h>
char keyPad();
void LCD_KEYPAD_START();

void main(void)
{
       int liters = 0 ;
       char num ;
       LCD_KEYPAD_START();
       while (1)
       {
              num = keyPad()  ;     
              if(liters == 32){
                     liters = 0 ;
                     lcd_clear();
              }
              lcd_printf("%c" , num);
              liters = liters + 1 ;
       }
}
                 
void LCD_KEYPAD_START(){
       // Set KeyPad port ;
       DDRB  = 0b00000111;
       PORTB = 0b11111000; 
       // Initiate LCD 
       lcd_init(16);   
}
char keyPad(){
      while(1){     
            // C1 
            PORTB.0 = 0; PORTB.1 = 1; PORTB.2 = 1;
            //Only C1 is activated
            switch(PINB){
                case 0b11110110:
                while (PINB.3 == 0);
                return '1';
                break;
                
                case 0b11101110:
                while (PINB.4 == 0);
                return '4';
                break;
                
                case 0b11011110:
                while (PINB.5 == 0);
                return '7';
                break;
                
                case 0b10111110:
                while (PINB.6 == 0);
                return '*';
                break;
                
            }
            
            // C2
            PORTB.0 = 1; PORTB.1 = 0; PORTB.2 = 1;   
            //Only C2 is activated
            switch(PINB){
                case 0b11110101:
                while (PINB.3 == 0);
                return '2';
                break;
                
                case 0b11101101:
                while (PINB.4 == 0);
                return '5';
                break;
                
                case 0b11011101:
                while (PINB.5 == 0);
                return '8';
                break;
                
                case 0b10111101:
                while (PINB.6 == 0);
                return '0';
                break;
            }

            // C3
            PORTB.0 = 1; PORTB.1 = 1; PORTB.2 = 0;
            //Only C3 is activated
            switch(PINB){    
            
                case 0b11110011:
                while (PINB.3 == 0);
                return '3';
                break;
                
                case 0b11101011:
                while (PINB.4 == 0);
                return '6';
                break;
                
                case 0b11011011:
                while (PINB.5 == 0);
                return '9';
                break;
                
                case 0b10111011:
                while (PINB.6 == 0);
                return '#';
                break;
                
            }  
        
        }
}
