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
uint8_t PWM_PIN[2] = {25, 26};uint8_t PWMCH[2] = {0, 1}; //PWM Channels
HBridge MOTOR_PWM; //HBridge class instance
float duty;

//Quadrature Encoder Stuff
QuadratureEncoder encoder;
uint8_t EncIN[] = {35}; const float degrees_per_edge = 0.06625;

// while Timer Stuff
SimpleTimer timer;
bool flag = false;
uint64_t dt_us = 10000; // 10 ms = 10000 us

//UART Stuff
SimpleUART uart(115200); //UART class
char buffer[30];int message_length;

#endif // __DEFINITIONS_H__