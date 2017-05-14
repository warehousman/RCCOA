#include <Arduino.h>
#include <MeMCore.h>
Servo servo_3_1;
//Servo servo_3_2;
MePort port_3(3);
MeUltrasonicSensor ultrasonic_2(2);
int d = 100;

void setup(){
  servo_3_1.attach(port_3.pin1());
  //servo_3_2.attach(port_3.pin2());
  servo_3_1.write(0);
  //servo_3_2.write(90);
  Serial.begin(9600);
}

void loop() {
d = ultrasonic_2.distanceCm();
Serial.println(d);
  if (d > 10) {
    servo_3_1.write(92);
  }
}
