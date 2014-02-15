#include "Autonomous.h"

Autonomous::Autonomous() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(chassis);
	Requires(intake);
	Requires(vision);
	
	chassis->encoderReset();
	ticktock = new Timer();
	program = AUTO_SHOOT_HOTSPOT;
	state = S_INIT;
}

// Called just before this Command runs the first time
void Autonomous::Initialize() {
	//chassis->encoderReset();

	chassis->encoderReset();
	program = AUTO_SHOOT_HOTSPOT;
	state = S_INIT;
}

// Called repeatedly when this Command is scheduled to run
void Autonomous::Execute() {
	
	cout<<"Left Encoder: "<<chassis->encoderLeftGet()<<"\t\tRight  Encoder: "<<chassis->encoderRightGet();
	string s;
	
	switch(program) {
		case AUTO_SHOOT_HOTSPOT:
			
			switch(state) {
				case S_INIT:
					state = S_ASH_CHECK_HS;
					break;
					
				case S_ASH_CHECK_HS:
					if(vision->get_V_Distance() == 1) {
						state = S_ASH_READY;
					}
					break;
					
			}
			
			break;
	
			
		case AUTO_GETBALL_HOTSPOT:		//Shoots hotspot, then gets ball and shoots it
			
			switch(state) {
					case S_INIT:
						ticktock->Reset();
						ticktock->Start();
						state = S_AGH_PICK_UP;
						s = "S_INIT\n";
						break;
				
				
					case S_AGH_PICK_UP:
						intake->MoveSolenoid(true);
						intake->Set(-1.0);
						s = "S_AGH_PICK_UP\n";
						
						if (ticktock->Get()>=2.0) {
							state = S_AGH_LOAD;
							ticktock->Reset();
							ticktock->Start();
						}
						else {
							state = S_AGH_PICK_UP;
						}
						break;
					
					case S_AGH_LOAD:
						chassis->tankDrive(0.25, 0.25);
						
						
						s = "S_AGH_LOAD\n";
						if (ticktock->Get()>=1.75) {
							state = S_AGH_FIRE;
							ticktock->Reset();
							ticktock->Start();
						}
						else {
							state = S_AGH_LOAD;
						}
						break;
					
					case S_AGH_FIRE:
						s = "S_AGH_FIRE\n";
						intake->MoveSolenoid(false);
						intake->Set(0.0);
						chassis->tankDrive(0.0, 0.0);
						state = S_AGH_FIRE;
						break;
						
					default:
						state = S_INIT;
						break;
				}
			
			break;
			
			//AUTO_GETBALL_HOTSPOT ends here
			
		
		default:
			program = AUTO_SHOOT_HOTSPOT;
	}
	
	cout<<s<<"\n";
}

// Make this return true when this Command no longer needs to run execute()
bool Autonomous::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Autonomous::End() {
	chassis->tankDrive(0.0, 0.0);
	program = AUTO_SHOOT_HOTSPOT;
	state = S_INIT;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Autonomous::Interrupted() {
	chassis->tankDrive(0.0, 0.0);
	program = AUTO_SHOOT_HOTSPOT;
	state = S_INIT;
}
