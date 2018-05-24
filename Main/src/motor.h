#ifndef MOTOR_H
#define MOTOR_H

#define MOTOR_CONTROL_INTERVAL   100
#define MOTOR_STOP_ON_NO_UPDATE 5000

extern void motor_setup(void);
extern void motor_control(void);
extern void motor_speed(uint8_t speed_left, uint8_t speed_right);

#endif
