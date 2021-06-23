// including the servo library.
#include <Servo.h>

// instantiating the servo.
Servo servo1;

// declaring the led pins.
const int LED1 = 2;
const int LED2 = 3;
const int LED3 = 4;

// declaring the button pins.
const int button1 = 12;
const int button2 = 13;

// declaring the potentiometer's pin.
const int pot1 = A0;

// declaring variables to hold the value if the buttons are pressed.
int button1press = 0;
boolean button2press = false;

// declaring values for the potentiometer's angles.
int pot1Val;
int pot1Angle;

// declaring initial angles for the servo.
int servo1pos[] = {1, 1, 1};

void setup() {

  // tying the servo to pin 9.
  servo1.attach(9);

  // declaring the LED's as output and BUTTONS as input.
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);

  // initializing the serial monitor
  Serial.begin(9600);

}

// MAIN-LOOP.
void loop() {

  // reading the value from the potentiometer.
  pot1Val = analogRead(pot1);

  // map(value, fromLow, fromHigh, toLow, toHigh)
  // mapping the potentiometer value from 0 degrees to 180 degrees.
  pot1Angle = map(pot1Val, 0, 1023, 0, 179);

  // moving the servo to the desired angle.
  servo1.write(pot1Angle);

  // creating an if-statement for the amount of times the button is pressed to save each corresponding angle.
  // switch-case statements.
  if (digitalRead(button1) == HIGH){

    button1press++;
    switch(button1press){

  // cases for each angle.
  // making the LED flash when each angle is confirmed through the potentiometer.
      case 1:
        servo1pos[0] = pot1Angle;
        digitalWrite(LED1, HIGH);
        Serial.println("Position 1 Saved");
        break;

      case 2:
         servo1pos[1] = pot1Angle;
         digitalWrite(LED2, HIGH);
         Serial.println("Position 2 Saved");
         break;

      case 3:
         servo1pos[2] = pot1Angle;
         digitalWrite(LED3, HIGH);
         Serial.println("Position 3 Saved");
         break;
             
    }
    
  }
  
  // code to move to the 3 recorded angles if button 2 is pressed.
  if (digitalRead(button2) == HIGH){

    button2press = true;
  }

  if(button2press){

    for(int i = 0; i < 3; i++){

      servo1.write(servo1pos[i]);
      Serial.println("ANGLES: ");
      Serial.println(servo1pos[i]);
      delay(1000);

      
    }
  }

  delay(500);
  
}
