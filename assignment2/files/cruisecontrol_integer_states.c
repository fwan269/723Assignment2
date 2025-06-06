/* sscc : C CODE OF SORTED EQUATIONS CruiseControl - INLINE MODE */

/* AUXILIARY DECLARATIONS */

#ifndef STRLEN
#define STRLEN 81
#endif
#define _COND(A,B,C) ((A)?(B):(C))
#ifdef TRACE_ACTION
#include <stdio.h>
#endif
#ifndef NULL
#define NULL ((char*)0)
#endif

#ifndef __EXEC_STATUS_H_LOADED
#define __EXEC_STATUS_H_LOADED

typedef struct {
unsigned int start:1;
unsigned int kill:1;
unsigned int active:1;
unsigned int suspended:1;
unsigned int prev_active:1;
unsigned int prev_suspended:1;
unsigned int exec_index;
unsigned int task_exec_index;
void (*pStart)();
void (*pRet)();
} __ExecStatus;

#endif
#define __ResetExecStatus(status) {\
   status.prev_active = status.active; \
   status.prev_suspended = status.suspended; \
   status.start = status.kill = status.active = status.suspended = 0; }
#define __DSZ(V) (--(V)<=0)
#define BASIC_TYPES_DEFINED
typedef int boolean;
typedef int integer;
typedef char* string;
#define _true 1
#define _false 0
#define __CruiseControl_GENERIC_TEST(TEST) return TEST;
typedef void (*__CruiseControl_APF)();
static __CruiseControl_APF *__CruiseControl_PActionArray;

#include "cruisecontrol_integer_states.h"

/* EXTERN DECLARATIONS */

#ifndef _NO_EXTERN_DEFINITIONS
#ifndef _NO_CONSTANT_DEFINITIONS
#ifndef _SPEED_MIN_DEFINED
#ifndef SPEED_MIN
extern float SPEED_MIN;
#endif
#endif
#ifndef _SPEED_MAX_DEFINED
#ifndef SPEED_MAX
extern float SPEED_MAX;
#endif
#endif
#ifndef _SPEED_INC_DEFINED
#ifndef SPEED_INC
extern float SPEED_INC;
#endif
#endif
#endif
#ifndef _NO_FUNCTION_DEFINITIONS
#ifndef _regulateThrottle_DEFINED
#ifndef regulateThrottle
extern float regulateThrottle(integer ,float ,float);
#endif
#endif
#ifndef _isPressed_DEFINED
#ifndef isPressed
extern boolean isPressed(float);
#endif
#endif
#endif
#endif

/* INITIALIZED CONSTANTS */

/* MEMORY ALLOCATION */

static boolean __CruiseControl_V0;
static boolean __CruiseControl_V1;
static boolean __CruiseControl_V2;
static boolean __CruiseControl_V3;
static boolean __CruiseControl_V4;
static boolean __CruiseControl_V5;
static float __CruiseControl_V6;
static boolean __CruiseControl_V7;
static float __CruiseControl_V8;
static boolean __CruiseControl_V9;
static float __CruiseControl_V10;
static boolean __CruiseControl_V11;
static float __CruiseControl_V12;
static float __CruiseControl_V13;
static integer __CruiseControl_V14;
static integer __CruiseControl_V15;
static float __CruiseControl_V16;
static float __CruiseControl_V17;
static integer __CruiseControl_V18;


/* INPUT FUNCTIONS */

void CruiseControl_I_OnMain () {
__CruiseControl_V0 = _true;
}
void CruiseControl_I_OffMain () {
__CruiseControl_V1 = _true;
}
void CruiseControl_I_ResumeMain () {
__CruiseControl_V2 = _true;
}
void CruiseControl_I_SetMain () {
__CruiseControl_V3 = _true;
}
void CruiseControl_I_QuickDecelMain () {
__CruiseControl_V4 = _true;
}
void CruiseControl_I_QuickAccelMain () {
__CruiseControl_V5 = _true;
}
void CruiseControl_I_AccelMain (float __V) {
__CruiseControl_V6 = __V;
__CruiseControl_V7 = _true;
}
void CruiseControl_I_BrakeMain (float __V) {
__CruiseControl_V8 = __V;
__CruiseControl_V9 = _true;
}
void CruiseControl_I_SpeedMain (float __V) {
__CruiseControl_V10 = __V;
__CruiseControl_V11 = _true;
}

