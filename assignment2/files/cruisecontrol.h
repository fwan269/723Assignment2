#include <stdbool.h>
#ifndef MYFUNCTIONS_H
#define MYFUNCTIONS_H
typedef enum {
    OFF,
    ON,
    STDBY,
    DISABLE
} CruiseState;

typedef struct {
    float CruiseSpeed;
    float ThrottleCmd;
    CruiseState cruiseState;
    int isGoingOn;
    float lastCruiseSpeed;
} CruiseControlState;

void CruiseControl(
    int On,
    int Off,
    int Resume,
    int Set,
    int QuickDecel,
    int QuickAccel,
    int Accel,
    int Brake,
    float Speed,
    float CruiseSpeed,
    float *ThrottleCmd,
    CruiseState *cruiseState,
    int *isGoingOn
);


#define SPEED_MIN 30.0
#define SPEED_MAX 150.0
#define SPEED_INC 2.5
#define PEDAL_MIN 3.0

float regulateThrottle(bool isGoingOn, float cruiseSpeed, float vehicleSpeed);
bool isBrakePressed(float brake);
bool isAccelPressed(float accel);
#endif