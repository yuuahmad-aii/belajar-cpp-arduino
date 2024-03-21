#include <arduino.h>
#include "parsing.h"

const short int pinLed = 13;

unsigned long waktuLalu;
unsigned long delaySaya = 1200;
Parsing parsingSaya;
int pwmSaya, analogLed;

void setup()
{
  Serial.begin(115200);
  pinMode(pinLed, OUTPUT);
}

void loop()
{
  parsingSaya.lakukanParsing();
  pwmSaya = parsingSaya.dapatkanNilaiPWM();

  if (millis() - waktuLalu > delaySaya)
  {
    waktuLalu = millis();
    Serial.print("nilai PWM : ");
    Serial.print(pwmSaya);
  }

  analogLed = parsingSaya.dapatkanNilaiAnalog();
  if (analogLed != 0 && analogLed > 0 && analogLed < 255)
    analogWrite(pinLed, analogLed);
  else
    digitalWrite(pinLed, 0);
}