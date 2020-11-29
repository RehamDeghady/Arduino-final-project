#include<Servo.h>
 
int servoBin = 3;
int ledBin = 4;
int buttonBin = 7;
int buzzerBin = 13;
int lightBin= A0;
int light2Bin = A2;
 
int numInRoom = 0;
int counter = 0;
int rem = 0;
int lightValue;
int light2Value;
int buttonValue;
 
Servo Servo1;
 
 
void setup() {
 
  pinMode(servoBin , OUTPUT);
  pinMode(ledBin , OUTPUT);
  pinMode(buzzerBin , OUTPUT);
  pinMode(lightBin , INPUT);
  pinMode(light2Bin , INPUT);
  pinMode(buttonBin , INPUT);
 
 
  Servo1.attach(servoBin);
 
  Serial.begin(9600);
}
 
void loop() {
 
  Serial.print(rem);
  Serial.print(" ");
  buttonValue = digitalRead(buttonBin);
  rem = counter % 2;
  if (buttonValue == LOW){
    delay (1000);
    counter += 1;
  }
    if (rem == 1){
      if (numInRoom < 6 && numInRoom > 0){
  digitalWrite(ledBin , LOW);
  lightValue = analogRead(lightBin);
  light2Value = analogRead(light2Bin);
 
 
  if (lightValue < 40){
    for (int i=0; i<800; i++){
    digitalWrite(buzzerBin , HIGH);
    delay(1);
    digitalWrite(buzzerBin , LOW);
    }
    delay(500);
    Servo1.write(90);
    delay (1000);
    Servo1.write(0);
    delay (1000);
    Servo1.write(90);
    delay (1000);
    numInRoom -=1;
    counter += 1;
  }
  if (light2Value < 40){
    for (int i=0; i<800; i++){
    digitalWrite(buzzerBin , HIGH);
    delay(1);
    digitalWrite(buzzerBin , LOW);
    }
    delay(500);
    Servo1.write(90);
    delay (1000);
    Servo1.write(0);
    delay (1000);
    Servo1.write(90);
    delay (1000);
    numInRoom +=1;
    counter +=1;
  }
}
 
  if (numInRoom == 6){
    digitalWrite(ledBin , HIGH);
    while (numInRoom == 6){
    lightValue = analogRead(lightBin);
    buttonValue = digitalRead(buttonBin);
    if (buttonValue == LOW){
    counter += 1;
  }
  rem = counter % 2;
 
if (rem == 1){
  if (lightValue < 40){
    delay(500);
    Servo1.write(90);
    delay (1000);
    Servo1.write(0);
    delay (1000);
    Servo1.write(90);
    delay (1000);
    numInRoom -=1;
    digitalWrite(ledBin , LOW);
    counter += 1;
  }
}
    digitalWrite(buzzerBin , HIGH);
    delay(1);
    digitalWrite(buzzerBin , LOW);
 
    }
 
 
  }
  if (numInRoom == 0){
    digitalWrite(ledBin , LOW);
    digitalWrite(buzzerBin , LOW);
  light2Value = analogRead(light2Bin);
    if (light2Value < 40){
    for (int i=0; i<800; i++){
    digitalWrite(buzzerBin , HIGH);
    delay(1);
    digitalWrite(buzzerBin , LOW);
    }
    delay(500);
    Servo1.write(90);
    delay (1000);
    Servo1.write(0);
    delay (1000);
    Servo1.write(90);
    delay (1000);
    numInRoom +=1;
    counter += 1;
  }
  }
  }
}
 
