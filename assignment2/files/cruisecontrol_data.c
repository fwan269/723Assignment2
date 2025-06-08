#include <stdbool.h>
#include "cruisecontrol.h"
#include <stdint.h>



CruiseState init = CRUISE_OFF;
//Page 12 lab 1

// void BoolArray ( BoolArray∗ , BoolArray );
// 	int eq_BoolArray ( BoolArray , BoolArray);
// 	char∗ BoolArray_to_text(BoolArray);
// 	void text_to_BoolArray(BoolArray∗, char∗); 
// int check_BoolArray (char∗) ;


//bool isBrakePressed(float brake) {
   // return brake > 3.0;
//}

//bool isAccelPressed(float accel) {
 //   return accel > 3.0;
//}

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
float regulateThrottle(int isGoingOn, float cruiseSpeed, float vehicleSpeed)
{
	static const float KP = 8.113;
	static const float KI = 0.5;
	static bool saturate = true;
	static float iterm = 0;
	
	if (isGoingOn == 1) {
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

// assignment function
void _CruiseState(CruiseState *lhs, CruiseState rhs)
{
	*lhs = rhs;
}

//equality function
int _eq_CruiseState(CruiseState *lhs, CruiseState rhs){
	
	return (*lhs == rhs) ? 1 : 0;
}


//string conversion function 1
char* _CruiseState_to_text(CruiseState state)
{
    switch (state) {
        case CRUISE_OFF:    return "OFF";
        case CRUISE_ON:     return "ON";
        case CRUISE_STDBY:  return "STDBY";
        case CRUISE_DISABLE:return "DISABLE";
        default:     return "UNKNOWN";
    }
}

//string conversion function 2
void _text_to_CruiseState(CruiseState *state, char *text)
{
    if (strcmp(text, "OFF") == 0)
        *state = CRUISE_OFF;
    else if (strcmp(text, "ON") == 0)
        *state = CRUISE_ON;
    else if (strcmp(text, "STDBY") == 0)
        *state = CRUISE_STDBY;
    else if (strcmp(text, "DISABLE") == 0)
        *state = CRUISE_DISABLE;
    else
        *state = CRUISE_OFF; // fallback default
}

//string conversion function 3
int _check_CruiseState(char *text)
{
    return (strcmp(text, "OFF") == 0 ||
            strcmp(text, "ON") == 0 ||
            strcmp(text, "STDBY") == 0 ||
            strcmp(text, "DISABLE") == 0);
}