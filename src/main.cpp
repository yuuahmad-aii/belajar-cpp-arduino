#include <arduino.h>

const short int pinLed = 13;

int incomingByte = 0; // for incoming serial data

String kataSerial;
bool selesaiSerial = false; // whether

void setup()
{
  Serial.begin(115200); // opens serial port, sets data rate to 9600 bps
}

void loop()
{
  // reply only when you receive data:
  if (Serial.available() > 0)
  {
    // read the incoming string
    kataSerial = Serial.readStringUntil(';');
    selesaiSerial = false;
  }

  if (!selesaiSerial)
  {
    if (kataSerial.length() > 0)
    {
      // say what you got:
      Serial.print("I received: ");
      Serial.println(kataSerial);
      selesaiSerial = true;
    }
    else
    {
      Serial.println("tidak ada data");
      selesaiSerial = true;
    }
  }
}