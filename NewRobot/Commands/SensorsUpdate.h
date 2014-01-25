#ifndef SENSORSUPDATE_H
#define SENSORSUPDATE_H

#include "../CommandBase.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class SensorsUpdate: public CommandBase {
public:
	SensorsUpdate();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
