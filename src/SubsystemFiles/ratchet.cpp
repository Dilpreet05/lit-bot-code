#include "main.h"

pros::Motor ratchetMotor(11,MOTOR_GEARSET_18,false);
pros::ADIDigitalIn LimitSwitch('H');



void updateRatchet(){
    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_UP) == 1 && master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN) != 1){

        ratchetMotor = 50;

    }else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_UP) != 1 && master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN) == 1){

        ratchetMotor = -127;

    }
}

void setRatchetBrake(){
    ratchetMotor.set_brake_mode(MOTOR_BRAKE_HOLD);
}