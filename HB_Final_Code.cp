#line 1 "C:/Users/Moham/OneDrive/Desktop/HB code/HB_Final_Code.c"

sbit LCD_RS at RB4_bit;
sbit LCD_EN at RB5_bit;
sbit LCD_D4 at RB6_bit;
sbit LCD_D5 at RB1_bit;
sbit LCD_D6 at RB2_bit;
sbit LCD_D7 at RB3_bit;

sbit LCD_RS_Direction at TRISB4_bit;
sbit LCD_EN_Direction at TRISB5_bit;
sbit LCD_D4_Direction at TRISB6_bit;
sbit LCD_D5_Direction at TRISB1_bit;
sbit LCD_D6_Direction at TRISB2_bit;
sbit LCD_D7_Direction at TRISB3_bit;




char i[5];
char J[5];
int heartbeat_count = 0;
int T1 = 0;


void interrupt () {
if (INTF_bit) {
 heartbeat_count++ ;
 Delay_ms(300);
 INTF_bit =0 ;
 }

}
void Move_Delay() {
 Delay_ms(500);
}

void main(){
 TRISD=0;
 TRISB0_bit =1;
 INTCON = 0XD0 ;
 OPTION_REG.INTEDG = 0;
 INTEDG_bit = 0;
 Lcd_Init();

 Lcd_Cmd(_LCD_CLEAR);
 Lcd_Cmd(_LCD_CURSOR_OFF);




 Lcd_Cmd(_LCD_CLEAR);
 while(1) {
 T1++ ;
 Lcd_Cmd(_LCD_CLEAR);
 Lcd_Cmd(_LCD_CURSOR_OFF);
 Lcd_Out(1,1,"H.B :");
 IntToStr(heartbeat_count, i);
 Lcd_Out(1,7,i);
 IntToStr(T1, J);
 Lcd_Out(2,1,"TIMER:");
 Lcd_Out(2,7,J);
 delay_ms(1000);
 if (T1 >= 60) {
 delay_ms(5000);
 T1 = 0;
 heartbeat_count=0;
 }

 if ((heartbeat_count <= 100) && (heartbeat_count >= 62)){
 PORTD=255;
 delay_ms(500);
 PORTD=0;
 delay_ms(500);
 PORTD=255;
 delay_ms(500);
 PORTD=0;
 delay_ms(500);
 PORTD=255;
 delay_ms(500);
 PORTD=0;
 delay_ms(500);
 PORTD=255;
 delay_ms(500);
 PORTD=0;
 heartbeat_count=0;
 T1 = 0;
 PORTD=0;

 }
 }

}
