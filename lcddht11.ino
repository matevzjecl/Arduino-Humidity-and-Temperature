#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#include <dht.h>

dht DHT;

#define DHT11_PIN 7

#define RedLed 2
#define BlueLed 3
#define WhiteLed 4
#define GreenLed 5

#define I2C_ADDR    0x27
#define BACKLIGHT_PIN     3
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7

int n = 1;

LiquidCrystal_I2C  lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);

void setup()
{
  pinMode(GreenLed, OUTPUT);
  pinMode(BlueLed, OUTPUT);
  pinMode(WhiteLed, OUTPUT);
  pinMode(RedLed, OUTPUT);
 lcd.begin (16,2); //  <<----- My LCD was 16x2
  Serial.begin(9600);
 
// Switch on the backlight
lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
lcd.setBacklight(HIGH);
lcd.home (); // go home

 
}

void loop()
{
 int chk = DHT.read11(DHT11_PIN);
 int temp = DHT.temperature;
 int hum = DHT.humidity;
 int range = 11;
 int numH = hum/range;
 int numT = temp/range;
  Serial.println(hum);

switch (numH) {
  case 0:
  analogWrite(WhiteLed,255);
  digitalWrite(GreenLed,LOW);
  break;
  case 1:
  analogWrite(WhiteLed,170);
  digitalWrite(GreenLed,LOW);
  break;
  case 2:
  analogWrite(WhiteLed,85);
  digitalWrite(GreenLed,LOW);
  break;
  case 3:
  analogWrite(GreenLed,85);
  digitalWrite(WhiteLed,LOW);
  break;
  case 4:
  analogWrite(GreenLed,255);
  digitalWrite(WhiteLed,LOW);
  break;
  case 5:
  analogWrite(GreenLed,255);
  digitalWrite(WhiteLed,LOW);
  break;
  case 6:
  analogWrite(GreenLed,170);
  digitalWrite(WhiteLed,LOW);
  break;
  case 7:
  analogWrite(GreenLed,85);
  digitalWrite(WhiteLed,LOW);
  break;
  case 8:
  analogWrite(GreenLed,85);
  digitalWrite(WhiteLed,LOW);
  break;
  case 9:
  analogWrite(GreenLed,85);
  digitalWrite(WhiteLed,LOW);
  break;

}

if(temp>20) {
  digitalWrite(RedLed,HIGH);
  digitalWrite(BlueLed,LOW);
}
else if(temp<20) {
  digitalWrite(BlueLed,HIGH);
  digitalWrite(RedLed,LOW);
}

 lcd.setCursor (0,0);       
 lcd.print("Temp. = ");
 lcd.print(temp);
 lcd.print(" ");
 lcd.print((char)223);
 lcd.print("C");
 lcd.setCursor (0,1);    
 lcd.print("Vlaga = ");
 lcd.print(hum);
 lcd.print(" %");
 delay(3000);



}
