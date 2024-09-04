#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define echoPin 6                    // Pin number 6 of arduino connected to Echo Pin of ultrasonic sensor
#define trigPin 7                    // Trigger Pin

const int buzzer = A3;               // Pin Number A3 of arduino connected to buzzer module

int maximumRange = 40;              // Maximum range needed
int minimumRange = 0;                // Minimum range needed
long duration, distance;             // Duration used to calculate distance
int buzz_s = 0;


void setup()
{
  Serial.begin(9600);
  lcd.begin();                        // Initializing LCD
  lcd.clear();                        // Clearing LCD
  lcd.print("   ULTRASONIC");
  Serial.println("ULTRASONIC");
  lcd.setCursor(0, 1);                // Sets cursor at Column 0 and Line 1
  lcd.print(" SENSOR TESTING");
  Serial.println("SENSOR TEST");
  delay(2000);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  buzz_s = LOW;
  digitalWrite(buzzer, buzz_s);
  delay(3000);
}


void loop()
{
  digitalWrite(trigPin, LOW);                // Initializing trigger pin
  delayMicroseconds(2);                      // Wait for 2 micro seconds
  digitalWrite(trigPin, HIGH);               // Send a pulse
  delayMicroseconds(10);                     // Wait 10 micro seconds
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);         // Calculate the time taken by ECHO pin to recieve the pulse

  //Calculate the distance (in cm) based on the speed of sound=========
  distance = duration / 58.2;
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("Distance:");
  Serial.print("Distance: ");
  lcd.setCursor(4, 1);
  lcd.print(distance);
  Serial.print(distance);
  lcd.print(" cms");
  Serial.println("cms");

  if (distance > 0)
  {
    if (distance < 5)
    {
      buzz_s = HIGH;
      digitalWrite(buzzer, buzz_s);
      delay(60);
      buzz_s = LOW;
      digitalWrite(buzzer, buzz_s);
      delay(60);
    }
  }
  if (distance > 5)
  {
    if (distance < 12.5)
    {
      buzz_s = HIGH;
      digitalWrite(buzzer, buzz_s);
      delay(125);
      buzz_s = LOW;
      digitalWrite(buzzer, buzz_s);
      delay(125);
    }
  }

  if (distance > 12.5)
  {
    if (distance < 25)
    {
      buzz_s = HIGH;
      digitalWrite(buzzer, buzz_s);
      delay(250);
      buzz_s = LOW;
      digitalWrite(buzzer, buzz_s);
      delay(250);
    }
  }

  if (distance > 25)
  {
    if (distance < 50)
    {
      buzz_s = HIGH;
      digitalWrite(buzzer, buzz_s);
      delay(500);
      buzz_s = LOW;
      digitalWrite(buzzer, buzz_s);
      delay(500);
    }
  }
}
