#include <definitions.h>

static void IRAM_ATTR timerISR(void *arg);

extern "C" void app_main()
{
    esp_task_wdt_deinit();
    MOTOR_PWM.setup(PWM_PIN, PWMCH);
    timer.setup(timerISR, "MAIN Timer");timer.startPeriodic(dt_us);
    encoder.setup(EncIN, degrees_per_edge);
    while (1){
        if (timer.interruptAvailable())
        {
            message_length = uart.available();
            MOTOR_PWM.setSpeed(duty);
            if (message_length)
            {
                uart.read(buffer, message_length); // Echo back
                sscanf(buffer, "%f\n", &duty);
            }
            //printf("%.2f, %.2f\n", encoder.getSpeed());
        }
    }
}

static void IRAM_ATTR timerISR(void *arg)
{
    timer.setInterrupt();
}