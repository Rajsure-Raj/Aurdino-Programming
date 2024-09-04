#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);          // Mentioning the kind of LCD been used along with the library which we are using in this program
const int IRS1Pin = 4;                       // Pin 4 connected to digital output of IR sensor 1
//const int IRS2Pin = 3;                       // Pin 3 connected to digital output of IR sensor 2

int IRS1_State = 0;                          // Initializing to store the value of the variable
int IRS2_State = 0;


void setup()
{
  pinMode(IRS1Pin, INPUT_PULLUP);            // Mentioning if the sensor in an input or an output device
 // pinMode(IRS2Pin, INPUT_PULLUP);
  lcd.begin();                               // Initializing the LCD
  lcd.print(" IR SENSOR 1&2");
  lcd.setCursor(0, 1);                       // Sets cursor at Column 0 and Line 1
  lcd.print("    TESTING");
  delay(3000);
}


void loop()
{
  IRS1_State = digitalRead(IRS1Pin);         // Checking for Obstacles from IR Sensor 1----
  IRS2_State = digitalRead(IRS2Pin);         // Checking for Obstacles from IR Sensor 2----

  if (IRS1_State == HIGH && IRS2_State == HIGH)
  {
    lcd.clear();
    lcd.print("  No Obstacle");              //Display this in first line
    delay(500); //wait for 500ms
  }

  if (IRS1_State == LOW && IRS2_State == LOW)
  {
    lcd.clear();
    lcd.print(" Obstacle 1 & 2");               //Display this in first line
    lcd.setCursor(0, 1);
    lcd.print("    Detected");
    delay(500);
  }

  if (IRS1_State == LOW && IRS2_State == HIGH)
  {
    lcd.clear();
    lcd.print("   Obstacle 1");               //Display this in first line
    lcd.setCursor(0, 1);
    lcd.print("    Detected");
    delay(500);
  }

  if (IRS1_State == HIGH && IRS2_State == LOW)
  {
    lcd.clear();
    lcd.print("   Obstacle 2");               //Display this in first line
    lcd.setCursor(0, 1);
    lcd.print("    Detected");
    delay(500);
  }
}