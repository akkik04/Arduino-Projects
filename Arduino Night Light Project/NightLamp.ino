  // 'ldr' stands for Light-Dependant-Resistor as used in this project.

  // initializing the ldr pin's number.
  int ldr_PIN = 0;
  
  // variable to store the ldr value.
  int light;
  
  // variables to store the pin numbers of the LED's.
  int red_LED = 9;
  int green_LED = 10;
  int blue_LED = 11;
  
  // creating an array to store the brightness of the 3 LED's.
  float RGB[3];
  
  void setup() {

   Serial.begin(9600);

  // declaring pins as output and setting the light effectiveness.
  pinMode(red_LED, OUTPUT);
  pinMode(green_LED, OUTPUT);
  pinMode(blue_LED, OUTPUT);
  
  digitalWrite(red_LED, LOW);
  digitalWrite(green_LED, LOW);
  digitalWrite(blue_LED, LOW);
  
  }
  
  void loop() {
  
  // using sine values to create a smooth curve for transition of lights.
  
  for(float x = 0; x < PI; x = x + 0.00001){
  
  RGB[0] = 255 * abs(sin(x * (180 / PI)));
  RGB[1] = 255 * abs(sin((x + PI/3) * (180 / PI)));
  RGB[2] = 255 * abs(sin((x + 2 * PI/3) * (180 / PI)));
  
  // reading value from the LDR pin.
  light = analogRead(ldr_PIN);
  Serial.println(light);
  
  // if-statement for setting brightness of LED's depending on the lighting in user's environment.
  if (light > 975){
  
  analogWrite(red_LED, RGB[0]);
  analogWrite(green_LED, RGB[1]);
  analogWrite(blue_LED, RGB[2]);
  
  }
  
  else{
  
  digitalWrite(red_LED, LOW);
  digitalWrite(green_LED, LOW);
  digitalWrite(blue_LED, LOW);
  }

  // for-loop to iterate for the 3 lights and switch between colours on RGB light.
  for(int i = 0; i < 3; i++){

  // nested if-statement to determine when to switch light colour along with delay.
  if (RGB[i] < 1){
    delay(100);
  }
  
  if (RGB[i] < 5){
    delay(50);
  }
  
  if (RGB[i] < 100){
    delay(10);
  }
  }
  
  delay(5);
  
  }
  
  }
