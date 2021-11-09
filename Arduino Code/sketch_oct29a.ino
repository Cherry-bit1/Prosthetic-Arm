#include <Servo.h>

Servo servo1;
Servo servo2;
int outPin1 = 9;
int outPin2 = 8;
int val = 0;
float EMG = A0;
int position;

void setup() {
  servo1.attach(9, 900, 2100); // Connects servo1 to pin 9
  servo2.attach(8, 900, 2100); // Connects servo2 to pin 8
  pinMode(outPin1, OUTPUT);
  pinMode(outPin2, OUTPUT);
  pinMode(EMG, INPUT);
  Serial.begin(9600);
}

void loop() {
  val = digitalRead(EMG);
  if(val){ // If there is input
    servo1.write(0); // Servo set to 0 degrees
    servo2.write(0);
    delay(1000); // Pause
    for(position = 0; position <= 90; position += 1){
      servo1.write(position); // Moves servo to next position
      servo2.write(position);
      delay(20); // Pause to allow time for servo to move
    }
    delay(1000); // Pause
  }
}
