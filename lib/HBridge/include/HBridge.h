#ifndef _HBRIDGE_H
#define _HBRIDGE_H

#include "SimplePWM.h"
#include "SimpleGPIO.h"

class HBridge
{
public:
    HBridge();
    void setup(uint8_t pwm_pin, uint8_t pwm_channel, uint8_t clk_pin, uint8_t cclk_pin);
    void setSpeed(float speed, uint8_t dir);
    void setStop();

private:
    SimplePWM hbridge_pwm;
    SimpleGPIO clk;
    SimpleGPIO cclk;
    TimerConfig motor_pwm_config{// Structure for timer configuration
                                 .timer = LEDC_TIMER_0,
                                 .frequency = 10000, // Frequency in Hz
                                 .bit_resolution = LEDC_TIMER_8_BIT,
                                 .mode = LEDC_LOW_SPEED_MODE};
};

#endif // _HBRIDGE_H