#ifndef __DEFINITIONS_H__
#define __DEFINITIONS_H__

#include <stdio.h>
#include <SimpleADC.h>
#include <SimpleTimer.h>
#include <SimpleUART.h>
#include <HBridge.h>
#include <QuadratureEncoder.h>
#include "esp_task_wdt.h" //Watch Dog 

//HBridge Stuff
const uint8_t PWM_PIN = 32;const uint8_t PWMCH = 0; //PWM Channels
const uint8_t COUNT_CLKW = 25;const uint8_t COUNT_CNTCLKW = 26;
HBridge MOTOR_PWM; //HBridge class instance

//Quadrature Encoder Stuff
QuadratureEncoder encoder;
uint8_t EncIN[] = {35}; const float degrees_per_edge = 0.06625;

// while Timer Stuff
SimpleTimer timer;
bool flag = false;
uint64_t dt_us = 10000; // 10 ms = 10000 us

// Read Timer Stuff
SimpleTimer 

//Control Stuff 
int e_state;int dir;float duty;

//UART Stuff
SimpleUART uart(115200); //UART class
char buffer[30];int message_length;

#endif // __DEFINITIONS_H__