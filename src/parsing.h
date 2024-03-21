#ifndef _PARSING
#define _PARSING
#include <Arduino.h>

class Parsing
{
private:
    /* data */
public:
    int pwm, analog, digital;
    void lakukanParsing();
    int dapatkanNilaiPWM();
    int dapatkanNilaiDigital();
    int dapatkanNilaiAnalog();
};

#endif