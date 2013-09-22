#ifndef DREWCOMMAND_H
#define DREWCOMMAND_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

/**
 *
 *
 * @author Drew
 */
class DrewCommand: public Command {
public:
	DrewCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual void Monkeys();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
