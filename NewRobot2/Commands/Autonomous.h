#ifndef AUTONOMOUS_H
#define AUTONOMOUS_H

#include "../CommandBase.h"

#define S_INIT				0

//All autonomous possibilities are AUTO_* and only one can be defined at a time
#define AUTO_SHOOT          3 // AS

#define S_AS_READY          1
#define S_AS_SHOOT          2
#define S_AS_MOVE           3
#define S_AS_STALL          4


#define AUTO_SHOOT_HOTSPOT		1 //ASH

#define S_ASH_CHECK_HS		1
#define S_ASH_READY			2
#define S_ASH_SHOOT			3
#define S_ASH_MOVE			4


#define AUTO_GETBALL_HOTSPOT	2 //AGH

#define S_AGH_PICK_UP       1
#define S_AGH_LOAD          2
#define S_AGH_FIRE          3

/**
 *
 *
 * @author Drew
 */
class Autonomous: public CommandBase {
private:
	Timer *ticktock;
	int program;
	int state;
public:
	Autonomous();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
