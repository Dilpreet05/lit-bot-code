#include "main.h"


/////
// For instalattion, upgrading, documentations and tutorials, check out website!
// https://ez-robotics.github.io/EZ-Template/
/////


const int DRIVE_SPEED = 101/2; // This is 110/127 (around 87% of max speed).  We don't suggest making this 127.
                             // If this is 127 and the robot tries to heading correct, it's only correcting by
                             // making one side slower.  When this is 87%, it's correcting by making one side
                             // faster and one side slower, giving better heading correction.
const int TURN_SPEED  = 90/2;
const int SWING_SPEED = 90/2;



///
// Constants
///

// It's best practice to tune constants when the robot is empty and with heavier game objects, or with lifts up vs down.
// If the objects are light or the cog doesn't change much, then there isn't a concern here.

void default_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}



void modified_exit_condition() {
  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);
}



// . . .
// Make your own autonomous functions here!
// . . .

// void example(){}

void skills(){
  chassis.set_drive_pid(10,DRIVE_SPEED,false);
}

void match(){

  pros::delay(3000);
  reset();
  chassis.set_drive_pid(-50,DRIVE_SPEED,true);
  pros::delay(100);
  grabberDown();
  pros::delay(150);
  grabberStop();
  chassis.wait_drive();

  grabberUp();
  pros::delay(200);
  grabberStop();

  reset();
  chassis.set_turn_pid(135,TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(10,DRIVE_SPEED,true);
  chassis.wait_drive();

  reset();
  chassis.set_swing_pid(ez::LEFT_SWING,90,SWING_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(6,DRIVE_SPEED);
  chassis.wait_drive();

  reset();
  pros::delay(500);
  grabberDown();
  pros::delay(500);
  
  chassis.set_drive_pid(-10,DRIVE_SPEED);
  chassis.wait_drive();
  grabberStop();

  reset();
  chassis.set_turn_pid(-90,TURN_SPEED);
  chassis.wait_drive();
  pros::delay(500);

  grabberUp();
  pros::delay(200);
  grabberStop();

  chassis.set_drive_pid(17,DRIVE_SPEED);
  chassis.wait_drive();

  reset();
  chassis.set_swing_pid(ez::RIGHT_SWING,-45,80);
  chassis.wait_drive();

  reset();
  chassis.set_turn_pid(-135,TURN_SPEED);
  chassis.wait_drive();


  chassis.set_drive_pid(22,DRIVE_SPEED,true);
  chassis.wait_drive();

  reset();
  chassis.set_turn_pid(45,TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(20,DRIVE_SPEED,true);
  chassis.wait_drive();


  // chassis.set_drive_pid(-5,DRIVE_SPEED,false);
  // chassis.wait_drive();

  // chassis.set_drive_pid(5,DRIVE_SPEED*2);
  // chassis.wait_drive();

  reset();





  


  // reset();
  // chassis.set_drive_pid(-43,DRIVE_SPEED,true);
  // pros::delay(100);
  // grabberDown();
  // pros::delay(150);
  // grabberStop();
  // chassis.wait_drive();

  // reset();
  // chassis.set_turn_pid(165,TURN_SPEED);
  // chassis.wait_drive();


  // reset();
  // chassis.set_drive_pid(23,DRIVE_SPEED,true);
  // chassis.wait_drive();

  // reset();
  // chassis.set_swing_pid(ez::LEFT_SWING,45,SWING_SPEED);
  // chassis.wait_drive();


  // chassis.set_drive_pid(2,DRIVE_SPEED);
  // chassis.wait_drive();

  // grabberDown();
  // pros::delay(200);
  // grabberStop();


  // reset();
  // chassis.set_drive_pid(-30,DRIVE_SPEED,true);
  // chassis.wait_drive();

  // chassis.set_swing_pid(ez::RIGHT_SWING,22.5,SWING_SPEED);
  // chassis.wait_drive();

  // chassis.set_drive_pid(-25,DRIVE_SPEED,true);
  // chassis.wait_drive();

  // reset();
  // chassis.set_swing_pid(ez::LEFT_SWING, -67.5, SWING_SPEED);
  // chassis.wait_drive();

  // chassis.set_drive_pid(32,DRIVE_SPEED*2,true);
  // grabberUp();
  // pros::delay(200);
  // grabberStop();
  // chassis.wait_drive();

  // reset();
  // chassis.set_drive_pid(-18,DRIVE_SPEED,true);
  // chassis.wait_drive();

  // reset();
  // chassis.set_swing_pid(ez::RIGHT_SWING, 112.5, SWING_SPEED);
  // chassis.wait_drive();

  // chassis.set_drive_pid(13,DRIVE_SPEED);
  // chassis.wait_drive();

  // grabberDown();
  // pros::delay(200);
  // grabberStop();

  // reset();
  // chassis.set_drive_pid(-10,DRIVE_SPEED);
  // chassis.wait_drive();

  // reset();
  // chassis.set_swing_pid(ez::LEFT_SWING,-112.5,SWING_SPEED);
  // chassis.wait_drive();

  // reset();
  // chassis.set_drive_pid(23,DRIVE_SPEED*2,true);
  // pros::delay(100);
  // grabberUp();
  // pros::delay(200);
  // grabberStop();
  // chassis.wait_drive();

  // reset();
  // chassis.set_drive_pid(-22,DRIVE_SPEED,true);
  // chassis.wait_drive();

  // reset();
  // chassis.set_swing_pid(ez::LEFT_SWING,90,SWING_SPEED);
  // chassis.wait_drive();

  // chassis.set_drive_pid(25,DRIVE_SPEED,true);
  // chassis.wait_drive();

  // reset();
  // chassis.set_swing_pid(ez::RIGHT_SWING,45,SWING_SPEED);
  // chassis.wait_drive();

  // chassis.set_drive_pid(20,DRIVE_SPEED);

  // grabberDown();
  // pros::delay(100);
  // grabberStop();



  

}





void reset(){
  chassis.reset_pid_targets(); // Resets PID targets to 0
  chassis.reset_gyro(); // Reset gyro position to 0
  chassis.reset_drive_sensor(); // Reset drive sensors to 0
}

void hangUp(){
  ratchetMotor = -127;
  pros::delay(50);
  hangMotor = 85;
}

void hangDown(){
  ratchetMotor = 127;
  hangMotor = -85;
}

void hangStop(){
  hangMotor.brake();
  ratchetMotor = 0;
}

void grabberUp(){
  grabberLeft = -127;
  grabberRight = -127;
}

void grabberDown(){
  grabberLeft = 127;
  grabberRight = 127;
}

void grabberStop(){
  grabberLeft = 0;
  grabberRight = 0;
  grabberLeft.brake();
  grabberRight.brake();
}



