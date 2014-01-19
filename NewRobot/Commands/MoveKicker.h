#ifndef MOVEKICKER_H
#define MOVEKICKER_H

#include "../CommandBase.h"


class MoveKicker: public CommandBase {
private:
	double speed;
	int    Mode;

public:
	MoveKicker(int);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
