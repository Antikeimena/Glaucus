#include <Arduino.h>
#include "odometry.h"
#include "pinout.h"
#include "tools.h"

volatile uint16_t odometry_left_counter;
volatile uint16_t odometry_right_counter;

extern void odometry_handle_left(void);
extern void odometry_handle_right(void);

void odometry_setup(void){
    odometry_left_counter  = 0;
    odometry_right_counter = 0;
    pinMode(PIN_ODOMETRY_LEFT,  INPUT);
    pinMode(PIN_ODOMETRY_RIGHT, INPUT);
    attachInterrupt(digitalPinToInterrupt(PIN_ODOMETRY_LEFT),  odometry_handle_left,  RISING);
    attachInterrupt(digitalPinToInterrupt(PIN_ODOMETRY_RIGHT), odometry_handle_right, RISING);
}

void odometry_handle_left(void){
    odometry_left_counter++;
}

void odometry_handle_right(void){
    odometry_right_counter++;
}

uint16_t odometry_get_left_counter(void){
    uint16_t val = odometry_left_counter;
    odometry_left_counter = 0;
    return val;
}

uint16_t odometry_get_right_counter(void){
    uint16_t val = odometry_right_counter;
    odometry_right_counter = 0;
    return val;
}
