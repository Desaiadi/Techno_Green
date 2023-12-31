
//LCD module connections
#define LCD_RS_PIN      PIN_D0
#define LCD_RW_PIN      PIN_D1
#define LCD_ENABLE_PIN  PIN_D2
#define LCD_DATA4       PIN_D3
#define LCD_DATA5       PIN_D4
#define LCD_DATA6       PIN_D5
#define LCD_DATA7       PIN_D6
//End LCD module connections

#include <16F877A.h>
#fuses HS,NOWDT,NOPROTECT,NOLVP                       
#use delay(clock = 8MHz)
#use fast_io(D)
#include <lcd.c>
#use I2C(master, I2C1, FAST = 100000)

char time[]     = "TIME:  :  :  ";
char calendar[] = "DATE:  /  /20  ";
int8  i, second, minute, hour, date, month, year;
void DS3231_display(){
  // Convert BCD to decimal
  second = (second >> 4) * 10 + (second & 0x0F);
  minute = (minute >> 4) * 10 + (minute & 0x0F);
  hour = (hour >> 4) * 10 + (hour & 0x0F);
  date = (date >> 4) * 10 + (date & 0x0F);
  month = (month >> 4) * 10 + (month & 0x0F);
  year = (year >> 4) * 10 + (year & 0x0F);
  // End conversion
  time[12]     = second % 10  + 48;
  time[11]     = second / 10  + 48;
  time[9]      = minute % 10  + 48;
  time[8]      = minute / 10  + 48;
  time[6]      = hour % 10  + 48;
  time[5]      = hour / 10  + 48;
  calendar[14] = year % 10 + 48;
  calendar[13] = year / 10  + 48;
  calendar[9]  = month % 10 + 48;
  calendar[8]  = month / 10 + 48;
  calendar[6]  = date % 10 + 48;
  calendar[5]  = date / 10 + 48;
  lcd_gotoxy(1, 1);                              // Go to column 1 row 1
  printf(lcd_putc, time);                        // Display time
  lcd_gotoxy(1, 2);                              // Go to column 1 row 2
  printf(lcd_putc, calendar);                    // Display calendar
}
void blink(){
  int8 j = 0;
  while(j < 10 && input(PIN_B0) && input(PIN_B1)){
    j++;
    delay_ms(25);
  }
}
unsigned int8 edit(parameter, xx, yy){
  while(!input(PIN_B0));                         // Wait until button RB0 is released
  while(TRUE){
    while(!input(PIN_B1)){                       // If button RB1 is pressed
      parameter++;
      if(i == 0 && parameter > 23)               // If hours > 23 ==> hours = 0
        parameter = 0;
      if(i == 1 && parameter > 59)               // If minutes > 59 ==> minutes = 0
        parameter = 0;
      if(i == 2 && parameter > 31)               // If date > 31 ==> date = 1
        parameter = 1;
      if(i == 3 && parameter > 12)               // If month > 12 ==> month = 1
        parameter = 1;
      if(i == 4 && parameter > 99)               // If year > 99 ==> year = 0
        parameter = 0;
      lcd_gotoxy(xx, yy);
      printf(lcd_putc,"%02u", parameter);        // Display parameter
      delay_ms(200);                             // Wait 200ms
    }
    lcd_gotoxy(xx, yy);
    lcd_putc("  ");
    blink();
    lcd_gotoxy(xx, yy);                          // Display two spaces
    printf(lcd_putc,"%02u", parameter);          // Display parameter
    blink();
    if(!input(PIN_B0)){                          // If button RB0 is pressed
      i++;                                       // Increament 'i' for the next parameter
      return parameter;                          // Return parameter value and exit
    }
  }
}
void main(){
  set_tris_d(0);
  port_b_pullups(TRUE);                          // Enable PORTB internal pull-ups
  lcd_init();                                    // Initialize LCD module
  lcd_putc('\f');                                // LCD clear
  while(TRUE){
    if(!input(PIN_B0)){                          // If RB0 button is pressed
      i = 0;
      hour = edit(hour, 6, 1);
      minute = edit(minute, 9, 1);
      date = edit(date, 6, 2);
      month = edit(month, 9, 2);
      year = edit(year, 14, 2);
      // Convert decimal to BCD
      minute = ((minute / 10) << 4) + (minute % 10);
      hour = ((hour / 10) << 4) + (hour % 10);
      date = ((date / 10) << 4) + (date % 10);
      month = ((month / 10) << 4) + (month % 10);
      year = ((year / 10) << 4) + (year % 10);
      // End conversion
      // Write data to DS3231 RTC
      i2c_start();                               // Start I2C protocol
      i2c_write(0xD0);                           // DS3231 address
      i2c_write(0);
      i2c_write(0);                              // Reset sesonds and start oscillator
      i2c_write(minute);                         // Write minute value to DS3231
      i2c_write(hour);                           // Write hour value to DS3231
      i2c_write(1);                              // Write day value (not used)
      i2c_write(date);                           // Write date value to DS3231
      i2c_write(month);                          // Write month value to DS3231
      i2c_write(year);                           // Write year value to DS3231
      delay_ms(200);                             // Wait 200ms
    }
    i2c_start();                                  // Start I2C protocol
    i2c_write(0xD0);                              // DS3231 address
    i2c_write(0);                                 // Send register address
    i2c_start();                                  // Restart I2C
    i2c_write(0xD1);                              // Initialize data read
    second = i2c_read(1);                         // Read seconds from register 0
    minute = i2c_read(1);                         // Read minuts from register 1
    hour   = i2c_read(1);                         // Read hour from register 2
    i2c_read(1);                                  // Read day from register 3 (not used)
    date   = i2c_read(1);                         // Read date from register 4
    month  = i2c_read(1);                         // Read month from register 5
    year   = i2c_read(0);                         // Read year from register 6
    i2c_stop();                                   // Stop I2C protocol
    DS3231_display();                             // Diaplay time & calendar
    delay_ms(50);
  }
}
