#line 1 "D:/Downloads/TULIP FARMS/moisture/MyProject.c"

sbit LCD_RS at RC0_bit;
sbit LCD_EN at RC1_bit;
sbit LCD_D4 at RC2_bit;
sbit LCD_D5 at RC3_bit;
sbit LCD_D6 at RC4_bit;
sbit LCD_D7 at RC5_bit;

sbit LCD_RS_Direction at TRISC0_bit;
sbit LCD_EN_Direction at TRISC1_bit;
sbit LCD_D4_Direction at TRISC2_bit;
sbit LCD_D5_Direction at TRISC3_bit;
sbit LCD_D6_Direction at TRISC4_bit;
sbit LCD_D7_Direction at TRISD5_bit;



float moisture_value;
char text[10];
void main(void)
{

ADC_Init();
Lcd_Init();
Lcd_Cmd(_LCD_CLEAR);
Lcd_Cmd(_LCD_CURSOR_OFF);
Lcd_Out(1,1,"Moistue sensor" );

while(1)
{

moisture_value = ADC_Read(0);
moisture_value = ( moisture_value * 100) / (1023);
FloatToStr(moisture_value, Ltrim(text));
Lcd_Out(2,1, text );
Lcd_Out_cp("%");

}
}
