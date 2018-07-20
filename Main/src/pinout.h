#ifndef PINOUT_H
#define PINOUT_H
 
//https://www.arduino.cc/en/Hacking/PinMapping2560

#define PIN_RESERVED_53       53 // SS
#define PIN_RESERVED_52       52 // SCK
#define PIN_RESERVED_51       51 // MOSI
#define PIN_RESERVED_50       50 // MISO

#define ULTRASONIC_10_TRIGGER 49
#define ULTRASONIC_10_ECHO    48
#define ULTRASONIC_09_TRIGGER 47
#define ULTRASONIC_09_ECHO    46 // PWM
#define ULTRASONIC_08_TRIGGER 45 // PWM
#define ULTRASONIC_08_ECHO    44 // PWM
#define ULTRASONIC_07_TRIGGER 43
#define ULTRASONIC_07_ECHO    42
#define ULTRASONIC_06_TRIGGER 41
#define ULTRASONIC_06_ECHO    40
#define ULTRASONIC_05_TRIGGER 39
#define ULTRASONIC_05_ECHO    38
#define ULTRASONIC_04_TRIGGER 37
#define ULTRASONIC_04_ECHO    36
#define ULTRASONIC_03_TRIGGER 35
#define ULTRASONIC_03_ECHO    34
#define ULTRASONIC_02_TRIGGER 33
#define ULTRASONIC_02_ECHO    32
#define ULTRASONIC_01_TRIGGER 31
#define ULTRASONIC_01_ECHO    30

#define PIN_RESERVED_29       29
#define PIN_RESERVED_28       28
#define PIN_RESERVED_27       27
#define PIN_RESERVED_26       26
#define PIN_RESERVED_25       25
#define PIN_RESERVED_24       24

#define PIN_ODOMETRY_RIGHT_B  23 
#define PIN_ODOMETRY_LEFT_B   22 

#define PIN_SCL               21 // Interrupt enabled
#define PIN_SDA               20 // Interrupt enabled

#define PIN_SERIAL1_RX        19 // Interrupt enabled 
#define PIN_SERIAL1_TX        18 // Interrupt enabled
#define PIN_SERIAL2_TX        17
#define PIN_SERIAL2_RX        16
#define PIN_SERIAL3_TX        15
#define PIN_SERIAL3_RX        14 

#define PIN_BUILD_IN_LED      13 // LED on board
#define PIN_RESERVED_12       12 // PWM
#define PIN_RESERVED_11       11 // PWM
#define PIN_RESERVED_10       10 // PWM
#define PIN_RESERVED_9         9 // PWM
#define PIN_RESERVED_8         8 // PWM
#define PIN_RESERVED_7         7 // PWM

#define PIN_MOTOR_PWM_LEFT     6 // PWM
#define PIN_MOTOR_PWM_RIGHT    5 // PWM
#define PIN_MOTOR_BREAK        4 // PWM

#define PIN_ODOMETRY_RIGHT_A   3 // Interrupt //PWM
#define PIN_ODOMETRY_LEFT_A    2 // Interrupt //PWM

#define PIN_SERIAL0_TX         1
#define PIN_SERIAL0_RX         0

#define PIN_RESERVED_A15     A15
#define PIN_RESERVED_A14     A14
#define PIN_RESERVED_A13     A13
#define PIN_RESERVED_A12     A12
#define PIN_RESERVED_A11     A11
#define PIN_RESERVED_A10     A10
#define PIN_RESERVED_A9       A9
#define PIN_RESERVED_A8       A8
#define PIN_RESERVED_A7       A7
#define PIN_RESERVED_A6       A6
#define PIN_RESERVED_A5       A5
#define PIN_RESERVED_A4       A4
#define PIN_RESERVED_A3       A3
#define PIN_RESERVED_A2       A2
#define PIN_RESERVED_A1       A1
#define PIN_BATTERY           A0

#endif
