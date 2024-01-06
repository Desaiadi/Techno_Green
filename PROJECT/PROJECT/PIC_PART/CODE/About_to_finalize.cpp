
#include <pic.h>

#define _XTAL_FREQ 20000000
#define LCD PORTD
#define RS RB0
#define RW RB1
#define EN RB2

// rtc macros for ds1307

#define DS1307_address 0xD0

#define second 0x00
#define minute 0x01
#define hour 0x02
#define day 0x03
#define date 0x04
#define month 0x05
#define year 0x06
#define control_reg 0x07

void DS1307_write(char sec, char min, char hr, char _day, char _date, char _month, char _year);
void DS1307_read(char slave_address,char register_address) ;
char decimal_to_bcd(unsigned char value);
void bcd_to_ascii(unsigned char value);

void delay(unsigned int Delay);
void lcd_cmd(unsigned char cmd);
void lcd_data(unsigned char data);
void lcd_Init();
void lcd_word(const unsigned char *words);


unsigned char __sec, __min, __hr, __day, __date, __month, __yr, __con;
void main(void)
{
TRISC = 0XFF;
SSPCON = 0x28;
SSPADD = 49;

TRISB=TRISD=0X00;
PORTB=PORTD=0X00;
lcd_Init();

lcd_cmd(0x80);
lcd_word(" CLOCK : ");
lcd_cmd(0xC0);
lcd_word(" DATE : ");
DS1307_write ( 0 , 59 , 2 , 1 , 26 , 12 , 19 )
__delay_ms(300);


while(1)
{  
__delay_ms(20);
DS1307_read(DS1307_address,0x00);


}


}

//void DS1307_write( char _second , char _minute , char _hour , char _day , char _date , char _month , char _year )
void DS1307_write( char _second , char _minute , char _hour , char _day , char _date , char _month , char _year )
{
/* Start bit */
SEN = 1 ;           // initiate start condition
while(SEN);     // wait for start condition to complete
SSPIF = 0 ;         // clear SSPIF flag
/* slave address bits */
        
SSPBUF = DS1307_address;   // send the slave address high and r / w = 0 for write
while(!SSPIF); // wait for acknowledge SSPIF is set for every 9th clock cycle             
SSPIF=0;         // clear SSPIF flag

if(ACKSTAT)
{
PEN = 1;       // initiate stop condition
while(PEN); // wait for stop condition to complete
return ;        // exit write ( no acknowledgment )
}

SSPBUF = second ;
while(!SSPIF);
SSPIF = 0;
if(ACKSTAT)
{
PEN = 1;        // initiate stop condition
while(PEN);     // wait for stop condition to complete
return ;        // exit write ( no acknowledgment )
}

SSPBUF = decimal_to_bcd(_second) ;
while(!SSPIF);
SSPIF = 0;

SSPBUF = decimal_to_bcd(_minute);
while(!SSPIF);
SSPIF = 0 ;

SSPBUF = decimal_to_bcd(_hour);
while(!SSPIF);
SSPIF = 0 ;

SSPBUF = decimal_to_bcd(_day);
while(!SSPIF);
SSPIF = 0 ;

SSPBUF = decimal_to_bcd(_date);
while(!SSPIF);
SSPIF = 0 ;

SSPBUF = decimal_to_bcd( _month );
while (!SSPIF);
PIR1bits.SSPIF = 0;

SSPBUF = decimal_to_bcd( _year );
while(!SSPIF);
SSPIF = 0;

SSPBUF = 0x00;
while (!SSPIF);
SSPIF = 0;

/* ---------------- */

PEN = 1;
while(PEN);
}

void DS1307_read(char slave_address,char register_address)
{
/* start bit */
// initiate start condition
SEN = 1;
while(SEN) ;// wait for start condition to complete  
SSPIF = 0;// clear SSPIF flag
/* slave address bits */
SSPBUF = slave_address;
while(!SSPIF);
SSPIF = 0;
if(ACKSTAT)
    { 
    PEN = 1; // initiate stop condition
    while(PEN);
    return;
    }
/* slave address bits */
SSPBUF = register_address;
while(!SSPIF);
SSPIF = 0;
if(ACKSTAT)
    {
    PEN = 1; // initiate stop condition
    while(PEN);
    return;
    }

RSEN = 1; // initiate start condition
while(RSEN); // wait for start condition to complete
SSPIF = 0;// clear SSPIF flag
/* slave address bits */

SSPBUF = (slave_address + 1); // send the slave address high and r / w = 1 bit
while(!SSPIF);
SSPIF = 0;
if(ACKSTAT)
    { 
    PEN = 1; // initiate stop condition
    while(PEN);
    return;
    }
 
/* Receive enable bit */
RCEN = 1;
while(!BF);
__sec = SSPBUF;


ACKDT = 0;
ACKEN = 1;
while(ACKEN);

 /* recive Enable bit */
RCEN = 1;
while(!BF);
__min = SSPBUF;


ACKDT = 0;
ACKEN = 1;
while(ACKEN);


/*recive Enable bit */
RCEN = 1;
while(!BF);
__hr = SSPBUF;


ACKDT = 0;
ACKEN = 1;
while(ACKEN);

/*recive Enable bit */
RCEN = 1;
while(!BF);
__day = SSPBUF;


ACKDT = 0;
ACKEN = 1;
while(ACKEN);

/*recive Enable bit */
RCEN = 1;
while(!BF);
__date = SSPBUF;


ACKDT = 0;
ACKEN = 1;
while(ACKEN);


/*recive Enable bit */
RCEN = 1;
while(!BF);
__month = SSPBUF;


ACKDT = 0;
ACKEN = 1;
while(ACKEN);

/*recive Enable bit */
RCEN = 1;
while(!BF);
__yr = SSPBUF;


ACKDT = 0;
ACKEN = 1;
while(ACKEN);

/*recive Enable bit */
RCEN = 1;
while(!BF);
__con = SSPBUF;

ACKDT = 1;
ACKEN = 1;
while(ACKEN);

/* stops bits */
PEN = 1;
while(PEN);

        lcd_cmd(0x88);
        bcd_to_ascii(__hr);
        lcd_data(':');
        bcd_to_ascii( __min);
        lcd_data(':');
        bcd_to_ascii(__sec);

        lcd_cmd(0xC8);
        bcd_to_ascii(__date);
        lcd_data('/');
        bcd_to_ascii (__month);
        lcd_data('/');
        bcd_to_ascii(__yr);

        
}

void delay(unsigned int Delay)
{
    
}

char decimal_to_bcd(unsigned char value)
{
unsigned char msb,lsb,hex;
msb = value/10 ;
Isb = value%10 ;
hex = ((msb<<4)+lsb);
return hex ;
}

void bcd_to_ascii(unsigned char value)
{
unsigned char bcd;
bcd = value;
bcd = bcd&0xf0;
bcd = bcd>>4 ;
bcd = bcd|0x30;
lcd_data(bcd);
bcd = value;
bcd = bcd&0x0f;
bcd = bcd|0x30;
lcd_data(bcd);

}

void lcd_data (unsigned char data)
{
PORTD = data ;
RS = 1 ;
RW = 0 ;
EN = 1 ;
_delay_ms(5);
EN = 0 ;
}

void lcd_command (unsigned char command)
{
PORTD = command;
RS = 0 ;
RW = 0 ;
EN = 1 ;
_delay_ms (5);
EN = 0 ;
}

