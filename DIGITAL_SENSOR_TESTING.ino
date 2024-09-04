#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);       // Mentioning the kind of LCD been used along with the libruary which we are using in this program

const int DigitalPin = 12;                // Pin 12 of Arduino connected to digital sensor
             
int DigitalPin_State = 0;                 // Initializing a variable


void setup()
{
  pinMode(DigitalPin, INPUT);             // Mentioning if the sensor is an input or an output device
  lcd.begin();                            // Initializing the LCD
  lcd.print(" DIGITAL SENSOR");
  lcd.setCursor(0, 1);                    // Sets cursor at Column 0 and Line 1
  lcd.print("    TESTING");
  delay(3000);
}


void loop()
{
  DigitalPin_State = digitalRead(DigitalPin);    // Checking for input ----
  delay(10);

  if (DigitalPin_State == HIGH)
  {
    lcd.clear();
    lcd.print("    No Input");                   // Display this in first line
    delay(500);     // Wait for 500ms
  }

  if (DigitalPin_State == LOW)
  {
    lcd.clear();
    lcd.print("     Input ");                    // Display this in first line
    lcd.setCursor(0, 1);
    lcd.print("    Detected");
    delay(500);    // Wait for 500ms
  }
}