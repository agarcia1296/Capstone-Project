#include <Servo.h>
#include <SoftwareSerial.h>
#include <XBee.h>

#define LOW_LIMIT 470
#define HIGH_LIMIT 2625
SoftwareSerial XBee(2,3);
Servo myservo;

int data = 0;
int pos = 0;    // variable to store the servo position

void setup() {
  Serial.begin(9600);
  XBee.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo.write(0);
  delay(500);
}

void loop() {
  //check to see if XBee is recieving
  delay(50);
  while (XBee.available()) {
    data = XBee.read();
    Serial.println(data);
   
  if (data == 49) {
     pos=0;
  }
  else if (data == 50) {
    pos=60;
  }
  else if (data == 51) {
   pos=120;
  }
  else if (data == 52) {
    pos=180;
  }
  else if (data == 53) {
    pos=240;
  }
  pos=map(pos,0,270,LOW_LIMIT,HIGH_LIMIT);
  myservo.writeMicroseconds(pos);
  }
}
