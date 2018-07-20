#include <Arduino.h>
#include "motor.h"
#include "pinout.h"
#include "Servo.h"
#include "pinout.h"
#include "tools.h"

Servo motor_left;
Servo motor_right;

uint32_t motor_lastrun    = 0;
uint32_t motor_lastupdate = 0;

uint8_t motor_desired_speed_left  = 90;
uint8_t motor_desired_speed_right = 90;
uint8_t motor_current_speed_left  = 90;
uint8_t motor_current_speed_right = 90;

extern void motor_set_speed(void);

////////////////////////
//////// SETUP /////////
////////////////////////
void motor_setup(void){

  pinMode(PIN_MOTOR_BREAK,      OUTPUT);
  digitalWrite(PIN_MOTOR_BREAK, LOW);   // Motors are blocked at startup

  motor_left.attach(PIN_MOTOR_PWM_LEFT);
  motor_left.write(90); // neutral

  motor_right.attach(PIN_MOTOR_PWM_RIGHT);
  motor_right.write(90); // neutral
}

//////////////////////
/////// LOOP /////////
//////////////////////
void motor_control(void){

    if(must_run(motor_lastrun, MOTOR_CONTROL_INTERVAL)){
        motor_set_speed();
        motor_lastrun = millis();
    }

    if(must_run(motor_lastupdate, MOTOR_STOP_ON_NO_UPDATE)){
        motor_speed(90, 90);
    }

}

///////////////////////////
//////// External /////////
///////////////////////////
void motor_speed(uint8_t speed_left, uint8_t speed_right){
    motor_desired_speed_left  = speed_left;
    motor_desired_speed_right = speed_right;
    motor_lastupdate = millis();
    motor_set_speed();
}

/////////////////////////
/////// Internal ////////
/////////////////////////
void motor_set_speed(void){

    if (abs(motor_desired_speed_left - motor_current_speed_left) < 10){

        motor_current_speed_left = motor_desired_speed_left;

    }else{

        if(motor_desired_speed_left > motor_current_speed_left){
            motor_current_speed_left += 10;
        }else{
            motor_current_speed_left -= 10;
        }

    }

    if (abs(motor_desired_speed_right - motor_current_speed_right) < 10){

        motor_current_speed_right = motor_desired_speed_right;

    }else{

        if(motor_desired_speed_right > motor_current_speed_right){
            motor_current_speed_right += 10;
        }else{
            motor_current_speed_right -= 10;
        }

    }

    if(motor_current_speed_left == 90 && motor_current_speed_right == 90){
        // We set speed here to 0 aka 90 to make sure power is off before we trigger the brake
        motor_left.write(motor_current_speed_left);
        motor_right.write(motor_current_speed_right);
        digitalWrite(PIN_MOTOR_BREAK, LOW);
    }else{
        // We open the break before we apply power to the motors
        digitalWrite(PIN_MOTOR_BREAK, HIGH);
        motor_left.write(motor_current_speed_left);
        motor_right.write(motor_current_speed_right);
    }

}