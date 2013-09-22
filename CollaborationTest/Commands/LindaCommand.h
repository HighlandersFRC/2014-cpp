#ifndef LINDACOMMAND_H
#define LINDACOMMAND_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

/**
 *
 *
 * @author Linda
 */
class LindaCommand: public Command {
public:
	DrewCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
