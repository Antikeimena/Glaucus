#ifndef BATTERY_H
#define BATTERY_H

#define BATTERY_MEASURE_NUM                 100.0
#define BATTERY_VOLTAGE_FACTOR     (10.0 /  232.0)
#define BATTERY_CONTROL_INTERVAL   (10   * 1000)

extern float battery_voltage;

extern void  battery_setup(void);
extern void  battery_measure(void);

#endif
