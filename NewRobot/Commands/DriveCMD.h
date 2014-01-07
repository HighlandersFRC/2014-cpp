#ifndef DRIVECMD_H
#define DRIVECMD_H_H

#include "../CommandBase.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class DriveCMD: public CommandBase {
public:
	DriveCMD();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
