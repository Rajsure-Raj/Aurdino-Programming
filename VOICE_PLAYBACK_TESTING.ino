#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int VoicePlay = 2;                            // Pin Number 2 connected to PlayE input of Voice Playback circuit
int VoicePlay_State = 0;                            // Initializing a variable


void setup()
{
  pinMode(VoicePlay, OUTPUT);
  VoicePlay_State = LOW;
  digitalWrite(VoicePlay, VoicePlay_State);
  lcd.begin();
  lcd.clear();
  lcd.print("Voice Playback");
  lcd.setCursor(0, 1);
  lcd.print("   Testing");
  delay(3000);
}


void loop()
{
  VoicePlay_State = HIGH;
  digitalWrite(VoicePlay, VoicePlay_State);
  delay(1500);
  VoicePlay_State = LOW;
  digitalWrite(VoicePlay, VoicePlay_State);
  delay(1500);

}