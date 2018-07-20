#include <Arduino.h>
#include "odometry.h"
#include "pinout.h"
#include "tools.h"

volatile uint32_t odometry_left_counter;
volatile uint32_t odometry_right_counter;

extern void odometry_handle_left(void);
extern void odometry_handle_right(void);

void odometry_setup(void){
    odometry_left_counter  = 0;
    odometry_right_counter = 0;
    pinMode(PIN_ODOMETRY_LEFT_A,  INPUT);
    pinMode(PIN_ODOMETRY_LEFT_B,  INPUT);
    pinMode(PIN_ODOMETRY_RIGHT_A, INPUT);
    pinMode(PIN_ODOMETRY_RIGHT_B, INPUT);
    attachInterrupt(digitalPinToInterrupt(PIN_ODOMETRY_LEFT_A),  odometry_handle_left,  RISING);
    attachInterrupt(digitalPinToInterrupt(PIN_ODOMETRY_RIGHT_A), odometry_handle_right, RISING);
}

void odometry_handle_left(void){
    if (digitalRead(PIN_ODOMETRY_LEFT_B)){
        odometry_left_counter++;
    }else{
        odometry_left_counter--;
    }
}

void odometry_handle_right(void){
    if (digitalRead(PIN_ODOMETRY_RIGHT_B)){
        odometry_right_counter++;
    }else{
        odometry_right_counter--;
    }
}

uint32_t odometry_get_left_counter(void){
    return odometry_left_counter;
}

uint32_t odometry_get_right_counter(void){
    return odometry_right_counter;
}
