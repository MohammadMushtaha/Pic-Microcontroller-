// LCD module connections
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
// End LCD module connections



char i[5];                              // Loop variable
char J[5];
int heartbeat_count = 0;
int T1 = 0;                   // for timer


void interrupt () {
if (INTF_bit)   {
  heartbeat_count++ ;
  Delay_ms(300);
  INTF_bit =0 ;
  }

}
void Move_Delay() {                  // Function used for text moving
  Delay_ms(500);                     // You can change the moving speed here
}

void main(){
  TRISD=0;         // SET THE DIRECTION OF PORTD AS OUTPUT
  TRISB0_bit =1;   // Set RB0 as input (heartbeat sensor)
  INTCON = 0XD0 ;         //SET THE INTERUPT REGISTER
  OPTION_REG.INTEDG = 0;    // INT OCCURE ON FALLING EDGE
  INTEDG_bit = 0;
  Lcd_Init();                        // Initialize LCD

  Lcd_Cmd(_LCD_CLEAR);               // Clear display
  Lcd_Cmd(_LCD_CURSOR_OFF);          // Cursor off




   Lcd_Cmd(_LCD_CLEAR);               // Clear display
  while(1) {
       T1++ ;
       Lcd_Cmd(_LCD_CLEAR);
       Lcd_Cmd(_LCD_CURSOR_OFF);
       Lcd_Out(1,1,"H.B :");
       IntToStr(heartbeat_count, i); // covert int to string for LCD display
       Lcd_Out(1,7,i);
       IntToStr(T1, J);   //covert T1 from int to string
       Lcd_Out(2,1,"TIMER:");
       Lcd_Out(2,7,J);
       delay_ms(1000); // Update every second
      if (T1 >= 60) {
      delay_ms(5000); // Update every second                         // Has 1ms elapsed?
      T1 = 0;
      heartbeat_count=0;                          // Clear the counter                              // Increment msec on every 1 ms
      }

      if ((heartbeat_count <= 100) && (heartbeat_count >= 62)){          //ALARM
      PORTD=255;
      delay_ms(500); // DELAY 3S
      PORTD=0;
      delay_ms(500); // DELAY 3S
      PORTD=255;
      delay_ms(500); // DELAY 3S
      PORTD=0;
      delay_ms(500); // DELAY 3S
      PORTD=255;
      delay_ms(500); // DELAY 3S
      PORTD=0;
      delay_ms(500); // DELAY 3S
      PORTD=255;
      delay_ms(500); // DELAY 3S
      PORTD=0;
      heartbeat_count=0; 
      T1 = 0;                       // Has 1ms elapsed?
      PORTD=0;
                    // Clear the counter                              // Increment msec on every 1 ms
      }
       }

}