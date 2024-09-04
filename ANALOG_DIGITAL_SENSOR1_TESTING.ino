#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int ADSensor1 = A0;                     // Pin number A0 of arduino connected to A/D Sensor 1
const int Buzzer = A3;                        // Pin number A3 of arduino connected to Buzzer Module
int BuzzerState = 0;                          // Variable for initializing  
 

int ADSensor1_A_State = 0;
int ADSensor1_D_State = 0;


void setup()
{
  pinMode(ADSensor1, INPUT);
  pinMode(Buzzer, OUTPUT);
  BuzzerState = LOW;
  lcd.begin();
  lcd.clear();
  lcd.print("   A/D Sensor1");
  lcd.setCursor(0, 1);
  lcd.print("    Testing");
  delay(3000);
}


void loop()
{
//  ADSensor1_A_State = analogRead(ADSensor1);
  ADSensor1_D_State = digitalRead(ADSensor1);
//
//  if (ADSensor1_D_State == LOW)
//  {
//    lcd.clear();
//    lcd.print("Analog = ");
//    lcd.print(ADSensor1_A_State);
//    lcd.setCursor(0, 1);
//    lcd.print("Input Detected");
//    delay(500);
//  }

  if (ADSensor1_D_State == HIGH)
  {
    lcd.clear();
//    lcd.print("Digital = ");
    lcd.print(ADSensor1_D_State);
    lcd.setCursor(0, 1);
    BuzzerState = LOW;
    digitalWrite(Buzzer, BuzzerState);
    delay(500);
  }

   else{
    lcd.print("   No Input");
    delay(500);
    BuzzerState = HIGH;
    digitalWrite(Buzzer, BuzzerState);
//    delay(500);
  }

}