/* ACTIONS */

/* PREDEFINED ACTIONS */

/* PRESENT SIGNAL TESTS */

#define __CruiseControl_A1 \
__CruiseControl_V0
#define __CruiseControl_A2 \
__CruiseControl_V1
#define __CruiseControl_A3 \
__CruiseControl_V2
#define __CruiseControl_A4 \
__CruiseControl_V3
#define __CruiseControl_A5 \
__CruiseControl_V4
#define __CruiseControl_A6 \
__CruiseControl_V5
#define __CruiseControl_A7 \
__CruiseControl_V7
#define __CruiseControl_A8 \
__CruiseControl_V9
#define __CruiseControl_A9 \
__CruiseControl_V11

/* OUTPUT ACTIONS */

#define __CruiseControl_A10 \
CruiseControl_O_CruiseSpeedMain(__CruiseControl_V12)
#define __CruiseControl_A11 \
CruiseControl_O_ThrottleCmdMain(__CruiseControl_V13)
#define __CruiseControl_A12 \
CruiseControl_O_CruiseStateMain(__CruiseControl_V14)

/* ASSIGNMENTS */

#define __CruiseControl_A13 \
__CruiseControl_V0 = _false
#define __CruiseControl_A14 \
__CruiseControl_V1 = _false
#define __CruiseControl_A15 \
__CruiseControl_V2 = _false
#define __CruiseControl_A16 \
__CruiseControl_V3 = _false
#define __CruiseControl_A17 \
__CruiseControl_V4 = _false
#define __CruiseControl_A18 \
__CruiseControl_V5 = _false
#define __CruiseControl_A19 \
__CruiseControl_V7 = _false
#define __CruiseControl_A20 \
__CruiseControl_V9 = _false
#define __CruiseControl_A21 \
__CruiseControl_V11 = _false
#define __CruiseControl_A22 \
__CruiseControl_V15 = 0
#define __CruiseControl_A23 \
__CruiseControl_V16 = __CruiseControl_V10
#define __CruiseControl_A24 \
__CruiseControl_V12 = __CruiseControl_V16
#define __CruiseControl_A25 \
__CruiseControl_V17 = __CruiseControl_V16
#define __CruiseControl_A26 \
__CruiseControl_V15 = 1
#define __CruiseControl_A27 \
__CruiseControl_V18 = 1
#define __CruiseControl_A28 \
__CruiseControl_V15 = 0
#define __CruiseControl_A29 \
__CruiseControl_V14 = __CruiseControl_V15
#define __CruiseControl_A30 \
__CruiseControl_V15 = 2
#define __CruiseControl_A31 \
__CruiseControl_V14 = __CruiseControl_V15
#define __CruiseControl_A32 \
__CruiseControl_V15 = 3
#define __CruiseControl_A33 \
__CruiseControl_V14 = __CruiseControl_V15
#define __CruiseControl_A34 \
__CruiseControl_V16 = SPEED_MIN
#define __CruiseControl_A35 \
__CruiseControl_V16 = SPEED_MAX
#define __CruiseControl_A36 \
__CruiseControl_V16 = __CruiseControl_V10
#define __CruiseControl_A37 \
__CruiseControl_V16 = __CruiseControl_V16+SPEED_INC
#define __CruiseControl_A38 \
__CruiseControl_V15 = 3
#define __CruiseControl_A39 \
__CruiseControl_V16 = __CruiseControl_V16-SPEED_INC
#define __CruiseControl_A40 \
__CruiseControl_V15 = 3
#define __CruiseControl_A41 \
__CruiseControl_V13 = regulateThrottle(__CruiseControl_V18, __CruiseControl_V16, __CruiseControl_V10)
#define __CruiseControl_A42 \
__CruiseControl_V18 = 0
#define __CruiseControl_A43 \
__CruiseControl_V14 = __CruiseControl_V15
#define __CruiseControl_A44 \
__CruiseControl_V15 = 0
#define __CruiseControl_A45 \
__CruiseControl_V15 = 3
#define __CruiseControl_A46 \
__CruiseControl_V15 = 1
#define __CruiseControl_A47 \
__CruiseControl_V16 = __CruiseControl_V17
#define __CruiseControl_A48 \
__CruiseControl_V15 = 0
#define __CruiseControl_A49 \
__CruiseControl_V15 = 1
#define __CruiseControl_A50 \
__CruiseControl_V16 = __CruiseControl_V17
#define __CruiseControl_A51 \
__CruiseControl_V14 = __CruiseControl_V15
#define __CruiseControl_A52 \
__CruiseControl_V12 = __CruiseControl_V16

