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
    bool isGoingOn;
    float lastCruiseSpeed;
} CruiseControlState;


#include <stdbool.h>


//Page 12 lab 1

// void BoolArray ( BoolArray∗ , BoolArray );
// 	int eq_BoolArray ( BoolArray , BoolArray);
// 	char∗ BoolArray_to_text(BoolArray);
// 	void text_to_BoolArray(BoolArray∗, char∗); 
// int check_BoolArray (char∗) ;


bool isBrakePressed(float brake) {
    return brake > PEDAL_MIN;
}

bool isAccelPressed(float accel) {
    return accel > PEDAL_MIN;
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

void CruiseControl(bool On, bool Off, bool Resume, bool Set, bool QuickDecel, bool QuickAccel,
				   float Accel, float Brake, float Speed, float CruiseSpeed, 
				   float ThrottleCmd, CruiseState cruiseState, bool isGoingOn) {
	float cruiseLast = 0;

	switch(cruiseState){
		case OFF:
		if(On){
			cruiseState = ON;
			isGoingOn = true;
			CruiseSpeed = Speed;
			cruiseLast = CruiseSpeed;
		} else {
			//manual operation
		}
		break;

		case ON:
		if(Off){
			cruiseState = OFF;
		} else if (isBrakePressed(Brake)){
			cruiseState = STDBY;
		} else if (isAccelPressed(Accel)){
			cruiseState = DISABLE;
		} else {
			if(Set){
				if(Set>SPEED_MAX){
					CruiseSpeed=SPEED_MAX;
				} else if(Set<SPEED_MIN){
					CruiseSpeed=SPEED_MIN;
				} else {
					CruiseSpeed=Speed;
				}
			} else if(QuickAccel){
				CruiseSpeed += SPEED_INC;
				if(CruiseSpeed>SPEED_MAX){
					cruiseState = DISABLE;
				}
				cruiseLast = CruiseSpeed;
			} else if(QuickDecel){
				CruiseSpeed -= SPEED_INC;
				if(CruiseSpeed<SPEED_MIN){
					cruiseState = DISABLE;
				}
				cruiseLast = CruiseSpeed;
			}
			ThrottleCmd = regulateThrottle(isGoingOn,CruiseSpeed,Speed);
			isGoingOn=false;
		}
		break;

		case DISABLE:
		if(Off){
			cruiseState = OFF;
		} else if(!(isAccelPressed(Accel)) || (SPEED_MIN<Speed<SPEED_MAX)){
			cruiseState = ON;
			CruiseSpeed = cruiseLast;
		}
		break;

		case STDBY:
		if(Off){
			cruiseState = OFF;
		}else if(Resume){
			if(isAccelPressed(Accel) || !(SPEED_MIN<Speed<SPEED_MAX)){
				cruiseState = DISABLE;
			}else{
				cruiseState = ON;
				CruiseSpeed = cruiseLast;
			}
		}
		break;
	}
}

int main(){

	bool On = false;
	bool Off = true;
	bool Resume = false;
	bool Set = false;
	bool QuickDecel = false;
	bool QuickAccel = false;
	float Accel = 0.0;   // Accelerator pedal sensor
	float Brake = 0.0;   // Brake pedal sensor
	float Speed = 0.0;   // Vehicle speed
	float CruiseSpeed = 0.0;
	float ThrottleCmd = 0.0;
	CruiseState cruiseState = OFF;

	bool isGoingOn = false;

	while (1){
		CruiseControl(On, Off, Resume, Set, QuickDecel, QuickAccel, Accel, Brake, Speed, CruiseSpeed, ThrottleCmd, cruiseState, isGoingOn);
	}
}