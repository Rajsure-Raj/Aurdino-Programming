#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int switch1Pin = 4;
int switch1State = 0;

const int switch2Pin = 3;
int switch2State = 0;


void setup()
{
  pinMode(switch1Pin, INPUT_PULLUP);
  pinMode(switch2Pin, INPUT_PULLUP);
  lcd.begin();
  lcd.print("  SWITCH ARRAY");
  lcd.setCursor(0, 1);                          // Sets cursor at Column 0 and Line 1
  lcd.print("    TESTING");
  delay(3000);
}


void loop()
{
  lcd.clear();
  lcd.print("Checking....");
  delay(30);
  
  switch1State = digitalRead(switch1Pin);       // Check switch pin continuously
  switch2State = digitalRead(switch2Pin);       // Check switch pin continuously

  if (switch1State == LOW)
  {
    lcd.clear();
    lcd.print("Switch 1 Pressed");              // Display this in first line
    delay(2000);
  }

  if (switch2State == LOW)
  {
    lcd.clear();
    lcd.print("Switch 2 Pressed");              // Display this in first line
    delay(2000);
  }
}