// declaring variables to store the pin numbers of each item.
int led = 10;
int sensor = 7;
int sensor_value;
int buzzer = 8;

void setup() {

  // declaring the sensor,led, and buzzer as inputs.
  pinMode(sensor, INPUT);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);

  // initializing the serial monitor.
  Serial.begin(9600);

}

// MAIN LOOP.
void loop() {

  // tying the 'sensor_value' variable to the value read from the sensor.
  sensor_value = digitalRead(sensor);

  // printing the sensor value on the serial monitor.
  Serial.println(sensor_value);

  // if-statement to determine when the LED should flash and the buzzer should ring.
  if (sensor_value == 1){
    digitalWrite(led, HIGH);
    tone(buzzer, 1000);
    delay(200);
  }
  else{
    digitalWrite(led, LOW);
    noTone(buzzer);
  }

}
