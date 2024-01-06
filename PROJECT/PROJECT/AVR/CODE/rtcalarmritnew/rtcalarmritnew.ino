/* ----- C Program for Arduino based Alarm Clock ---- */


#include <Wire.h>

#include<EEPROM.h>

#include <RTClib.h>

#include <LiquidCrystal.h>


LiquidCrystal lcd(7, 6, 5, 4, 3, 2); 

RTC_DS3231 RTC;

int temp,inc,hours1,minut,add=11;


#define buzzer 13
#define relay1 12
#define relay2 11
#define relay3 10
#define mois1 A0
#define mois2 A1
#define mois3 A2
#define mois4 A3

int HOUR,MINUT,SECOND;


int h=0;
int m=0;
int d=0; 

void setup()

{
Serial.begin(9600);
 Wire.begin();

 RTC.begin();

 lcd.begin(16,2);

pinMode(buzzer, OUTPUT);
pinMode(relay1, OUTPUT);
pinMode(relay2, OUTPUT);
pinMode(relay3, OUTPUT);
pinMode(mois1, INPUT);
pinMode(mois2, INPUT);
pinMode(mois3, INPUT);
pinMode(mois4, INPUT);

   lcd.setCursor(0,0);

   lcd.print("Real Time Clock");

   lcd.setCursor(0,1);

   lcd.print("Circuit Digest ");

    delay(2000);

   // RTC.adjust(DateTime(F(__DATE__),F(__TIME__)));

// if(!RTC.isrunning())

 //{

 //RTC.adjust(DateTime(__DATE__,__TIME__));

// }

}

 

void loop()

{
  checkmois();

   int temp=0,val=1,temp4;

   DateTime now = RTC.now();

   lcd.clear();

 lcd.setCursor(0,0);

 lcd.print("Time:");

 lcd.setCursor(6,0);

 lcd.print(HOUR=now.hour(),DEC); 

// Serial.print(HOUR=now.hour(),DEC);

  Serial.print(HOUR); 
 lcd.print(":");
 Serial.print(":");

 lcd.print(MINUT=now.minute(),DEC);

// Serial.print(MINUT=now.minute(),DEC);


Serial.print(MINUT);
 lcd.print(":");
 Serial.print(":");

 lcd.print(SECOND=now.second(),DEC);

 Serial.print(SECOND=now.second(),DEC);

 Serial.println(" ");
 
 lcd.setCursor(0,1);

 lcd.print("Date: ");

 lcd.print(d=now.day(),DEC);

 //Serial.println(now.day(),DEC);

 
 Serial.println(d);
 lcd.print("/");

 lcd.print(now.month(),DEC);

 lcd.print("/");

 lcd.print(now.year(),DEC);

 match();

 delay(200);

}



/*Function to set alarm time and feed time into Internal eeprom*/


/* Function to chack medication time */


void match()

{

  if((HOUR == 16) && (MINUT == 00) && (d == 1) )
  {
  motoron();
}
if((HOUR == 16) && (MINUT == 00) && (d == 3) )
  {
  motoron();
}
if((HOUR == 16) && (MINUT == 00) && (d == 5) )
  {
  motoron();
}
if((HOUR == 16) && (MINUT == 00) && (d == 7) )
  {
  motoron();
}
if((HOUR == 16) && (MINUT == 00) && (d == 10) )
  {
  motoron();
}
if((HOUR == 16) && (MINUT == 00) && (d == 11) )
  {
  motoron();
}
if((HOUR == 16) && (MINUT == 00) && (d == 13) )
  {
  motoron();
}
if((HOUR == 16) && (MINUT == 00) && (d == 14) )
  {
  motoron();
}
if((HOUR == 16) && (MINUT == 00) && (d == 16) )
  {
  motoron();
}
if((HOUR == 16) && (MINUT == 00) && (d == 17) )
  {
  motoron();
}
if((HOUR == 16) && (MINUT == 00) && (d == 20) )
  {
  motoron();
}
if((HOUR == 16) && (MINUT == 00) && (d == 21) )
  {
  motoron();
}
if((HOUR == 16) && (MINUT == 00) && (d == 24) )
  {
  motoron();
}
if((HOUR == 16) && (MINUT == 00) && (d == 25) )
  {
  motoron();
}
if((HOUR == 16) && (MINUT == 00) && (d == 28) )
  {
  motoron();
}
if((HOUR == 16) && (MINUT == 00) && (d == 30) )
  {
  motoron();
}
}
void motoron(){
Serial.print("alarm on");
   beep();
  }



/* function to buzzer indication */


void beep()

{

   digitalWrite(buzzer,HIGH);
   digitalWrite(relay1,HIGH);
   digitalWrite(relay2,HIGH);
   digitalWrite(relay3,HIGH);
  // delay(60000);
    checkmois();
    delay(5000);
    checkmois();
    delay(5000);
    checkmois();
    delay(5000);
    checkmois();
    delay(5000);
    checkmois();
    delay(5000);
    checkmois();
    delay(5000);
    checkmois();
    delay(5000);
    checkmois();
    delay(5000);
    checkmois();
    delay(5000);
    checkmois();
    delay(5000);
    checkmois();
    delay(5000);
    checkmois();
    delay(5000);
  digitalWrite(buzzer, LOW);
  digitalWrite(relay1, LOW); 
  digitalWrite(relay2, LOW); 
  digitalWrite(relay3, LOW); 
   delay(500);

}

void checkmois(){
int key1= digitalRead(mois1);
int key2= digitalRead(mois2);
int key3= digitalRead(mois3);
int key4= digitalRead(mois4);

if (key1==LOW){
  
  digitalWrite(relay1, LOW); 

}
if (key2==LOW){
  
  digitalWrite(relay2, LOW); 

}

if (key3==LOW){
  
  digitalWrite(relay3, LOW); 

}

if (key4==LOW){
  
  digitalWrite(buzzer, LOW); 

}

}
