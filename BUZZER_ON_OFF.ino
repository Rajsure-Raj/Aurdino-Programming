const int Buzzer = A3;                        // Pin number A3 of arduino connected to Buzzer Module
int BuzzerState = 0;                          // Variable for initializing  
 

void setup()
{
  pinMode(Buzzer, OUTPUT);
  BuzzerState = LOW;
  digitalWrite(Buzzer, BuzzerState);
  delay(1000);
}


void loop()
{
  BuzzerState = HIGH;
  digitalWrite(Buzzer, BuzzerState);
  delay(1000);
  BuzzerState = LOW;
  digitalWrite(Buzzer, BuzzerState);
  delay(1000);
}