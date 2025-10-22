#include <definitions.h>

static void IRAM_ATTR timerISR(void *arg);

extern "C" void app_main()
{
    esp_task_wdt_deinit();
    encoder.setup(EncIN, degrees_per_edge);
    control.setup(gains, dt_us / 1000000.0f);
    MOTOR_PWM.setup(PWM_PIN, PWMCH);
    timer.setup(timerISR, "MainTimer");timer.startPeriodic(dt_us);
    while (1)
    {
        if (timer.interruptAvailable())
        {
            switch (mode)
            {
            case SPEED_CONTROL: //speed
                measurement = encoder.getSpeed();
                error = reference - measurement;
                u = control.calc(error);
                MOTOR_PWM.setSpeed(u);
                break;
            case ANGULAR_CONTROL: // angle
                measurement = encoder.getAngle();
                error = reference - measurement;
                u = control.calc(error);
                MOTOR_PWM.setSpeed(u);   
                break;       
            case PWM_CONTROL: // duty
                MOTOR_PWM.setSpeed(reference); 
                break; 
            }            
            message_length = uart.available();
            if (message_length)
            {
                uart.read(buffer, message_length); // Echo back
                sscanf(buffer, "%d,%f,%f,%f,%f\n", &mode, &gains[0], &gains[1], &gains[2], &reference);
                //sscanf(buffer, "%f,%f,%f,%f\n", &gains[0], &gains[1], &gains[2], &reference);
                control.setup(gains, dt_us / 1000000.0f);
            }
            //measurement = encoder.getAngle();
            //error = reference - measurement;
            //u = control.calc(error);
            //MOTOR_PWM.setSpeed(u);  
            printf("%.2f,%.2f,%.2f,%.2f\n",u, measurement, encoder.getSpeed(), encoder.getAngle());
        }
    }
}

static void IRAM_ATTR timerISR(void *arg)
{
    timer.setInterrupt();
}