#include "Platform.h"
#include "../Robotmap.h"
/*TODO: The platform needs two limit switches (one at
 *  the top and one at the bottom) to stop the platform
 *  if it gets too close to the end. It will also have
 *  an encoder to measure the height of the platform, so
 *  it may have functionality compatible with the vision
 *  software in the future. For now, add buttons for the
 *  driver to run it up and down.
*/
Platform::Platform() : Subsystem("Platform") {
	
}
    
void Platform::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}


// Put methods for controlling this subsystem
// here. Call these from Commands.
