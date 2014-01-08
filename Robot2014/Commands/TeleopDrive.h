#ifndef TELEOPDRIVE_H
#define TELEOPDRIVE_H

#include "../CommandBase.h"


class TeleopDrive: public CommandBase {
public:
	TeleopDrive();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
