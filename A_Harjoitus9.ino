#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


float temp;
float tempT;
int sensorPin = 0; 

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
}


void loop() {
  lueAsteet();
  delay(3000);
 printtaa();
 
}

void lueAsteet(){
 int reading = analogRead(sensorPin);
 float voltage = reading * 5.0;
 voltage /= 1024.0;
 temp = (voltage - 0.5) * 100 ;
 tempT =temp;
}

void printtaa() {
  temp = (floor((temp*2)+0.5)/2);
  
  lcd.clear();
  lcd.setCursor(0,0);
  String eka = " Celsiusta";
  String stringi = temp + eka;
  Serial.print(tempT); Serial.println(" Celsius- astetta");
  Serial.print(stringi); Serial.println(" Celsius- astetta LCD- näytössä");
  lcd.print(stringi);
}
