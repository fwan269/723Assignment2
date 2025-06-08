#include <stdbool.h>
#include "cruisecontrol.h"
#include <stdint.h>



CruiseState init = CRUISE_OFF;

int isPressed(float pedal) {
   if(pedal>3.0){
	return 1;
   } else {
	return 0;
   }
}

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
int _eq_CruiseState(CruiseState lhs, CruiseState rhs){
	
	if(lhs != rhs){
		return 0;
	} else{
		return 1;
	}
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

// Simple function to compare two strings, returns 1 if equal, 0 if not
int my_strcmp(const char *a, const char *b) {
    while (*a && *b) {
        if (*a != *b) return 0;
        a++;
        b++;
    }
    return (*a == '\0' && *b == '\0');
}

void _text_to_CruiseState(CruiseState *state, char *text)
{
    if (my_strcmp(text, "OFF"))
        *state = CRUISE_OFF;
    else if (my_strcmp(text, "ON"))
        *state = CRUISE_ON;
    else if (my_strcmp(text, "STDBY"))
        *state = CRUISE_STDBY;
    else if (my_strcmp(text, "DISABLE"))
        *state = CRUISE_DISABLE;
    else
        *state = CRUISE_OFF; // fallback default
}

int _check_CruiseState(char *text)
{
    return (my_strcmp(text, "OFF") ||
            my_strcmp(text, "ON") ||
            my_strcmp(text, "STDBY") ||
            my_strcmp(text, "DISABLE"));
}