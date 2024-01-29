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
// If the objects are ez or the cog doesn't change much, then there isn't a concern here.

void default_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 10, 0, 18, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.50, 0.235, 5.25, 15);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.5, 0.0, 4.5, 15);
  chassis.set_pid_constants(&chassis.turnPID, 3.5, 0.003, 27, 15);
  chassis.set_pid_constants(&chassis.swingPID, 4.5, 0, 33,0);
}




void modified_exit_condition() {
  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);
}


void drive_example(){
  // The first parameter is target inches
  // The second parameter is max speed the robot will drive at
  // The third parameter is a boolean (true or false) for enabling/disabling a slew at the start of drive motions
  // for slew, only enable it when the drive distance is greater then the slew distance + a few inches
  double valRight = 0.0;
  double valLeft = 0.0;
  pros::lcd::clear();

  valRight = chassis.get_gyro();


  pros::lcd::print(1,"value forward Right: %lf", valRight);


  chassis.set_swing_pid(ez::LEFT_SWING, 90, SWING_SPEED);
  chassis.wait_drive();


  valRight = chassis.get_gyro();
  // valLeft = chassis.left_sensor()/chassis.get_tick_per_inch();

  pros::lcd::print(3,"value forward Right: %lf", valRight);
  // pros::lcd::print(3,"value forward Left: %lf", valLeft);


  // printf("value forward Right: %lf", valRight);
  // printf("value forward Left: %lf", valLeft);


  pros::delay(1000);

  chassis.set_swing_pid(ez::LEFT_SWING,0,SWING_SPEED);
  chassis.wait_drive();

  valRight = chassis.get_gyro();
  // valLeft = chassis.left_sensor()/chassis.get_tick_per_inch();  

  pros::lcd::print(5,"value Back Right: %lf", valRight);
  // pros::lcd::print(7,"value Back Left: %lf", valLeft);

  // printf("value forward Right: %lf", valRight);
  // printf("value forward Left: %lf", valLeft);


  // chassis.set_drive_pid(-12, DRIVE_SPEED);
  // chassis.wait_drive();
}

void turn_example() {
  // The first parameter is target degrees
  // The second parameter is max speed the robot will drive at

  
  // chassis.set_turn_pid(180, TURN_SPEED);
  // chassis.wait_drive();

  // // pros::delay(1000);


  // // pros::delay(1000);

  // reset();
  // chassis.set_turn_pid(-180, TURN_SPEED);
  // chassis.wait_drive();

  chassis.set_swing_pid(ez::LEFT_SWING,90,SWING_SPEED);
  chassis.wait_drive();

  reset();
  chassis.set_swing_pid(ez::LEFT_SWING,-90,SWING_SPEED);
  chassis.wait_drive();
}



// . . .
// Make your own autonomous functions here!
// . . .

// void example(){}

int skillsDelay = 600;

