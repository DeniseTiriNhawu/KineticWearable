#include <Servo.h>
#define TILT 2  // pin 2 for the tilt


Servo skirtServo;   //servo for the left side
Servo skirtServo2;  // servo for the right side
int openPosition = 0;
int closePosition = 90;
void setup() {
 // put your setup code here, to run once:


 Serial.begin(9600);
 Serial.println("Tilt test");
 skirtServo.attach(9);              //servo is attached to digital pin 9
 skirtServo2.attach(10);            // servo2 is attached to digital pin 10
 skirtServo.write(closePosition);   // the skirt is first positioned down
 skirtServo2.write(closePosition);  // skirt is first positioned down
 pinMode(TILT, INPUT);
}


void loop() {
 // put your main code here, to run repeatedly:
 int TiltSensed = digitalRead(TILT);  //reads the value of the tilt sensor


 if (TiltSensed == 0) {              //value equals zero, do the following
   skirtServo.write(openPosition);   //output: servo moves to "0" degrees
   skirtServo2.write(openPosition);  //output: servo2 moves according to "0" degrees
   Serial.println("Tilt detected");
 } else {                             // value equals one, do the following
   skirtServo.write(closePosition);   //output: servo moves to "90" degrees
   skirtServo2.write(closePosition);  //output: servo2 moves to "90" degrees
   Serial.println("Normal");
 }
 delay(500);  //delays the respone time
}

