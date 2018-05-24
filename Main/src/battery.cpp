#include <Arduino.h>
#include "battery.h"
#include "pinout.h"
#include "tools.h"

float    battery_voltage = 0.0;
uint32_t battery_lastrun =   0;

void battery_setup(void){
}

void battery_measure(void){

    if(must_run(battery_lastrun, BATTERY_CONTROL_INTERVAL)){
        uint64_t val = 0;

        for(uint8_t i = 0; i < BATTERY_MEASURE_NUM; i++){
            val += analogRead(PIN_BATTERY);
        }

        battery_voltage = (val / BATTERY_MEASURE_NUM) * BATTERY_VOLTAGE_FACTOR;
        battery_lastrun = millis();
    }
}
