#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int ADSensor2 = A1;                           // Pin number A1 of arduino connected to A/D Sensor 2

int ADSensor2_A_State = 0;
int ADSensor2_D_State = 0;


void setup()
{
  pinMode(ADSensor2, INPUT);
  lcd.begin();
  lcd.clear();
  lcd.print("  A/D Sensor2");
  lcd.setCursor(0, 1);
  lcd.print("    Testing");
  delay(3000);
}


void loop()
{
  ADSensor2_A_State = analogRead(ADSensor2);         //Read analog value from sensor
  ADSensor2_D_State = digitalRead(ADSensor2);        //Read digital value from sensor

  if (ADSensor2_D_State == LOW)
  {
    lcd.clear();
    lcd.print("Analog = ");
    lcd.print(ADSensor2_A_State);
    lcd.setCursor(0, 1);
    lcd.print("Input Detected");
    delay(500);
  }

  if (ADSensor2_D_State == HIGH)
  {
    lcd.clear();
    lcd.print("Analog = ");
    lcd.print(ADSensor2_A_State);
    lcd.setCursor(0, 1);
    lcd.print("    No Input");
    delay(500);
  }
}
