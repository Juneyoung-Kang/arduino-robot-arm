#include <Servo.h>

Servo servo1; //Servos
Servo servo2;
Servo servo3;
Servo servo4;

const int LED1 = 2; //LEDs
const int LED2 = 3;
const int LED3 = 4;
const int LED4 = 7;
const int LED5 = 8;

const int button1 = 12; //Buttons
const int button2 = 13;

int button1Presses = 0; //Button values
boolean button2Pressed = false;

const int pot1 = A0; //Potentimeters
const int pot2 = A1; 
const int pot3 = A2;
const int pot4 = A3;

int pot1Val; //Potentimeter values
int pot2Val;
int pot3Val;
int pot4Val;
int pot1Angle;
int pot2Angle;
int pot3Angle;
int pot4Angle;

int servo1PosSaves[] = {1,1,1,1,1}; //position saves
int servo2PosSaves[] = {1,1,1,1,1};
int servo3PosSaves[] = {1,1,1,1,1};
int servo4PosSaves[] = {1,1,1,1,1};

void setup() {
  servo1.attach(5);
  servo2.attach(6);
  servo3.attach(9);
  servo4.attach(10);
  
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);

  Serial.begin(9600);
}

void loop() {
  pot1Val = analogRead(pot1);
  pot1Angle = map(pot1Val, 0, 1023, 0, 179); 
  pot2Val = analogRead(pot2); 
  pot2Angle = map(pot2Val, 0, 1023, 0, 179);
  pot3Val = analogRead(pot3);
  pot3Angle = map(pot3Val, 0, 1023, 0, 179);
  pot4Val = analogRead(pot4);
  pot4Angle = map(pot4Val, 0, 1023, 0, 179);
  
  servo1.write(pot1Angle);
  servo2.write(pot2Angle);
  servo3.write(pot3Angle);
  servo4.write(pot4Angle);
   if(digitalRead(LED1)==HIGH){
    Serial.println("LED1 IS HIGH!");
  } else{
    Serial.println("NO!");
  }
  
  if(digitalRead(button1) == HIGH){
    button1Presses++;
    switch(button1Presses){
      case 1:
        servo1PosSaves[0] = pot1Angle;
        servo2PosSaves[0] = pot2Angle;
        servo3PosSaves[0] = pot3Angle;
        servo4PosSaves[0] = pot4Angle;
        digitalWrite(LED1, HIGH);
        Serial.println("Pos 1 Saved");
        break;
      case 2:
         servo1PosSaves[1] = pot1Angle;
         servo2PosSaves[1] = pot2Angle;
         servo3PosSaves[1] = pot3Angle;
         servo4PosSaves[1] = pot4Angle;
         digitalWrite(LED2, HIGH);
         Serial.println("Pos 2 Saved");
         break;
      case 3:
         servo1PosSaves[2] = pot1Angle;
         servo2PosSaves[2] = pot2Angle;
         servo3PosSaves[2] = pot3Angle;
         servo4PosSaves[2] = pot4Angle;
         digitalWrite(LED3, HIGH);
         Serial.println("Pos 3 Saved");
         break;
       case 4:
         servo1PosSaves[3] = pot1Angle;
         servo2PosSaves[3] = pot2Angle;
         servo3PosSaves[3] = pot3Angle;
         servo4PosSaves[3] = pot4Angle;
         digitalWrite(LED4, HIGH);
         Serial.println("Pos 4 Saved");
         break;
       case 5:
         servo1PosSaves[4] = pot1Angle;
         servo2PosSaves[4] = pot2Angle;
         servo3PosSaves[4] = pot3Angle;
         servo4PosSaves[4] = pot4Angle;
         digitalWrite(LED5, HIGH);
         Serial.println("Pos 5 Saved");
         break;
    }
  }

  if(digitalRead(button2) == HIGH){ 
    button2Pressed = true;   
  }
  
  if(button2Pressed){ 
    for(int i = 0; i < 5; i++){
        servo1.write(servo1PosSaves[i]);
        servo2.write(servo2PosSaves[i]);
        servo3.write(servo3PosSaves[i]);
        servo4.write(servo4PosSaves[i]);
        Serial.println(" potentimeter Angles: ");
        Serial.println(servo1PosSaves[i]);
        Serial.println(servo2PosSaves[i]);
        Serial.println(servo3PosSaves[i]);
        Serial.println(servo4PosSaves[i]);
        delay(1050);
      }
  }
  delay(300);
} 