void skills(){

  
  reset();
  chassis.set_drive_pid(10,127);
  chassis.wait_drive();

  reset();
  chassis.set_drive_pid(-6,DRIVE_SPEED,true);
  chassis.wait_drive();

  reset();
  chassis.set_turn_pid(-135,TURN_SPEED);
  chassis.wait_drive();

  // reset();
  // chassis.set_swing_pid(ez::LEFT_SWING,45,SWING_SPEED);
  // chassis.wait_drive();

  // chassis.set_drive_pid(11,DRIVE_SPEED,true);
  // chassis.wait_drive();

  chassis.set_drive_pid(15,DRIVE_SPEED);
  chassis.wait_drive();

  reset();
  chassis.set_turn_pid(-90,TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(6,DRIVE_SPEED);
  chassis.wait_drive();


  reset();
  pros::delay(250);
  grabberDown();
  pros::delay(200);
  grabberStop();
  chassis.wait_drive();
  // grabberStop();

  for(int k = 0; k < 5; k++){
    pros::delay(skillsDelay);
    skillsCycle();
    if(k==3){
      reset();
      chassis.set_swing_pid(ez::RIGHT_SWING,-4,DRIVE_SPEED);
      chassis.wait_drive();
    }
  }


  // pushOver();
  pros::delay(skillsDelay);

  reset();

  chassis.set_drive_pid(7,DRIVE_SPEED);
  chassis.wait_drive();
  
  reset();
  chassis.set_drive_pid(-5,DRIVE_SPEED);
  chassis.wait_drive();

  reset();
  chassis.set_turn_pid(90,TURN_SPEED);
  chassis.wait_drive();

  grabberUp();
  pros::delay(500);
  grabberStop();

  chassis.set_drive_pid(11,DRIVE_SPEED);
  chassis.wait_drive();

  reset();
  // chassis.set_turn_pid(45,TURN_SPEED);
  chassis.set_swing_pid(ez::LEFT_SWING,45,SWING_SPEED);
  chassis.wait_drive();
  
  chassis.set_drive_pid(39,DRIVE_SPEED,true);
  chassis.wait_drive();

  // unPushOver();


  chassis.set_drive_pid(-38,DRIVE_SPEED,true);
  chassis.wait_drive();

  reset();
  chassis.set_swing_pid(ez::LEFT_SWING,-42,SWING_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-9,DRIVE_SPEED,true);
  chassis.wait_drive();

  chassis.set_turn_pid(-135,TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(5,DRIVE_SPEED);
  chassis.wait_drive();

  
  grabberDown();
  pros::delay(250);
  grabberStop();
  
  

  for(int k = 0; k < 5; k++){
    pros::delay(skillsDelay);
    skillsCycle();
    // if(k==3){
    //   reset();
    //   chassis.set_swing_pid(ez::RIGHT_SWING,-4,DRIVE_SPEED);
    //   chassis.wait_drive();
    // }
  }

  // pushOver();


  pros::delay(skillsDelay);

  reset();

  chassis.set_drive_pid(7,DRIVE_SPEED);
  chassis.wait_drive();
  
  reset();
  chassis.set_swing_pid(ez::RIGHT_SWING,-4,DRIVE_SPEED);
  chassis.wait_drive();

  reset();
  chassis.set_drive_pid(-5,DRIVE_SPEED);
  chassis.wait_drive();

  reset();
  chassis.set_turn_pid(90,TURN_SPEED);
  chassis.wait_drive();

  grabberUp();
  pros::delay(500);
  grabberStop();

  chassis.set_drive_pid(9,DRIVE_SPEED);
  chassis.wait_drive();

  reset();
  // chassis.set_turn_pid(45,TURN_SPEED);
  chassis.set_swing_pid(ez::LEFT_SWING,43,SWING_SPEED);
  chassis.wait_drive();
  
  chassis.set_drive_pid(41,DRIVE_SPEED,true);
  chassis.wait_drive();


  // // unPushOver();

  reset();  

  chassis.set_drive_pid(-39,DRIVE_SPEED,true);
  chassis.wait_drive();

  reset();
  chassis.set_swing_pid(ez::LEFT_SWING,-42,SWING_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-12,DRIVE_SPEED,true);
  chassis.wait_drive();

  chassis.set_turn_pid(-135,TURN_SPEED);
  chassis.wait_drive();


  chassis.set_drive_pid(4,DRIVE_SPEED);
  chassis.wait_drive();

  grabberDown();
  pros::delay(250);
  grabberStop();


  for(int k = 0; k < 5; k++){
    pros::delay(skillsDelay);
    skillsCycle();
    // if(k%2!=0){
    //   chassis.set_drive_pid(6,DRIVE_SPEED);
    //   chassis.wait_drive();
    //   reset();
    // }
  }

  // pushOver();

  pros::delay(skillsDelay);

  reset();

  chassis.set_drive_pid(6,DRIVE_SPEED);
  chassis.wait_drive();
  
  reset();
  chassis.set_drive_pid(-3,DRIVE_SPEED);
  chassis.wait_drive();

  reset();
  chassis.set_turn_pid(90,TURN_SPEED);
  chassis.wait_drive();

  grabberUp();
  pros::delay(500);
  grabberStop();

  chassis.set_drive_pid(12,DRIVE_SPEED);
  chassis.wait_drive();

  reset();
  // chassis.set_turn_pid(45,TURN_SPEED);
  chassis.set_swing_pid(ez::LEFT_SWING,44,SWING_SPEED);
  chassis.wait_drive();
  
  chassis.set_drive_pid(41,DRIVE_SPEED,true);
  chassis.wait_drive();




  chassis.set_drive_pid(-30,DRIVE_SPEED);
  chassis.wait_drive();

}






void unPushOver(){
  reset();  

  chassis.set_drive_pid(-39,DRIVE_SPEED,true);
  chassis.wait_drive();

  reset();
  chassis.set_swing_pid(ez::LEFT_SWING,-45,SWING_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-11,DRIVE_SPEED,true);
  chassis.wait_drive();

  chassis.set_turn_pid(-135,TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(5,DRIVE_SPEED);
  chassis.wait_drive();

  grabberDown();
  pros::delay(250);
  grabberStop();

}

void pushOver(){


  pros::delay(skillsDelay);

  reset();

  chassis.set_drive_pid(6,DRIVE_SPEED);
  chassis.wait_drive();
  
  reset();
  chassis.set_drive_pid(-3,DRIVE_SPEED);
  chassis.wait_drive();

  reset();
  chassis.set_turn_pid(90,TURN_SPEED);
  chassis.wait_drive();

  grabberUp();
  pros::delay(500);
  grabberStop();

  chassis.set_drive_pid(12,DRIVE_SPEED);
  chassis.wait_drive();

  reset();
  // chassis.set_turn_pid(45,TURN_SPEED);
  chassis.set_swing_pid(ez::LEFT_SWING,44,SWING_SPEED);
  chassis.wait_drive();
  
  chassis.set_drive_pid(41,DRIVE_SPEED,true);
  chassis.wait_drive();
}


void skillsCycle(){



  reset();
  chassis.set_turn_pid(45,TURN_SPEED*1.5);
  chassis.wait_drive();

  pros::delay(100);

  reset();
  chassis.set_turn_pid(-45,TURN_SPEED);
  chassis.wait_drive();

}


// *****************

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

  reset();
  chassis.set_turn_pid(360,TURN_SPEED);
  chassis.wait_drive();

  reset();
  chassis.set_drive_pid(6,DRIVE_SPEED);
  chassis.wait_drive();

  reset();
  pros::delay(500);
  grabberDown();
  pros::delay(500);
  
  chassis.set_drive_pid(-55,DRIVE_SPEED);
  chassis.wait_drive();
  grabberStop();

  reset();
  chassis.set_swing_pid(ez::LEFT_SWING,-48,SWING_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-7,DRIVE_SPEED);
  chassis.wait_drive();

  pros::delay(skillsDelay);
  grabberUp();
  pros::delay(200);
  grabberStop();

  chassis.set_drive_pid(32,101,true);
  chassis.wait_drive();


  for(int k = 0; k < 2; k++){
    chassis.set_drive_pid(-10,DRIVE_SPEED);
    chassis.wait_drive();

    chassis.set_drive_pid(12,DRIVE_SPEED);
    chassis.wait_drive();
  }


  reset();
  chassis.set_drive_pid(-3,DRIVE_SPEED);
  chassis.wait_drive();

  reset();
  chassis.set_turn_pid(90,TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(53,DRIVE_SPEED,true);
  chassis.wait_drive();

  reset();
  chassis.set_turn_pid(90,TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(34,DRIVE_SPEED);
  chassis.wait_drive();


  

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

}



