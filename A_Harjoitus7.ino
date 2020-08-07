const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
#include <LiquidCrystal.h>
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int trigPin = 9;
const int echoPin = 8;
long duration;
int distanceCm, distanceInch;
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distanceCm= duration*0.034/2;

lcd.setCursor(0,0); // Sets the location at which subsequent text written to the LCD will be displayed
lcd.print("Etaisyys: "); // Prints string "Distance" on the LCD
lcd.print(distanceCm); // Prints the distance value from the sensor
lcd.print(" cm");
delay(1000);
lcd.clear();
}