/* PROCEDURE CALLS */

/* CONDITIONS */

#define __CruiseControl_A53 \
__CruiseControl_V15==0
#define __CruiseControl_A54 \
__CruiseControl_V15==1
#define __CruiseControl_A55 \
isPressed(__CruiseControl_V8)
#define __CruiseControl_A56 \
isPressed(__CruiseControl_V6)
#define __CruiseControl_A57 \
__CruiseControl_V10<SPEED_MIN
#define __CruiseControl_A58 \
__CruiseControl_V10>SPEED_MAX
#define __CruiseControl_A59 \
__CruiseControl_V16>SPEED_MAX
#define __CruiseControl_A60 \
__CruiseControl_V16<SPEED_MIN
#define __CruiseControl_A61 \
__CruiseControl_V15==2
#define __CruiseControl_A62 \
isPressed(__CruiseControl_V6)||!(((__CruiseControl_V10>SPEED_MIN)&&(__CruiseControl_V10<SPEED_MAX)))
#define __CruiseControl_A63 \
__CruiseControl_V15==3
#define __CruiseControl_A64 \
!(isPressed(__CruiseControl_V6))&&(__CruiseControl_V10>SPEED_MIN)&&(__CruiseControl_V10<SPEED_MAX)

/* DECREMENTS */

/* START ACTIONS */

/* KILL ACTIONS */

/* SUSPEND ACTIONS */

/* ACTIVATE ACTIONS */

/* WRITE ARGS ACTIONS */

/* RESET ACTIONS */

#define __CruiseControl_A65 \

#define __CruiseControl_A66 \

#define __CruiseControl_A67 \

#define __CruiseControl_A68 \

#define __CruiseControl_A69 \

#define __CruiseControl_A70 \

#define __CruiseControl_A71 \

#define __CruiseControl_A72 \

#define __CruiseControl_A73 \


/* ACTION SEQUENCES */

/* FUNCTIONS RETURNING NUMBER OF EXEC */

int CruiseControl_number_of_execs () {
return (0);
}


/* AUTOMATON (STATE ACTION-TREES) */



static void __CruiseControl__reset_input () {
__CruiseControl_V0 = _false;
__CruiseControl_V1 = _false;
__CruiseControl_V2 = _false;
__CruiseControl_V3 = _false;
__CruiseControl_V4 = _false;
__CruiseControl_V5 = _false;
__CruiseControl_V7 = _false;
__CruiseControl_V9 = _false;
__CruiseControl_V11 = _false;
}

/* REDEFINABLE BIT TYPE */

#ifndef __SSC_BIT_TYPE_DEFINED
typedef char __SSC_BIT_TYPE;
#endif

/* REGISTER VARIABLES */

static __SSC_BIT_TYPE __CruiseControl_R[2] = {_true,
 _false};

/* AUTOMATON ENGINE */

