#include <Arduino.h>
#include "main.h"
#include "uplink.h"
#include "usonic.h"
#include "motor.h"
#include "pinout.h"
#include "tools.h"
#include "battery.h"
#include "odometry.h"

//////////////////////
/// Setup function ///
//////////////////////
void setup() {
  tools_setup();
  motor_setup();
  uplink_setup();
  battery_setup();
  odometry_setup();
  ultrasonic_setup();
}

////////////////////
/// Endless loop ///
////////////////////
void loop() {
   uplink_checkReceive();
   motor_control();
   battery_measure();
   ultrasonic_measure();
   uplink_sendData();
}
