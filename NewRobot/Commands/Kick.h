#ifndef KICK_H
#define KICK_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Javario
 */
class Kick: public CommandBase {
public:
	Kick();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
