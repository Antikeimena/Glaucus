#ifndef ODOMETRY_H
#define ODOMETRY_H

#include <Arduino.h>

extern void     odometry_setup(void);
extern uint16_t odometry_get_left_counter(void);
extern uint16_t odometry_get_right_counter(void);

#endif
