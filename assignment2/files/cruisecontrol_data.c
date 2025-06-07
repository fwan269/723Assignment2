#include <stdbool.h>



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


#include <stdbool.h>


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


void CruiseControl_off(bool On, bool Off, bool Resume, bool Set, bool QuickDecel, bool QuickAccel,
				   float Accel, float Brake, float Speed, float CruiseSpeed, 
				   float ThrottleCmd, CruiseState cruiseState, int isGoingOn){
	
	float cruiseLast = 0;

	if(On){
		cruiseState = ON;
		isGoingOn = 1;
		CruiseSpeed = Speed;
		cruiseLast = CruiseSpeed;
	} else {
		//manual operation
	}

}

void CruiseControl_on(bool On, bool Off, bool Resume, bool Set, bool QuickDecel, bool QuickAccel,
				   float Accel, float Brake, float Speed, float CruiseSpeed, 
				   float ThrottleCmd, CruiseState cruiseState, int isGoingOn) {

	if(Off){
			cruiseState = OFF;
		} else if (isBrakePressed(Brake)){
			cruiseState = STDBY;
		} else if (isAccelPressed(Accel)){
			cruiseState = DISABLE;
		} else {
			if(Set){
				if(Set>150){
					CruiseSpeed=150;
				} else if(Set<30){
					CruiseSpeed=30;
				} else {
					CruiseSpeed=Speed;
				}
			} else if(QuickAccel){
				CruiseSpeed += 2.5;
				if(CruiseSpeed>150){
					cruiseState = DISABLE;
				}
				cruiseLast = CruiseSpeed;
			} else if(QuickDecel){
				CruiseSpeed -= 2.5;
				if(CruiseSpeed<30){
					cruiseState = DISABLE;
				}
				cruiseLast = CruiseSpeed;
			}
			ThrottleCmd = regulateThrottle(isGoingOn,CruiseSpeed,Speed);
			isGoingOn=0;
		}

}

void CruiseControl_disable(bool On, bool Off, bool Resume, bool Set, bool QuickDecel, bool QuickAccel,
				   float Accel, float Brake, float Speed, float CruiseSpeed, 
				   float ThrottleCmd, CruiseState cruiseState, int isGoingOn) {
	
	if(Off){
			cruiseState = OFF;
		} else if(!(isAccelPressed(Accel)) || (30<Speed<150)){
			cruiseState = ON;
			CruiseSpeed = cruiseLast;
		}

}


void CruiseControl_STDBY(bool On, bool Off, bool Resume, bool Set, bool QuickDecel, bool QuickAccel,
				   float Accel, float Brake, float Speed, float CruiseSpeed, 
				   float ThrottleCmd, CruiseState cruiseState, int isGoingOn) {

	if(Off){
			cruiseState = OFF;
		}else if(Resume){
			if(isAccelPressed(Accel) || !(30<Speed<150)){
				cruiseState = DISABLE;
			}else{
				cruiseState = ON;
				CruiseSpeed = cruiseLast;
			}
		}

}




void CruiseControl(bool On, bool Off, bool Resume, bool Set, bool QuickDecel, bool QuickAccel,
				   float Accel, float Brake, float Speed, float CruiseSpeed, 
				   float ThrottleCmd, CruiseState cruiseState, int isGoingOn) {
	float cruiseLast = 0;

	switch(cruiseState){
		case OFF:
		if(On){
			cruiseState = ON;
			isGoingOn = 1;
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
				if(Set>150){
					CruiseSpeed=150;
				} else if(Set<30){
					CruiseSpeed=30;
				} else {
					CruiseSpeed=Speed;
				}
			} else if(QuickAccel){
				CruiseSpeed += 2.5;
				if(CruiseSpeed>150){
					cruiseState = DISABLE;
				}
				cruiseLast = CruiseSpeed;
			} else if(QuickDecel){
				CruiseSpeed -= 2.5;
				if(CruiseSpeed<30){
					cruiseState = DISABLE;
				}
				cruiseLast = CruiseSpeed;
			}
			ThrottleCmd = regulateThrottle(isGoingOn,CruiseSpeed,Speed);
			isGoingOn=0;
		}
		break;

		case DISABLE:
		if(Off){
			cruiseState = OFF;
		} else if(!(isAccelPressed(Accel)) || (30<Speed<150)){
			cruiseState = ON;
			CruiseSpeed = cruiseLast;
		}
		break;

		case STDBY:
		if(Off){
			cruiseState = OFF;
		}else if(Resume){
			if(isAccelPressed(Accel) || !(30<Speed<150)){
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

	bool isGoingOn = 0;

	while (1){
		CruiseControl(On, Off, Resume, Set, QuickDecel, QuickAccel, Accel, Brake, Speed, CruiseSpeed, ThrottleCmd, cruiseState, isGoingOn);
	}
}