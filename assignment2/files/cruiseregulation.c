#include <stdbool.h>

typedef enum {
    CRUISE_OFF,
    CRUISE_ON,
    CRUISE_STDBY,
    CRUISE_DISABLE
} CruiseState;

typedef struct {
    bool On;
    bool Off;
    bool Resume;
    bool Set;
    bool QuickDecel;
    bool QuickAccel;
    float Accel;   // Accelerator pedal sensor
    float Brake;   // Brake pedal sensor
    float Speed;   // Vehicle speed
} CruiseInput;

typedef struct {
    float CruiseSpeed;
    float ThrottleCmd;
    CruiseState State;
} CruiseOutput;

#define SPEED_MIN 30.0
#define SPEED_MAX 150.0
#define SPEED_INC 2.5
#define PEDAL_MIN 3.0


/*
DESCRIPTION: Saturate the throttle command to limit the acceleration.
PARAMETERS: throttleIn - throttle input
            saturate - true if saturated, false otherwise
RETURNS: throttle output (ThrottleCmd)
*/
float saturateThrottle(float throttleIn, bool* saturate)
{
	static const float THROTTLESATMAX = 45.0;
	if (throttleIn > THROTTLESATMAX) {
		*saturate = true;
		return THROTTLESATMAX;
	}
	else if (throttleIn < 0) {
		*saturate = true;
		return 0;
	}
	else {
		*saturate = false;
		return throttleIn;
	}
}

/*
DESCRIPTION: Saturate the throttle command to limit the acceleration.
PARAMETERS: isGoingOn - true if the cruise control has just gone into the ON state 
                        from another state; false otherwise
            saturate - true if saturated, false otherwise
RETURNS: throttle output (ThrottleCmd)
*/
float regulateThrottle(bool isGoingOn, float cruiseSpeed, float vehicleSpeed)
{
	static const float KP = 8.113;
	static const float KI = 0.5;
	static bool saturate = true;
	static float iterm = 0;
	
	if (isGoingOn) {
		iterm = 0;	// reset the integral action
		saturate = true;	
	}
	float error = cruiseSpeed - vehicleSpeed;
	float proportionalAction = error * KP;
	if (saturate)
		error = 0;	// integral action is hold when command is saturated
	iterm = iterm + error;
	float integralAction = KI * iterm;
	return saturateThrottle(proportionalAction + integralAction, &saturate);
}
