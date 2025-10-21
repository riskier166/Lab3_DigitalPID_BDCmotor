#include <definitions.h>

static void IRAM_ATTR timerISR(void *arg);

extern "C" void app_main()
{
    esp_task_wdt_deinit();
    encoder.setup(EncIN,degrees_per_edge);
    control.setup(gains,dt_us/1000000.0f);
    MOTOR_PWM.setup(PWM_PIN,PWMCH);
    while (1)
    {
        if (timer.interruptAvailable())
        {
            float measurement = encoder.getAngle();
            float error = reference - measurement;
            float u = control.calc(error);
            MOTOR_PWM.setSpeed(u);
            printf("%.2f,%.2f,%.2f,%.2f\n",measurement,gains[0],gains[1],gains[2]);
            message_length = uart.available();
            if (message_length)
            {
                uart.read(buffer, message_length); // Echo back
                sscanf(buffer, "%f,%f\n", &gains[0], &gains[1], &gains[2], &reference);
                control.setup(gains,dt_us/1000000);
            }
        }
    }
}

static void IRAM_ATTR timerISR(void *arg)
{
    timer.setInterrupt();
}