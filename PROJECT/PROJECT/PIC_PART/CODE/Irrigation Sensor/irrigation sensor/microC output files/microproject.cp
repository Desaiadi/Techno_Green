#line 1 "C:/Users/sifat/OneDrive/Desktop/microproject.c"
 sbit LCD_RS at RD0_bit;
 sbit LCD_EN at RD1_bit;
 sbit LCD_D4 at RD2_bit;
 sbit LCD_D5 at RD3_bit;
 sbit LCD_D6 at RD4_bit;
 sbit LCD_D7 at RD5_bit;
 sbit LCD_RS_Direction at TRISD0_bit;
 sbit LCD_EN_Direction at TRISD1_bit;
 sbit LCD_D4_Direction at TRISD2_bit;
 sbit LCD_D5_Direction at TRISD3_bit;
 sbit LCD_D6_Direction at TRISD4_bit;
 sbit LCD_D7_Direction at TRISD5_bit;


 double source=0;
 double temp=0;
 int view=0;
 char txt[6];

 void main()

 {

 TRISC = 0x00;
 PORTC = 0x00;
 ADC_Init();
 Lcd_Init();
 Lcd_Cmd(_LCD_CLEAR);
 Lcd_Cmd(_LCD_CURSOR_OFF);


 Lcd_Out(1, 1, "    Irrigation ");
 Lcd_Out(2, 1, "    system");
 delay_ms(2000);
 Lcd_Cmd(_LCD_CLEAR);
 Lcd_Out(1, 1, "    Automation ");
 Lcd_Out(2, 1, "    system");
 delay_ms(2000);
 Lcd_Cmd(_LCD_CLEAR);
 Lcd_Out(1, 1, "  SOIL MOISTURE ");
 Lcd_Out(2, 1, " automation");
 delay_ms(2000);
 Lcd_Cmd(_LCD_CLEAR);

 while(1)
 {
 source=Adc_Read(1);

 if(source>600)
 {
 PORTC = 0b11111101;
 delay_ms(500);
 Lcd_Cmd(_LCD_CLEAR);
 Lcd_Out(1,5, "Dry Soil");
 Lcd_Out(2,5, "Motor On");
 }

 if(source<=600)
 {
 PORTC = 0b00000000;
 delay_ms(500);
 Lcd_Cmd(_LCD_CLEAR);
 Lcd_Out(1,5, "Humid Soil");
 Lcd_Out(2,5, "Motor OFF");
 }
 }

 }
