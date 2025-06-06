#include <stdbool.h>

#define SPEED_MIN 30.0
#define SPEED_MAX 150.0
#define SPEED_INC 2.5
#define PEDAL_MIN 3.0

float regulateThrottle(int isGoingOn, float cruiseSpeed, float vehicleSpeed);
bool isBrakePressed(float brake);
bool isAccelPressed(float accel);