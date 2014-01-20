#ifndef COMPRESSORCMD_H
#define COMPRESSORCMD_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Drew
 */
class CompressorCMD: public CommandBase {
public:
	CompressorCMD();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
