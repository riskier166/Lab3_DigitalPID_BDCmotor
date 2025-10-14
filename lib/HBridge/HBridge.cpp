#include "HBridge.h"

HBridge::HBridge()
{
}

void HBridge::setup(uint8_t pwm_pin, uint8_t pwm_channel, uint8_t clk_pin, uint8_t cclk_pin)
{
    hbridge_pwm.setup(pwm_pin, pwm_channel, &motor_pwm_config);
    clk.setup(clk_pin, GPO);
    cclk.setup(cclk_pin, GPO);
}

void HBridge::setSpeed(float speed, uint8_t dir)
{
    if (dir == 1)
    {
        clk.set(1);
        cclk.set(0);
        hbridge_pwm.setDuty(speed);
    }
    else if (dir == 0)
    {
        clk.set(0);
        cclk.set(1);
        hbridge_pwm.setDuty(speed);
    }
    else
    {
        hbridge_pwm.setDuty(0.0);
        clk.set(0);
        cclk.set(0);
    }
}

void HBridge::setStop()
{
    hbridge_pwm.setDuty(0.0);
    clk.set(0);
    cclk.set(0);
}