int CruiseControl () {
/* AUXILIARY VARIABLES */

static __SSC_BIT_TYPE E[25];
E[0] = __CruiseControl_R[0]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 7\n"),
#endif
__CruiseControl_A7));
if (E[0]) {
__CruiseControl_A65;
#ifdef TRACE_ACTION
fprintf(stderr, "__CruiseControl_A65\n");
#endif
}
E[1] = __CruiseControl_R[0]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 8\n"),
#endif
__CruiseControl_A8));
if (E[1]) {
__CruiseControl_A66;
#ifdef TRACE_ACTION
fprintf(stderr, "__CruiseControl_A66\n");
#endif
}
E[2] = __CruiseControl_R[0]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 9\n"),
#endif
__CruiseControl_A9));
if (E[2]) {
__CruiseControl_A67;
#ifdef TRACE_ACTION
fprintf(stderr, "__CruiseControl_A67\n");
#endif
}
if (__CruiseControl_R[0]) {
__CruiseControl_A68;
#ifdef TRACE_ACTION
fprintf(stderr, "__CruiseControl_A68\n");
#endif
}
E[3] = __CruiseControl_R[1]&&!(__CruiseControl_R[0]);
E[4] = E[3]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 53\n"),
#endif
__CruiseControl_A53);
E[5] = E[4]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__CruiseControl_A1);
E[6] = E[5]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 9\n"),
#endif
__CruiseControl_A9);
if (E[6]) {
__CruiseControl_A23;
#ifdef TRACE_ACTION
fprintf(stderr, "__CruiseControl_A23\n");
#endif
}
if (E[6]) {
__CruiseControl_A24;
#ifdef TRACE_ACTION
fprintf(stderr, "__CruiseControl_A24\n");
#endif
}
E[5] = E[5]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 9\n"),
#endif
__CruiseControl_A9));
E[7] = E[4]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__CruiseControl_A1));
E[4] = E[5]||E[7]||(E[3]&&!(E[4]));
E[3] = E[4]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 54\n"),
#endif
__CruiseControl_A54);
E[4] = E[4]&&!(E[3]);
E[7] = E[4]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 61\n"),
#endif
__CruiseControl_A61);
E[5] = E[7]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__CruiseControl_A2));
E[8] = E[5]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 3\n"),
#endif
__CruiseControl_A3));
E[4] = E[8]||(E[4]&&!(E[7]));
E[8] = E[4]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 63\n"),
#endif
__CruiseControl_A63);
E[9] = E[8]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__CruiseControl_A2));
E[10] = E[9]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 64\n"),
#endif
__CruiseControl_A64);
E[4] = (E[9]&&!(E[10]))||(E[4]&&!(E[8]));
if (E[4]) {
__CruiseControl_A51;
#ifdef TRACE_ACTION
fprintf(stderr, "__CruiseControl_A51\n");
#endif
}
if (E[4]) {
__CruiseControl_A52;
#ifdef TRACE_ACTION
fprintf(stderr, "__CruiseControl_A52\n");
#endif
}
if (E[6]||E[4]) {
__CruiseControl_A10;
#ifdef TRACE_ACTION
fprintf(stderr, "__CruiseControl_A10\n");
#endif
}
if (__CruiseControl_R[0]) {
__CruiseControl_A69;
#ifdef TRACE_ACTION
fprintf(stderr, "__CruiseControl_A69\n");
#endif
}
E[9] = E[3]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__CruiseControl_A2));
E[11] = E[9]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 8\n"),
#endif
__CruiseControl_A8);
E[12] = E[11]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 55\n"),
#endif
__CruiseControl_A55);
E[9] = E[9]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 8\n"),
#endif
__CruiseControl_A8));
E[9] = (E[11]&&!(E[12]))||E[9];
E[11] = E[9]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 7\n"),
#endif
__CruiseControl_A7);
E[13] = E[11]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 56\n"),
#endif
__CruiseControl_A56);
E[9] = E[9]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 7\n"),
#endif
__CruiseControl_A7));
E[9] = (E[11]&&!(E[13]))||E[9];
E[11] = E[9]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 4\n"),
#endif
__CruiseControl_A4);
E[14] = E[11]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 57\n"),
#endif
__CruiseControl_A57);
if (E[14]) {
__CruiseControl_A34;
#ifdef TRACE_ACTION
fprintf(stderr, "__CruiseControl_A34\n");
#endif
}
E[11] = E[11]&&!(E[14]);
E[15] = E[11]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 58\n"),
#endif
__CruiseControl_A58);
if (E[15]) {
__CruiseControl_A35;
#ifdef TRACE_ACTION
fprintf(stderr, "__CruiseControl_A35\n");
#endif
}
E[11] = E[11]&&!(E[15]);
if (E[11]) {
__CruiseControl_A36;
#ifdef TRACE_ACTION
fprintf(stderr, "__CruiseControl_A36\n");
#endif
}
E[9] = E[9]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 4\n"),
#endif
__CruiseControl_A4));
E[9] = E[14]||E[15]||E[11]||E[9];
E[16] = E[9]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 6\n"),
#endif
__CruiseControl_A6);
if (E[16]) {
__CruiseControl_A37;
#ifdef TRACE_ACTION
fprintf(stderr, "__CruiseControl_A37\n");
#endif
}
E[17] = E[16]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 59\n"),
#endif
__CruiseControl_A59);
E[9] = E[9]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 6\n"),
#endif
__CruiseControl_A6));
E[9] = (E[16]&&!(E[17]))||E[9];
E[18] = E[9]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 5\n"),
#endif
__CruiseControl_A5);
if (E[18]) {
__CruiseControl_A39;
#ifdef TRACE_ACTION
fprintf(stderr, "__CruiseControl_A39\n");
#endif
}
E[19] = E[18]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 60\n"),
#endif
__CruiseControl_A60);
E[9] = E[9]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 5\n"),
#endif
__CruiseControl_A5));
E[9] = (E[18]&&!(E[19]))||E[9];
E[20] = E[9]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 9\n"),
#endif
__CruiseControl_A9);
if (E[20]) {
__CruiseControl_A41;
#ifdef TRACE_ACTION
fprintf(stderr, "__CruiseControl_A41\n");
#endif
}
if (E[20]) {
__CruiseControl_A11;
#ifdef TRACE_ACTION
fprintf(stderr, "__CruiseControl_A11\n");
#endif
}
if (__CruiseControl_R[0]) {
__CruiseControl_A70;
#ifdef TRACE_ACTION
fprintf(stderr, "__CruiseControl_A70\n");
#endif
}
E[3] = E[3]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__CruiseControl_A2);
if (E[3]) {
__CruiseControl_A28;
#ifdef TRACE_ACTION
fprintf(stderr, "__CruiseControl_A28\n");
#endif
}
if (E[3]) {
__CruiseControl_A29;
#ifdef TRACE_ACTION
fprintf(stderr, "__CruiseControl_A29\n");
#endif
}
if (E[12]) {
__CruiseControl_A30;
#ifdef TRACE_ACTION
fprintf(stderr, "__CruiseControl_A30\n");
#endif
}
if (E[12]) {
__CruiseControl_A31;
#ifdef TRACE_ACTION
fprintf(stderr, "__CruiseControl_A31\n");
#endif
}
if (E[13]) {
__CruiseControl_A32;
#ifdef TRACE_ACTION
fprintf(stderr, "__CruiseControl_A32\n");
#endif
}
if (E[13]) {
__CruiseControl_A33;
#ifdef TRACE_ACTION
fprintf(stderr, "__CruiseControl_A33\n");
#endif
}
E[9] = E[9]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 9\n"),
#endif
__CruiseControl_A9));
E[9] = E[20]||E[9];
if (E[9]) {
__CruiseControl_A42;
#ifdef TRACE_ACTION
fprintf(stderr, "__CruiseControl_A42\n");
#endif
}
if (E[9]) {
__CruiseControl_A43;
#ifdef TRACE_ACTION
fprintf(stderr, "__CruiseControl_A43\n");
#endif
}
if (E[3]||E[12]||E[13]||E[9]||E[4]) {
__CruiseControl_A12;
#ifdef TRACE_ACTION
fprintf(stderr, "__CruiseControl_A12\n");
#endif
}
if (E[6]) {
__CruiseControl_A25;
#ifdef TRACE_ACTION
fprintf(stderr, "__CruiseControl_A25\n");
#endif
}
if (E[6]) {
__CruiseControl_A26;
#ifdef TRACE_ACTION
fprintf(stderr, "__CruiseControl_A26\n");
#endif
}
if (E[6]) {
__CruiseControl_A27;
#ifdef TRACE_ACTION
fprintf(stderr, "__CruiseControl_A27\n");
#endif
}
if (E[17]) {
__CruiseControl_A38;
#ifdef TRACE_ACTION
fprintf(stderr, "__CruiseControl_A38\n");
#endif
}
if (E[19]) {
__CruiseControl_A40;
#ifdef TRACE_ACTION
fprintf(stderr, "__CruiseControl_A40\n");
#endif
}
E[7] = E[7]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__CruiseControl_A2);
if (E[7]) {
__CruiseControl_A44;
#ifdef TRACE_ACTION
fprintf(stderr, "__CruiseControl_A44\n");
#endif
}
E[5] = E[5]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 3\n"),
#endif
__CruiseControl_A3);
E[21] = E[5]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 62\n"),
#endif
__CruiseControl_A62);
if (E[21]) {
__CruiseControl_A45;
#ifdef TRACE_ACTION
fprintf(stderr, "__CruiseControl_A45\n");
#endif
}
E[5] = E[5]&&!(E[21]);
if (E[5]) {
__CruiseControl_A46;
#ifdef TRACE_ACTION
fprintf(stderr, "__CruiseControl_A46\n");
#endif
}
if (E[5]) {
__CruiseControl_A47;
#ifdef TRACE_ACTION
fprintf(stderr, "__CruiseControl_A47\n");
#endif
}
E[22] = E[21]||E[5];
E[8] = E[8]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__CruiseControl_A2);
if (E[8]) {
__CruiseControl_A48;
#ifdef TRACE_ACTION
fprintf(stderr, "__CruiseControl_A48\n");
#endif
}
if (E[10]) {
__CruiseControl_A49;
#ifdef TRACE_ACTION
fprintf(stderr, "__CruiseControl_A49\n");
#endif
}
if (E[10]) {
__CruiseControl_A50;
#ifdef TRACE_ACTION
fprintf(stderr, "__CruiseControl_A50\n");
#endif
}
E[23] = E[6]||E[3]||E[12]||E[13]||E[17]||E[19]||E[9]||E[7]||E[22]||E[8]||E[10];
E[24] = !(_true);
if (__CruiseControl_R[0]) {
__CruiseControl_A22;
#ifdef TRACE_ACTION
fprintf(stderr, "__CruiseControl_A22\n");
#endif
}
if (__CruiseControl_R[0]) {
__CruiseControl_A71;
#ifdef TRACE_ACTION
fprintf(stderr, "__CruiseControl_A71\n");
#endif
}
if (__CruiseControl_R[0]) {
__CruiseControl_A72;
#ifdef TRACE_ACTION
fprintf(stderr, "__CruiseControl_A72\n");
#endif
}
if (__CruiseControl_R[0]) {
__CruiseControl_A73;
#ifdef TRACE_ACTION
fprintf(stderr, "__CruiseControl_A73\n");
#endif
}
__CruiseControl_R[1] = __CruiseControl_R[0]||E[6]||E[3]||E[12]||E[13]||E[17]||E[19]||E[9]||E[7]||E[22]||E[8]||E[10]||E[4];
E[22] = __CruiseControl_R[1];
__CruiseControl_R[0] = !(_true);
__CruiseControl__reset_input();
return E[22];
}

/* AUTOMATON RESET */

int CruiseControl_reset () {
__CruiseControl_R[0] = _true;
__CruiseControl_R[1] = _false;
__CruiseControl__reset_input();
return 0;
}
