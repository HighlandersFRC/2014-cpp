#ifndef JOYSTICKMAP_H
#define JOYSTICKMAP_H


#define DRIVE_TYPE_TANK   0
#define DRIVE_TYPE_ARCADE 1

#define DRIVE_TYPE   DRIVE_TYPE_TANK


#define DRIVER_GAMEPAD         1
#define COPILOT_GAMPAD         2

#define DRIVER_LEFT_JOYSTICK   1
#define DRIVER_RIGHT_JOYSTICK  2
#define COPILOT_LEFT_JOYSTICK  3
#define COPILOT_RIGHT_JOYSTICK 4

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
#define THROTTLE               4


//               Control             Axis        Joystick                     Description
static const int DRIVE_L[2]       = {Y_AXIS,     DRIVER_LEFT_JOYSTICK};
static const int DRIVE_R[2]       = {Y_AXIS,     DRIVER_RIGHT_JOYSTICK};

static const int PLATFORM_C[2]    = {Y_AXIS,     COPILOT_LEFT_JOYSTICK};

static const int KICKER_MAN_C[2]  = {Y_AXIS,     COPILOT_RIGHT_JOYSTICK};

static const int KICKER_POWER[2]  = {THROTTLE,   COPILOT_RIGHT_JOYSTICK};


//               Control             Button      Joystick                     Description
static const int SHIFT[2]         = {BTN_2,      DRIVER_RIGHT_JOYSTICK};

static const int KICKER_PREP[2]   = {BTN_5,		 COPILOT_RIGHT_JOYSTICK};
static const int KICK[2]          = {TRIGGER,    COPILOT_RIGHT_JOYSTICK};
static const int MANUAL_KICK[2]   = {BTN_2,      COPILOT_RIGHT_JOYSTICK};

static const int INTAKE_IN[2]		= {BTN_2,       COPILOT_LEFT_JOYSTICK};
static const int INTAKE_OUT[2]		= {BTN_3,       COPILOT_LEFT_JOYSTICK};
static const int INTAKE_SOL_IN[2]	= {BTN_4,       COPILOT_LEFT_JOYSTICK};
static const int INTAKE_SOL_OUT[2]	= {BTN_5,       COPILOT_LEFT_JOYSTICK};
static const int INTAKE_SEQUENCE[2]	= {BTN_1,		COPILOT_LEFT_JOYSTICK};

static const int PLATFORM_KICK_POS1[2]  = {BTN_3,		 COPILOT_RIGHT_JOYSTICK};
static const int PLATFORM_KICK_POS2[2]  = {BTN_4,		 COPILOT_RIGHT_JOYSTICK};
static const int PLATFORM_KICK_POS3[2]  = {BTN_6,		 COPILOT_RIGHT_JOYSTICK};


#endif
