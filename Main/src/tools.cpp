#include <Arduino.h>
#include "tools.h"

void tools_setup(void){
}

uint32_t tools_millis_since(uint32_t in){

    uint32_t now = millis();

    if (in <= now){
        return now - in;
    }else{
        return UINT16_MAX - in + millis();
    }

}

bool must_run(uint32_t in, uint32_t duration){

    if(tools_millis_since(in) > duration){
        return true;
    }else{
        return false;
    }

}