#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int motor1Pin = 8;           // motor 1 pin connected to pin number 8 of arduino
int motor1State = 0;
const int motor2Pin = 9;           // motor 1 pin connected to pin number 9 of arduino
int motor2State = 0;
const int motor3Pin = 10;          // motor 2 pin connected to pin number 10 of arduino
int motor3State = 0;
const int motor4Pin = 11;          // motor 2 pin connected to pin number 11 of arduino
int motor4State = 0;


void setup()
{
  lcd.begin();                     // Initializing LCD.
  lcd.clear();                     // Clearing LCD
  lcd.home();                      // Sets cursor at Column 0 and Line 0
  lcd.print("DC Motor");
  lcd.setCursor(0, 1);             // Sets cursor at Column 0 and Line 1
  lcd.print("TESTING");
  delay(2000);

  pinMode(motor1Pin, OUTPUT);
  pinMode(motor2Pin, OUTPUT);
  pinMode(motor3Pin, OUTPUT);
  pinMode(motor4Pin, OUTPUT);

  motor1State = LOW;
  motor2State = LOW;
  motor3State = LOW;
  motor4State = LOW;
  digitalWrite(motor1Pin, motor1State);
  digitalWrite(motor2Pin, motor2State);
  digitalWrite(motor3Pin, motor3State);
  digitalWrite(motor4Pin, motor4State);
  delay(2000);
}


void loop()
{
  motor1State = HIGH;
  motor2State = LOW;
  motor3State = HIGH;
  motor4State = LOW;
  digitalWrite(motor1Pin, motor1State);
  digitalWrite(motor2Pin, motor2State);
  digitalWrite(motor3Pin, motor3State);
  digitalWrite(motor4Pin, motor4State);
  lcd.clear();     // Clears LCD
  lcd.print("LEFT TURN..");
  delay(5000);
  motor1State = LOW;
  motor2State = LOW;
  motor3State = LOW;
  motor4State = LOW;
  digitalWrite(motor1Pin, motor1State);
  digitalWrite(motor2Pin, motor2State);
  digitalWrite(motor3Pin, motor3State);
  digitalWrite(motor4Pin, motor4State);
  lcd.clear();     // Clears LCD
  lcd.print("Stopped..");
  delay(1000);
  motor1State = LOW;
  motor2State = HIGH;
  motor3State = LOW;
  motor4State = HIGH;
  digitalWrite(motor1Pin, motor1State);
  digitalWrite(motor2Pin, motor2State);
  digitalWrite(motor3Pin, motor3State);
  digitalWrite(motor4Pin, motor4State);
  lcd.clear();     // Clears LCD
  lcd.print("RIGHT TURN..");
  delay(5000);
  motor1State = LOW;
  motor2State = LOW;
  motor3State = LOW;
  motor4State = LOW;
  digitalWrite(motor1Pin, motor1State);
  digitalWrite(motor2Pin, motor2State);
  digitalWrite(motor3Pin, motor3State);
  digitalWrite(motor4Pin, motor4State);
  lcd.clear();     // Clears LCD
  lcd.print("Stopped..");
  delay(1000);
}