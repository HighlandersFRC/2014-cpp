#ifndef AUTONOMOUS_H
#define AUTONOMOUS_H

#include "../CommandBase.h"

#define S_PICK_UP       1
#define S_LOAD          2
#define S_FIRE          3
#define S_INIT          0

/**
 *
 *
 * @author Drew
 */
class Autonomous: public CommandBase {
private:
	Timer *ticktock;
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
