#ifndef __DEFINITIONS_H__
#define __DEFINITIONS_H__

#include <stdio.h>
#include <SimpleADC.h>
#include <SimpleTimer.h>
#include <SimpleUART.h>
#include <HBridge.h>
#include <QuadratureEncoder.h>
#include "esp_task_wdt.h" //Watch Dog 
#include "PID.h"

//PID stuff
PID control;
float gains[3] = {0,0,0};
float reference;

//HBridge Stuff
uint8_t PWM_PIN[2] = {25, 26};uint8_t PWMCH[2] = {0, 1}; //PWM Channels
HBridge MOTOR_PWM; //HBridge class instance

//Quadrature Encoder Stuff
QuadratureEncoder encoder;
uint8_t EncIN[] = {35, 34}; const float degrees_per_edge = 0.36437;

// while Timer Stuff
SimpleTimer timer;
bool flag = false;
uint64_t dt_us = 10000; // 10 ms = 10000 us

//UART Stuff
SimpleUART uart(115200); //UART class
char buffer[30];int message_length;

// Control stuff
float duty; 
float Kp; float Ki; float Kd;
float angle; float error; float ref_angle; float U_x;

#endif // __DEFINITIONS_H__