#include <pic18.h>
#include "LCD_PortD.c"

void main(void){
	unsigned int i;
	
	TRISA = 0;
	TRISB = 0xFF;
	TRISC = 0;
	TRISD = 0;
	TRISE = 0;
	ADCON1 = 0x0F;
	
			LCD_Init();
			Wait_ms(10);

	while(1){
		while(RB0){
			const unsigned char MSG0[20] = "        D3       ";
			LCD_Move(0,0);  for (i=0; i<20; i++) LCD_Write(MSG0[i]);
			RC0 = !RC0;
			for(i=0;i<2126;i++);
		}
		while(RB1){
			const unsigned char MSG1[20] = "        G3       ";
			LCD_Move(0,0);  for (i=0; i<20; i++) LCD_Write(MSG1[i]);
			RC0 = !RC0;
			for(i=0;i<1592;i++);
		}
		while(RB2){
			const unsigned char MSG2[20] = "        B3       ";
			LCD_Move(0,0);  for (i=0; i<20; i++) LCD_Write(MSG2[i]);
			RC0 = !RC0;
			for(i=0;i<1264;i++);
		}
		while(RB3){
			const unsigned char MSG3[20] = "        E4       ";
			LCD_Move(0,0);  for (i=0; i<20; i++) LCD_Write(MSG3[i]);
			RC0 = !RC0;
			for(i=0;i<947;i++);
		}
	}
}