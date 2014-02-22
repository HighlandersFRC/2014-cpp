#ifndef TELEOP_H
#define TELEOP_H

#include "../CommandBase.h"
#include "../OI.h"


/**
 * @author Zack Palmer
 * @date 01/25/14
 */
class Teleop: public CommandBase {
private:
	Timer *kicker_timer;
	bool platpres;
	double wantedheight;
	double pos;
	bool PID_enable;
	bool kick_press;
public:
	Teleop();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
