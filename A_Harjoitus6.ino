
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int analogPin = A4;
float analogValue;
float input_voltage;

void setup() {
  // set up the LCD's number of columns and rows:
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(A4,INPUT);
  lcd.print("Voltage level");
}

void loop() {
    
  analogValue = analogRead (A4);
  Serial.println(analogValue);
  delay (1000); 
  input_voltage = (analogValue * 5.0) / 1024.0;
  lcd.setCursor(0, 1);
  lcd.print("Voltage= ");
  lcd.print(input_voltage);
  Serial.println(input_voltage);
  delay(100);
}
