#include <arduino.h>

const short int pinLed = 13;

bool parsing;                            // nilai parsing data
int nilaiPWM, nilaiDigital, nilaiAnalog; // data yang ingin diambil
String serialData, arrayData[20];         // data terkumpul dan data yang disimpan sementara dalam string

unsigned long waktuLalu;
int delaySaya = 1200;

void setup()
{
  Serial.begin(115200);
  pinMode(pinLed, OUTPUT);
}

void loop()
{
  while (Serial.available())
  {
    // buat variabel nilaiinput, dan masukkan nilai serial.readString kesana
    // String nilaiInput = Serial.readString();
    // print/tampilkan nilai input tadi di serial monitor
    char inChar = Serial.read();
    serialData += inChar;
    if (inChar == '$')
      parsing = true;
    if (parsing)
    {
      int q = 0;
      for (int i = 0; i < serialData.length(); i++)
      {
        if (serialData[i] == '#')
        {
          q++;
          arrayData[q] = "";
        }
        else
          arrayData[q] += serialData[i];
      }
      // setelah semua data didapatkan, kita akan print datanya ke serial satu persatu
      nilaiPWM = arrayData[0].toInt();
      nilaiDigital = arrayData[1].toInt();
      nilaiAnalog = arrayData[2].toInt();
      parsing = false;
      serialData = "";
    }
  }

  if (millis() - waktuLalu > delaySaya)
  {
    waktuLalu = millis();
    // tampilkan data pada serial
    Serial.print("pwm: ");
    Serial.println(nilaiPWM);
    Serial.print("digital: ");
    Serial.println(nilaiDigital);
    Serial.print("analog: ");
    Serial.println(nilaiAnalog);
    Serial.println(); // enter
  }

  if (nilaiAnalog != 0 && nilaiAnalog > 0 && nilaiAnalog < 255)
    analogWrite(pinLed, nilaiAnalog);
  else
    digitalWrite(pinLed, 0);
}