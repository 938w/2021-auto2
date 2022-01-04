/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    1, 3, 2, 4, 9   
// FrontLift            motor         5               
// BackLift             motor         8               
// Inertial10           inertial      10              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
int hector = 0;
double lol = 0;
void autonomous(void) {
  
  
  ////Picks up blue goal out of ramp
  //Lowers front lift
  FrontLift.spinFor(reverse, 565, deg, 100, rpm);
  //hold front lift
  FrontLift.setStopping(brakeType::hold);
  //move forward to ramp
  Drivetrain.driveFor(forward, 20, inches, 150, rpm);
  //Lifts up goal
  FrontLift.spinFor(forward,290,deg);

  //turn to right position
  
  Drivetrain.turnFor(left, 87, deg, 200, rpm);

  //Push goal to other side

  //Pushes goal to other side
  Drivetrain.driveFor(forward,100, inches, 150, rpm);
  wait (1, sec);

  //gets red goal to storage

  //Back up from neutral goal a little
  Drivetrain.driveFor(reverse, 10, inches, 100, rpm);
  //Lowers blue goal down
  FrontLift.spinFor(reverse, 295, deg, 100,  rpm);
  //Drive back more
  Drivetrain.driveFor(reverse, 20, inches, 100, rpm);
  //Lowers back lift
  BackLift.spinFor(reverse,655,deg, 100, rpm);
  wait(0.3,sec);
  //Turn right to swipe rings out and to get in position
  Drivetrain.turnFor(right,128, degrees, 200, rpm);
  wait(0.5,sec);
  //Backs out fast to get red goal
  Drivetrain.driveFor(reverse,16, inches, 200, rpm);
  Drivetrain.driveFor(reverse, 1, inches, 170, rpm);
  Drivetrain.driveFor(reverse, 1, inches, 140, rpm);
  Drivetrain.driveFor(reverse, 1, inches, 100, rpm);
  Drivetrain.driveFor(reverse, 2, inches, 50, rpm);
  
  //Fully lifts back lift to store goal
  BackLift.spinFor(forward, 670, deg, 100, rpm);
  wait (0.5,sec);
  BackLift.setStopping(brakeType::hold);
  //Wiggle to get red goal in, incase its not
  Drivetrain.driveFor(forward,2, inches,200, rpm);
  Drivetrain.driveFor(reverse,2,inches,200,rpm);
  //Turns a little to face tall branch
  Drivetrain.turnFor(left,12.5,deg,100,rpm);
  //Move forward to tall branch
  Drivetrain.driveFor(60,inches,100,rpm);
  wait (1,sec);
  //Lifts high branch
  FrontLift.spinFor(forward,270, degrees,50,rpm);
  //Lowers back lift
  BackLift.spinFor(reverse,665,deg,100,rpm);
  //Turn so backlift faces the neutral goal
  Drivetrain.turnFor(145,degrees,100,rpm);
  //Drive backwards to intake goal
  Drivetrain.driveFor(reverse,32,inches,200,rpm);
  //BackLift lifts up goal
  BackLift.spinFor(forward,350,degrees,100,rpm);
  //Turn so back faces the platform wall
  Drivetrain.turnFor(right,90,deg,100,rpm);
  //Drives backwards to platform wall
  Drivetrain.driveFor(reverse,50, inches,100,rpm);
  //Turn to calibrate
  Drivetrain.turnFor(left,55,deg,100,rpm);
  //
  Drivetrain.driveFor(reverse,10, inches, 100, rpm);

  Drivetrain.turnFor(left,40, degrees,100, rpm);
  Drivetrain.driveFor(forward, 7, inches, 100, rpm);
  BackLift.setStopping(hold);
  DrivetrainInertial.resetRotation();
  FrontLift.spinFor(reverse,300,degrees,50,rpm);
  Drivetrain.driveFor(forward,25,inches);
  FrontLift.spinFor(forward,290, degrees, 25, rpm, false);
  Drivetrain.turnFor(right, 10, degrees, 50, rpm);
  //drive up ramp
  while (DrivetrainInertial.roll() > 24 || DrivetrainInertial.roll() < -24) {
    Brain.Screen.clearScreen();
    Brain.Screen.newLine();
    Brain.Screen.print(DrivetrainInertial.roll());
    Drivetrain.drive(forward);
  }
  Drivetrain.stop(hold);

  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
