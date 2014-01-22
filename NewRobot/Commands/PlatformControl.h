#ifndef PLATFORMCONTROL_H
#define PLATFORMCONTROL_H

#include "../CommandBase.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class PlatformControl: public CommandBase {
public:
	PlatformControl();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
