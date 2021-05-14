  // importing the necessary modules for the project.
  #include <LiquidCrystal.h>
  #include <DS3231.h>

  // declaring the necessary variables using the modules.
  DS3231 clock;
  RTCDateTime dt;
  LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
  const int buzzer = 5;


void setup() {

  // initializing the buzzer.
  pinMode(buzzer, OUTPUT);

  
  // initializing the LCD.
  lcd.begin(16, 2);
  
  // initializing the RTC module.
  clock.begin();
  clock.setDateTime(__DATE__, __TIME__);

}

// MAIN LOOP.
void loop() {

  // receiving data as the date and time from the RTC module.
   dt = clock.getDateTime();

  // code for printing the year, month, and day recieved from the RTC module on the LCD.
  lcd.setCursor(0,0);
  lcd.print(dt.year);
  lcd.print("-");
  lcd.print(dt.month);
  lcd.print("-");
  lcd.print(dt.day);
  
  // code for printing the hour, minute, and second recieved from the RTC module on the LCD. 
  lcd.setCursor(0,1);
  lcd.print(dt.hour);
  lcd.print(":");
  lcd.print(dt.minute);
  lcd.print(":");
  lcd.print(dt.second);
  lcd.print(":");
  
  delay(1000);
 
  /* if-statement to determine when the alarm should be activated to alert the user.
   *  
   * *** THE CODE IS SET FOR THE ALARM TO RING AT 8:18 PM.***
   * ADJUST THE IF-STATEMENT'S CONDITIONS OF TIME TO FIT THE APPROPRIATE PERIOD.
   */
   
  if ((dt.hour == 20) && (dt.minute == 18)){
    lcd.clear();
    lcd.setCursor(0, 3);
    lcd.print("ALARM IS RINGING");

    // setting the buzzer to ring and stop to create an effect.
    tone(buzzer, 400);
    delay(500);
    noTone(buzzer);
    delay(500);
    lcd.clear();
    
    // code for printing each corresponding value from "DT" on the LCD.
    lcd.setCursor(0,0);
    lcd.print(dt.year);
    lcd.print("-");
    lcd.print(dt.month);
    lcd.print("-");
    lcd.print(dt.day);
    
   
    lcd.setCursor(0,1);
    lcd.print(dt.hour);
    lcd.print(":");
    lcd.print(dt.minute);
    lcd.print(":");
    lcd.print(dt.second);
    lcd.clear();
  
  }
}
