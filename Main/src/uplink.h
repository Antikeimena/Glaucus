#ifndef UPLINK_H
#define UPLINK_H

#include <Arduino.h>

#include "config.pb.h"
#include "motor.pb.h"
#include "sensor.pb.h"
#include "status.pb.h"

#define UPLINK_STATUS_INTERVAL   1000
#define UPLINK_SENSOR_INTERVAL   100

enum uplink_states {
                    WAITING_FOR_A,
                    WAITING_FOR_N,
                    WAITING_FOR_S,
                    WAITING_FOR_I,
                    WAITING_FOR_TYPE,
                    WAITING_FOR_SIZE_L,
                    WAITING_FOR_SIZE_H,
                    WAITING_FOR_MESSAGE
                   };

enum uplink_message_types {
                            NOTSET,
                            CONFIG,
                            MOTOR,
                            SENSOR,
                            STATUS
                          };

#define MAX(a,b) ((a) > (b) ? a : b)
#define MIN(a,b) ((a) < (b) ? a : b)

#define BUFFERSIZE MAX(antikeimena_Config_size, MAX(antikeimena_Motor_size, MAX(antikeimena_Sensor_size, antikeimena_Status_size)))

#define UPLINK_SPEED 115200

#define NOTSET_MESSAGE 0
#define CONFIG_MESSAGE 1
#define MOTOR_MESSAGE  2
#define SENSOR_MESSAGE 3
#define STATUS_MESSAGE 4

extern void uplink_setup(void);
extern void uplink_sendData(void);
extern void uplink_checkReceive(void);

#endif
