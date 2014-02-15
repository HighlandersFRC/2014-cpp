#ifndef AUTONOMOUS_H
#define AUTONOMOUS_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Drew
 */
class Autonomous: public CommandBase {
private:
	Timer ticktock1;
public:
	Autonomous();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
