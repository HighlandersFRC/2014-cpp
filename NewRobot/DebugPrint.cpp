#include "DebugPrint.h"
extern "C" {
///DebugPrint(int, string)
///
///@brief This function prints a message to the DriveStation console.
///
///@param i : int used to filter print messages
///@param s : string argument to print
///
///This function does not return a value.
///  
///
void DebugPrint(int i, string s) {
	bool DEBUG = true;
	int  filter = 0;
	
	// Prints a debug message if DEBUG is active.
	if (DEBUG) 
	{
		if (i == filter) //?
		{
			cout<<"DebugPrint: "<<s<<"\n";
		}
	}
}
}
