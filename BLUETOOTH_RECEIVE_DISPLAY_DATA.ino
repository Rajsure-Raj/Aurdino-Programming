#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);


void setup()
{
  Serial.begin(9600);
  lcd.begin();                        // Initializing LCD.
  lcd.clear();                        // Clearing LCD
  lcd.print("111Bluetooth RECEIVE");
  lcd.setCursor(0, 1);                // Sets cursor at Column 0 and Line 1
  lcd.print("TEST DATA");
  delay(2000);
}

void loop()
{
  lcd.clear();
  lcd.print("Checking Data...");
  delay(200);

  //================ Bluetooth receive ===================

  while (Serial.available())       // Check if any data received in RX(Pin 2) of bluetooth
  {
    delay(200);
    if (Serial.find("$"))          // Search for a symbol "$" in the data sent via buetooth
    {
      delay(200);
      char d = Serial.read();      // Save the character present, next to symbol "$" in Variable d
      delay(200);
      lcd.clear();
      lcd.print(d);                // Print the value of d
      delay(3000);
      d = 0;                       // Clear the value of d
    }
  }
}