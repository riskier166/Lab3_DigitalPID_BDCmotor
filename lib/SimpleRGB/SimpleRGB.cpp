#include "SimpleRGB.h"

SimpleRGB::SimpleRGB()
{

}
void SimpleRGB::setup(uint8_t pins[3], uint8_t channel[3], TimerConfig *config, bool invert)
{
    for (uint8_t i = 0; i < 3; i++)
    {
        pwm[i].setup(pins[i],channel[i],config,invert);
    }
}

void SimpleRGB::setColor(uint8_t r, uint8_t g, uint8_t b)
{
    pwm[0].setDigitalLevel(r);
    pwm[1].setDigitalLevel(g);
    pwm[2].setDigitalLevel(b);
}
 
void SimpleRGB::setColor(uint32_t color_code)
{
    setColor(color_code >> 16 & 0xFF,color_code >> 8 & 0xFF ,color_code & 0xFF);
}

