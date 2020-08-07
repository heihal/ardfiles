#include <Servo.h>
Servo srv;
int const ohjainPIN = A0;
int ohjainVal;
int kulma;

void setup() {
  srv.attach(9);
  Serial.begin(9600);

}

void loop() {
  ohjainVal = analogRead(ohjainPIN);
  Serial.print("potVal: ");
  Serial.print(ohjainVal);
  kulma = map(ohjainVal, 0, 1023, 0, 159);
  Serial.print(", angle: ");
  Serial.println(kulma);
  srv.write(kulma);
  delay(15);

}
