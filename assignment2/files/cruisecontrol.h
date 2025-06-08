
#include <stdbool.h>
#include <stdint.h>
//defien the states for off on stdby disanle for crusie controll
#define OFF CRUISE_OFF
#define ON CRUISE_ON
#define STDBY CRUISE_STDBY
#define DISABLE CRUISE_DISABLE

//crusie control loop
#ifndef CRUISECONTROL_H
#define CRUISECONTROL_H

#define SPEED_MIN 30.0
#define SPEED_MAX 150.0
#define SPEED_INC 2.5
#define PEDAL_MIN 3.0
#define SPEED_INT 0.0

//enum for the crusie states 
typedef enum {
    CRUISE_OFF,
    CRUISE_ON,
    CRUISE_STDBY,
    CRUISE_DISABLE
} CruiseState;

//5 helper functions to initialize the type for esteral as it does not supprrt this 
void _CruiseState(CruiseState *lhs, CruiseState rhs);
int  _eq_CruiseState(CruiseState lhs, CruiseState rhs);
char* _CruiseState_to_text(CruiseState state);
void _text_to_CruiseState(CruiseState *state, char *text);
int _check_CruiseState(char *text);


// function for regulating the throttle and if the pedel is pressed.
float regulateThrottle(int isGoingOn, float cruiseSpeed, float vehicleSpeed);
int isPressed(float pedal);

#endif // CRUISECONTROL_H