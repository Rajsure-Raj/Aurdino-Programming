const int relayPin = 5;                            // Pin Number 5 connected to Relay
int relayState = 0;                                // Variable for initializing


void setup()
{
  pinMode(relayPin, OUTPUT);
  relayState = LOW;
  digitalWrite(relayPin, relayState);
  delay(1000);
}


void loop()
{
  relayState = HIGH;
  digitalWrite(relayPin, relayState);
  delay(1500);
  relayState = LOW;
  digitalWrite(relayPin, relayState);
  delay(1500);

}
