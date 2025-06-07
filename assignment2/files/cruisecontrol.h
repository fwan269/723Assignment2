#include <stdbool.h>

#define SPEED_MIN 30.0
#define SPEED_MAX 150.0
#define SPEED_INC 2.5
#define PEDAL_MIN 3.0
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

void CruiseControl(bool On, bool Off, bool Resume, bool Set, bool QuickDecel, bool QuickAccel,
				   float Accel, float Brake, float Speed, float CruiseSpeed, 
				   float ThrottleCmd, CruiseState cruiseState, int isGoingOn); 




float regulateThrottle(bool isGoingOn, float cruiseSpeed, float vehicleSpeed);
bool isBrakePressed(float brake);
bool isAccelPressed(float accel);