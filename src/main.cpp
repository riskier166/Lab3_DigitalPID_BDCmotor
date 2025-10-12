#include <definitions.h>

static void IRAM_ATTR timerISR(void *arg);

extern "C" void app_main()
{
    esp_task_wdt_deinit();
    MOTOR_PWM.setup(PWM_PIN, PWMCH, &motor_pwm_config);
    COUNT_CLKWISE.setup(COUNT_CLKW, GPO);
    COUNT_CNTCLKWISE.setup(COUNT_CNTCLKW, GPO);
    timer.setup(timerISR, "MAIN Timer");timer.startPeriodic(dt_us);
    while (1){
        if (timer.interruptAvailable())
        {
            message_length = uart.available();
            if (e_state == 1)
            {
                if (dir==1){
                COUNT_CLKWISE.set(1);COUNT_CNTCLKWISE.set(0);
                    MOTOR_PWM.setDuty(duty);
                }
                else if (dir==0){
                    COUNT_CLKWISE.set(0);COUNT_CNTCLKWISE.set(1);
                    MOTOR_PWM.setDuty(duty);
                }
                else continue;
            } else {
                MOTOR_PWM.setDuty(0.0);
                COUNT_CLKWISE.set(0);COUNT_CNTCLKWISE.set(0);
            }
            message_length = uart.available();
            if (message_length)
            {
                uart.read(buffer, message_length); // Echo back
                sscanf(buffer, "%d,%d,%f\n", &e_state, &dir, &duty);
            }
        }
    }
}

static void IRAM_ATTR timerISR(void *arg)
{
    timer.setInterrupt();
}