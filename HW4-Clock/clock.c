// Global Variables

const unsigned char MSG0[20] = "Stopwatch   HW4 ";

// Subroutine Declarations
#include <pic18.h>

// Subroutines
#include        "LCD_PortD.c"
void Wait(unsigned int X)
{
	unsigned int i,j;
	for(i=0; i<X; i++)
		for(j=0;j<62;j++);
}


// Main Routine

void main(void)
{
   	unsigned int HR, MIN, SEC;
	unsigned int i;

   	TRISA = 0;
   	TRISB = 0xFF;
   	TRISC = 0;
   	TRISD = 0;
   	TRISE = 0;
	PORTA = 0;
	PORTB = 0;
	PORTC = 0;
	PORTD = 0;
	PORTE = 0;
	HR = 0;
	MIN = 0;
	SEC = 0;
   	ADCON1 = 0x0F;

   	LCD_Init();                  // initialize the LCD
	Wait_ms(10);
   	LCD_Move(0,0);  for (i=0; i<20; i++) LCD_Write(MSG0[i]); 
 
	while(RB1==1){
	while(1){
		SEC = SEC + 1;
		if (SEC >= 600){
			MIN = MIN + 1;
			SEC = 0;
			if(MIN >= 600){
				HR = HR + 1;
				MIN = 0;
			}
		}
		LCD_Move(1,0); LCD_Out(HR,2,0);
		LCD_Write(':');
		LCD_Out(MIN,2,0);
		LCD_Write(':');
		LCD_Out(SEC,3,1);
		Wait_ms(185);
		if(RB2==1){
			SEC = 0;
			MIN = 0;
			HR = 0;
		}
		if(RB0==1){
			exit(0);
		}
			
	}
	}
}