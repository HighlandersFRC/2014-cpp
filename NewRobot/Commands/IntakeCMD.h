#ifndef INTAKECMD_H
#define INTAKECMD_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Drew
 */
class IntakeCMD: public CommandBase {
private:
	double speed;
public:
	IntakeCMD(double);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
	double IntakeSpeed;
	double val;
};

#endif
