#ifndef USONIC_H
#define USONIC_H

#define NUM_ULTRASONIC_SENSORS      10
#define ULTRASONIC_UPDATE_INTERVAL 100

extern uint32_t ultrasonic_distance[NUM_ULTRASONIC_SENSORS];

extern void     ultrasonic_setup(void);
extern void     ultrasonic_measure(void);

#endif
