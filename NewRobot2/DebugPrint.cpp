#include "WPILib.h"
#include "Robotmap.h"		// for: SD_DBG_PRT_LAST
#include "DebugPrint.h"		// for: DebugPrint()

static int  filtered_verbosity = DBG_PRT_V1;


/// @brief This function prints a message to the standard out.
///
/// You will need to use NetConsole to see these print messages
///
/// @param v : enum used to filter print messages
/// @param s : string argument to print
///
///This function does not return a value.
///
void DebugPrint(dbg_prt_t msg_verbosity, std::string s)
{	
	static int once = 0;
	
	// Prints a debug message if verbosity of the print message
	// is less then or equal to the current threshold.
	if (msg_verbosity <= filtered_verbosity) 
	{
		// Roll the debug print messages
		
		if (!once)
		{
			once = true;
			SmartDashboard::PutString(SD_DBG_PRT_LAST_MINUS_3, "--------------------------------------------------------");
			SmartDashboard::PutString(SD_DBG_PRT_LAST_MINUS_2, "--------------------------------------------------------");
			SmartDashboard::PutString(SD_DBG_PRT_LAST_MINUS_1, "--------------------------------------------------------");
			SmartDashboard::PutString(SD_DBG_PRT_LAST, 		   "--------------------------------------------------------");
		}
		else
		{
			SmartDashboard::PutString(SD_DBG_PRT_LAST_MINUS_3, SmartDashboard::GetString(SD_DBG_PRT_LAST_MINUS_2));
			SmartDashboard::PutString(SD_DBG_PRT_LAST_MINUS_2, SmartDashboard::GetString(SD_DBG_PRT_LAST_MINUS_1));
		    SmartDashboard::PutString(SD_DBG_PRT_LAST_MINUS_1, SmartDashboard::GetString(SD_DBG_PRT_LAST));
		}
		
		// Print new message to smart dashboard
		SmartDashboard::PutString(SD_DBG_PRT_LAST, s);
		
		// Print new message stdout
		printf ("Team4499: %s\n", s.c_str());
	}
}


