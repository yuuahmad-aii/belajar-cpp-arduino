#include "parsing.h"
#include <Arduino.h>

bool parsing;                            // nilai parsing data
int nilaiPWM, nilaiDigital, nilaiAnalog; // data yang ingin diambil
String serialData, arrayData[20];        // data terkumpul dan data yang disimpan sementara dalam string

void Parsing::lakukanParsing()
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
            for (unsigned int i = 0; i < serialData.length(); i++)
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
}

int Parsing::dapatkanNilaiPWM()
{
    return nilaiPWM;
}
int Parsing::dapatkanNilaiAnalog()
{
    return nilaiAnalog;
}
int Parsing::dapatkanNilaiDigital()
{
    return nilaiDigital;
}