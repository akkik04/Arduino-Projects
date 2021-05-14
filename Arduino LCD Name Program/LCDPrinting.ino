// importing the required module to operate the LCD.
#include <LiquidCrystal.h>
/*
  The circuit:
 * LCD RS pin to digital pin 7
 * LCD Enable pin to digital pin 8
 * LCD D4 pin to digital pin 9
 * LCD D5 pin to digital pin 10
 * LCD D6 pin to digital pin 11
 * LCD D7 pin to digital pin 12
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 * A to 5V, K to GND
 */

// declaring the LCD pins.
 LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
 
void setup() {

  // initializing the LCD.
  lcd.begin(16, 2);

}

// MAIN LOOP.
void loop() {
  
  // using the LCD to print the message.
  lcd.setCursor(0,0);
  lcd.print("Hello World!");
  lcd.setCursor(0,1);
  lcd.print("I am Akshith");

}
