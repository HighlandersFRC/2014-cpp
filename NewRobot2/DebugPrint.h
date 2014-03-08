#ifndef DEBUGPRINT_H
#define DEBUGPRINT_H

#include "WPILib.h"

#define FULL_PRINT 1

// Debug message verbosity levels.
// -- Each debug message has a verbosity level
// -- A desired verbosity level is set once globally and it
//    determines whether a given debug message will be printed.
typedef enum
{
	DBG_PRT_V1 = 1,
	DBG_PRT_V2,
} dbg_prt_t;


void DebugPrint(dbg_prt_t msg_verbosity, std::string s);


#endif // #ifndef DEBUGPRINT_H
