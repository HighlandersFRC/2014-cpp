#ifndef PLATFORMCONTROL_H
#define PLATFORMCONTROL_H

#include "../CommandBase.h"

/**
 *
 *
 * @author 4499 The Highlanders
 */
class PlatformControl: public CommandBase {
public:
	PlatformControl();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
	double BeltSpeed;
};

#endif
