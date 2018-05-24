#include <Arduino.h>
#include "usonic.h"
#include "pinout.h"
#include "tools.h"
#include <Ultrasonic.h>

uint32_t ultrasonic_lastrun = 0;
uint32_t ultrasonic_distance[NUM_ULTRASONIC_SENSORS];
uint8_t  ultrasonic_index   = 0;

Ultrasonic ultrasonic_uss[NUM_ULTRASONIC_SENSORS] = {
                                  Ultrasonic(ULTRASONIC_01_TRIGGER, ULTRASONIC_01_ECHO),
                                  Ultrasonic(ULTRASONIC_02_TRIGGER, ULTRASONIC_02_ECHO),
                                  Ultrasonic(ULTRASONIC_03_TRIGGER, ULTRASONIC_03_ECHO),
                                  Ultrasonic(ULTRASONIC_04_TRIGGER, ULTRASONIC_04_ECHO),
                                  Ultrasonic(ULTRASONIC_05_TRIGGER, ULTRASONIC_05_ECHO),
                                  Ultrasonic(ULTRASONIC_06_TRIGGER, ULTRASONIC_06_ECHO),
                                  Ultrasonic(ULTRASONIC_07_TRIGGER, ULTRASONIC_07_ECHO),
                                  Ultrasonic(ULTRASONIC_08_TRIGGER, ULTRASONIC_08_ECHO),
                                  Ultrasonic(ULTRASONIC_09_TRIGGER, ULTRASONIC_09_ECHO),
                                  Ultrasonic(ULTRASONIC_10_TRIGGER, ULTRASONIC_10_ECHO)
                                 };

void ultrasonic_setup(void){
}

void ultrasonic_measure(void){
    if(must_run(ultrasonic_lastrun, ULTRASONIC_UPDATE_INTERVAL)){
        ultrasonic_distance[ultrasonic_index] = ultrasonic_uss[ultrasonic_index].distanceRead();
        ultrasonic_index++;

        if(ultrasonic_index > (NUM_ULTRASONIC_SENSORS - 1)){
          ultrasonic_index = 0;
        }
        ultrasonic_lastrun = millis();
    }
}
