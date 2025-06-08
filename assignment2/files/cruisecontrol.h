#include <stdbool.h>
#include <stdint.h>
#define OFF CRUISE_OFF
#define ON CRUISE_ON
#define STDBY CRUISE_STDBY
#define DISABLE CRUISE_DISABLE
#ifndef CRUISECONTROL_H
#define CRUISECONTROL_H

#define SPEED_MIN 30.0
#define SPEED_MAX 150.0
#define SPEED_INC 2.5
#define PEDAL_MIN 3.0
typedef enum {
    CRUISE_OFF,
    CRUISE_ON,
    CRUISE_STDBY,
    CRUISE_DISABLE
} CruiseState;

void _CruiseState(CruiseState *lhs, CruiseState rhs);
int  _eq_CruiseState(CruiseState lhs, CruiseState rhs);
char* _CruiseState_to_text(CruiseState state);
void _text_to_CruiseState(CruiseState *state, char *text);
int _check_CruiseState(char *text);

float regulateThrottle(int isGoingOn, float cruiseSpeed, float vehicleSpeed);
int isPressed(float *pedal);

#endif // CRUISECONTROL_H