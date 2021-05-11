// WATER FLOOD ALERT PROGRAM.

// declaring variables to store various values.
const int WaterSensor = 2;
const int buzzer = 9;
const int LED = 10;
int Water_value;


void setup() {

  // initializing the serial monitor.
  Serial.begin(9600);

  // declaring the various pins as INPUT or OUTPUT.
  pinMode(WaterSensor, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(LED, OUTPUT);
  

}

// MAIN LOOP.
void loop() {

  // code to tie the 'Water_value' variable to the value of the water from the sensor through analogRead.
  Water_value = analogRead(WaterSensor);
  Serial.println(Water_value);

  // creating an if-statement to make the LED flash and buzzer beep when the serial monitor reads values from the water sensor.
  if (Water_value > 300){

    // adding features to the LED and buzzer such as, the sound of the buzzer, brightness of LED, and adding a delay.
    digitalWrite(LED, HIGH);
    tone(buzzer, 800);
    delay(200);

    digitalWrite(LED, LOW);
    noTone(buzzer);
    delay(200);

    digitalWrite(LED, HIGH);
    tone(buzzer, 400);
    delay(200);

    digitalWrite(LED, LOW);
    noTone(buzzer);
    delay(200);
  }

  else {

    digitalWrite(LED, LOW);
    noTone(buzzer);
  }
  
}
