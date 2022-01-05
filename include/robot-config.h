using namespace vex;

extern brain Brain;

// VEXcode devices
extern smartdrive Drivetrain;
extern motor FrontLift;
extern motor BackLift;
extern inertial DrivetrainInertial;
extern motor rightMotorA;
extern motor rightMotorB;
extern motor leftMotorA;
extern motor leftMotorB;
/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );