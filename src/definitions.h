#ifndef __DEFINITIONS_H__
#define __DEFINITIONS_H__

#include <stdio.h>
#include <SimplePWM.h>
#include <SimpleGPIO.h>
#include <SimpleADC.h>
#include <SimpleTimer.h>
#include <SimpleUART.h>
#include "esp_task_wdt.h" //Watch Dog 

//Pwm Stuff
const uint8_t PWM_PIN = 32;
const uint8_t PWMCH = 0; //PWM Channels
TimerConfig motor_pwm_config{ // Structure for timer configuration
    .timer = LEDC_TIMER_0, 
    .frequency = 10000, // Frequency in Hz
    .bit_resolution = LEDC_TIMER_8_BIT, 
    .mode = LEDC_LOW_SPEED_MODE 
};
SimplePWM MOTOR_PWM;

// GPIO Stuff
const uint8_t COUNT_CLKW = 25;const uint8_t COUNT_CNTCLKW = 26;const uint8_t Enable_pin = 33;
SimpleGPIO COUNT_CLKWISE;SimpleGPIO COUNT_CNTCLKWISE;SimpleGPIO ENABLE_PIN;

// Timer Stuff
SimpleTimer timer;
bool flag = false;
uint64_t dt_us = 10000; // 10 ms = 10000 us

//Control Stuff 
int e_state;
int dir; 
float duty;

//UART Stuff
SimpleUART uart(115200); //UART class
char buffer[30];int message_length;

#endif // __DEFINITIONS_H__