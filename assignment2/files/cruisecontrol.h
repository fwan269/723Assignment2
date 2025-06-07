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


void _CruiseState(CruiseState *lhs, CruiseState rhs);
int _eq_CruiseState(CruiseState lhs, CruiseState rhs);
char* _CruiseState_to_text(CruiseState state);
void _text_to_CruiseState(CruiseState *state, char *text);
int _check_CruiseState(char *text);

float regulateThrottle(bool isGoingOn, float cruiseSpeed, float vehicleSpeed);
bool isBrakePressed(float brake);
bool isAccelPressed(float accel);