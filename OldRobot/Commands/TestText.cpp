#include "TestText.h"
TestText::TestText() {
}
// Called just before this Command runs the first time
void TestText::Initialize() {
}
// Called repeatedly when this Command is scheduled to run
void TestText::Execute() {
	printf("testtext running.");
}
// Make this return true when this Command no longer needs to run execute()
bool TestText::IsFinished() {
	return true;
}
// Called once after isFinished returns true
void TestText::End() {
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TestText::Interrupted() {
}
