#include <xc.h>
#define _XTAL_FREQ 20000000
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

void main() 
{
    TRISB=0X00;
    PORTB=0X00;
    TRISB0=1;
    TRISB1=1;
    TRISB2=0;
    TRISB3=0;
    TRISB4=0;
    TRISB5=0;
    unsigned int a;
    while(1)
    {
     if(RB0==1)
     {
         a++;
         __delay_ms(500);
     }
     if(RB1==1)
     {
         if(a!=0)
         {
             a--;
             __delay_ms(500);
         }
     }
     if((a>=1)&&(a<3))
     {
         RB2=1;
         __delay_ms(1000);
     }
     else if((a>=3)&&(a<5))
     {
         RB3=1;
         __delay_ms(1000);
     }
     else
     {
         RB2=0;
         RB3=0;
     }
    }
}
