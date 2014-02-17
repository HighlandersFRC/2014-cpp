#include "Autonomous.h"

Autonomous::Autonomous() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(chassis);
	Requires(intake);
	Requires(vision);
	
	chassis->encoderReset();
	ticktock = new Timer();
	ticktock->Reset();
	program = AUTO_SHOOT;
	state = S_INIT;
}

// Called just before this Command runs the first time
void Autonomous::Initialize() {
	//chassis->encoderReset();

	chassis->encoderReset();
	program = AUTO_SHOOT;
	state = S_INIT;
	ticktock->Reset();
}

// Called repeatedly when this Command is scheduled to run
void Autonomous::Execute() {
	double TOLERANCE = 0.01;
	double platform_level = 1.68;
	
	cout<<"Left Encoder: "<<chassis->encoderLeftGet()<<"\t\tRight  Encoder: "<<chassis->encoderRightGet();
	string s;
	
	switch(program) {
		case AUTO_SHOOT:
			
			switch(state) {
				case S_INIT:
					state = S_AS_READY;
					break;
						
				case S_AS_READY:
					
					intake->MoveSolenoid(true);
					
					if (platform->ReturnPIDInput() < platform_level) {
						platform->setSpeed(0.5);
					}
					else {
						platform->setSpeed(-0.5);
					}
					
					if ((platform_level + TOLERANCE >= platform->ReturnPIDInput()) && (platform_level-TOLERANCE <= platform->ReturnPIDInput())) {
						state = S_AS_SHOOT;
						platform->setSpeed(0.0);
					}
					else {
						state = S_AS_READY;
					}
					break;
							
				case S_AS_SHOOT:
					ticktock->Start();
					
					if(ticktock->Get()<=0.4) {
						kicker->setSpeed(0.75);
					} else if(ticktock->Get()>0.4) {
						state = S_AS_MOVE;
						kicker->setSpeed(0.0);
						ticktock->Reset();
						break;
					}
					
					state = S_AS_SHOOT;
					break;
					
				case S_AS_MOVE:
					ticktock->Start();
					
					if(ticktock->Get()<=1.0) {
						chassis->tankDrive(0.5, 0.5);
					} else if (ticktock->Get()>2.0) {
						state = S_AS_STALL;
						chassis->tankDrive(0.0, 0.0);
						ticktock->Reset();
						break;
					}
					
					state = S_AS_MOVE;
					break;
					
				case S_AS_STALL:
					state = S_AS_STALL;
					break;
				
				default:
					state = S_INIT;
					break;
			}
			
			program = AUTO_SHOOT;
			break;
			
		default:
			program = AUTO_SHOOT;
			break;
	
	
//		case AUTO_SHOOT_HOTSPOT:
//			
//			switch(state) {
//				case S_INIT:
//					state = S_ASH_CHECK_HS;
//					break;
//					
//				case S_ASH_CHECK_HS:
//					if(vision->get_V_Distance() == 1) {
//						state = S_ASH_READY;
//					}
//					break;
//				
//				case S_ASH_READY:
//					break;
//					
//				default:
//					state = S_INIT;
//					break;
//			}
//			
//			break;
//	
//			
//		case AUTO_GETBALL_HOTSPOT:		//Shoots hotspot, then gets ball and shoots it
//			
//			switch(state) {
//					case S_INIT:
//						ticktock->Reset();
//						ticktock->Start();
//						state = S_AGH_PICK_UP;
//						s = "S_INIT\n";
//						break;
//				
//				
//					case S_AGH_PICK_UP:
//						intake->MoveSolenoid(true);
//						intake->Set(-1.0);
//						s = "S_AGH_PICK_UP\n";
//						
//						if (ticktock->Get()>=2.0) {
//							state = S_AGH_LOAD;
//							ticktock->Reset();
//							ticktock->Start();
//						}
//						else {
//							state = S_AGH_PICK_UP;
//						}
//						break;
//					
//					case S_AGH_LOAD:
//						chassis->tankDrive(0.25, 0.25);
//						
//						
//						s = "S_AGH_LOAD\n";
//						if (ticktock->Get()>=1.75) {
//							state = S_AGH_FIRE;
//							ticktock->Reset();
//							ticktock->Start();
//						}
//						else {
//							state = S_AGH_LOAD;
//						}
//						break;
//					
//					case S_AGH_FIRE:
//						s = "S_AGH_FIRE\n";
//						intake->MoveSolenoid(false);
//						intake->Set(0.0);
//						chassis->tankDrive(0.0, 0.0);
//						state = S_AGH_FIRE;
//						break;
//						
//					default:
//						state = S_INIT;
//						break;
//				}
//			
//			break;
//			
//			//AUTO_GETBALL_HOTSPOT ends here
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
	program = AUTO_SHOOT;
	state = S_INIT;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Autonomous::Interrupted() {
	chassis->tankDrive(0.0, 0.0);
	program = AUTO_SHOOT;
	state = S_INIT;
}
