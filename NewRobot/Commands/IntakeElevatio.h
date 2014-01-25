#ifndef INTAKEELEVATIO_H
#define INTAKEELEVATIO_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Drew
 */
class IntakeElevatio: public CommandBase {
private:
	bool solVal;
public:
	IntakeElevatio(bool);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
