#ifndef EXAMPLE_COMMAND_H
#define EXAMPLE_COMMAND_H

#include "../CommandBase.h"
#include "../OI.h"
#include "../RobotMap.h"

/**
 * @author Zack Palmer
 * @date 01/25/14
 */
class Teleop: public CommandBase {
private:
	Timer *kicker_timer;
public:
	Teleop();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
