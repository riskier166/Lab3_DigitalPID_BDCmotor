#ifndef __SIMPLERGB_H__
#define __SIMPLERGB_H__

#include "SimplePWM.h"

class SimpleRGB
{
public:
    SimpleRGB();
    void setup(uint8_t pins[3], uint8_t channel[3], TimerConfig *config, bool invert);
    void setColor(uint8_t r, uint8_t g, uint8_t b);
    void setColor(uint32_t color_code);

private:
    SimplePWM pwm[3];
};

#endif // __SIMPLERGB_H__