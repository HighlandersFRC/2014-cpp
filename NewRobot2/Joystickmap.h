#ifndef JOYSTICKMAP_H
#define JOYSTICKMAP_H


#define DRIVE_TYPE_TANK   0
#define DRIVE_TYPE_ARCADE 1

#define DRIVE_TYPE   DRIVE_TYPE_TANK


#define DRIVER_GAMEPAD         1
#define COPILOT_GAMPAD         2

#define DRIVER_LEFT_JOYSTICK   1
#define DRIVER_RIGHT_JOYSTICK  2
#define COPILOT				   3

#define CONTROL_BOARD          5


#define TRIGGER                1
#define BTN_1                  1
#define BTN_2                  2
#define BTN_3                  3
#define BTN_4                  4
#define BTN_5                  5
#define BTN_6                  6
#define BTN_7                  7
#define BTN_8                  8
#define BTN_9                  9
#define BTN_10                10
#define BTN_11                11
#define BTN_12                12
#define BTN_13                13
#define BTN_14                14
#define BTN_15                15
#define BTN_16                16

#define X_AXIS                 1
#define Y_AXIS                 2
#define Z_AXIS                 3
#define R_AXIS	               4


//               Control             Axis        Joystick                     Description
static const int DRIVE_L[2]       = {Y_AXIS,     DRIVER_LEFT_JOYSTICK};
static const int DRIVE_R[2]       = {Y_AXIS,     DRIVER_RIGHT_JOYSTICK};

static const int PLATFORM_C[2]    = {R_AXIS,     COPILOT};

static const int KICKER_MAN_C[2]  = {Y_AXIS,     COPILOT};	//NOT CHANGED

static const int KICKER_POWER[2]  = {Y_AXIS,   COPILOT};


//               Control             Button      Joystick                     Description
static const int SHIFT[2]         = {BTN_2,      DRIVER_RIGHT_JOYSTICK};

static const int KICKER_PREP[2]   = {BTN_5,		 COPILOT};	//NOT CHANGED
static const int KICK[2]          = {BTN_1,    COPILOT};

static const int INTAKE_IN[2]		= {BTN_5,       COPILOT};
static const int INTAKE_OUT[2]		= {BTN_6,       COPILOT};
static const int INTAKE_SOL_IN[2]	= {BTN_4,       COPILOT};
static const int INTAKE_SOL_OUT[2]	= {BTN_3,       COPILOT};
static const int INTAKE_SEQUENCE[2]	= {BTN_12,		COPILOT};
static const int CENTER_SEQUENCE[2] = {BTN_11,		COPILOT};	//NOT ASSIGNED
static const int CV_TOGGLE[2]		= {BTN_2,		COPILOT};	//NOT ASSIGNED


static const int PLATFORM_KICK_GOAL1[2]  = {BTN_10,		 COPILOT};
static const int PLATFORM_KICK_GOAL2[2]  = {BTN_9,		 COPILOT};
static const int PLATFORM_KICK_TRUS1[2]  = {BTN_8,		 COPILOT};
static const int PLATFORM_KICK_TRUS2[2]  = {BTN_7,		 COPILOT};	//NOT ASSIGNED


#endif
