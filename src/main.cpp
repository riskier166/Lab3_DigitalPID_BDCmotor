#include <definitions.h>

static void IRAM_ATTR timerISR(void *arg);

extern "C" void app_main()
{
    esp_task_wdt_deinit();
    MOTOR_PWM.setup(PWM_PIN, PWMCH, COUNT_CLKW, COUNT_CNTCLKW);
    timer.setup(timerISR, "MAIN Timer");timer.startPeriodic(dt_us);
    while (1){
        if (timer.interruptAvailable())
        {
            message_length = uart.available();
            if (e_state == 1)
            {
                MOTOR_PWM.setSpeed(duty, dir);
            } else {
                MOTOR_PWM.setStop();
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