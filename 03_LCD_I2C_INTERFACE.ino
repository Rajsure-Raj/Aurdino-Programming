#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);


void setup()
{
  lcd.begin();                                // Initialize the LCD
  lcd.clear();
  lcd.print("Robotics Development Board");
  delay(1000);
}


void loop()
{
  lcd.scrollDisplayLeft();
  delay(300);
}
