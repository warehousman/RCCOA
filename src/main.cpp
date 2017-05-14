#include <Arduino.h>
#include <MeMCore.h>
Servo servo_3_1; // ESC
Servo servo_3_2; // Steering Servo
MePort port_3(3); // Init adapter
MeUltrasonicSensor ultrasonic_2(2); // Init ultrasonic
int steer = 78; // neuteral steering servo
int csp = 90; //forward speed
int bsp = 125; //backward speed
int l = 40;
int r = 115;

void setup(){
  pinMode(A7, INPUT);
  servo_3_1.attach(port_3.pin1());
  servo_3_2.attach(port_3.pin2());
  servo_3_2.write(steer);
  Serial.begin(9600);
}

void FWD () {
  servo_3_1.write(csp);
  servo_3_2.write(steer);
  delay (500);
}

void TurnLeft () {
  servo_3_1.write(csp);
  servo_3_2.write(l);
  delay (500);
}

void TurnRight () {
  servo_3_1.write(csp);
  servo_3_2.write(r);
  delay (500);
}

void BR () {
  servo_3_2.write(l);
  for (int i = csp; i < bsp; i++) {
    servo_3_1.write(i);
  }
  delay (500);
}

void BL () {
  servo_3_2.write(r);
  for (int i = csp; i < bsp; i++) {
    servo_3_1.write(i);
  }
  delay (500);
}

void loop() {
int d = ultrasonic_2.distanceCm(100);
randomSeed(analogRead(6));
int randNumber = random(2);
//Serial.print("d - ");
//Serial.println(d);
  if (d > 50 || d == 0) {
    FWD ();
    //Serial.println (">50 FWD");
  }
  else if (d > 30) {
    //Serial.print (">30 Turn");
    switch (randNumber) {
      case 0:
        TurnLeft();
        break;
      case 1:
        TurnRight();
        break;
    }
  }
  else {
    switch (randNumber) {
      case 0:
        BR();
        break;
      case 1:
        BL();
        break;
    }
  }
}
