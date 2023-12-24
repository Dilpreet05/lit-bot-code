#include "main.h"

pros::Motor grabber(2,pros::E_MOTOR_GEARSET_18,false);

void setGrabberBrakes(){
    grabber.set_brake_mode(MOTOR_BRAKE_HOLD);
}

void moveGrabber(){
    if((master.get_digital(pros::E_CONTROLLER_DIGITAL_L2) == 1) && (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2) != 1)){
        grabber = -80;
    }
    else if((master.get_digital(pros::E_CONTROLLER_DIGITAL_L2) != 1) && (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2) == 1)){
        grabber = 80;
    }
    else{
        grabber.brake();
    }
    pros::delay(20);
}