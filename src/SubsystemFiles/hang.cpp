#include "main.h"

pros::Motor hangMotor(12,MOTOR_GEARSET_18,false);
pros::Motor ratchetMotor(11,MOTOR_GEARSET_18,false);
pros::ADIDigitalIn LimitSwitch('H');

void setHangBrake(){
        hangMotor.set_brake_mode(MOTOR_BRAKE_HOLD);
        ratchetMotor.set_brake_mode(MOTOR_BRAKE_HOLD);
}

void updateHang(){
 

        if((master.get_digital(pros::E_CONTROLLER_DIGITAL_R1) == 1) && (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1) != 1)){
                hangMotor = 85;
        }else if((master.get_digital(pros::E_CONTROLLER_DIGITAL_L1) == 1) && (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1) != 1) && !(LimitSwitch.get_value() == 1)){
                hangMotor = -85;
        }else{
                hangMotor.brake();
        }
        pros::delay(20);        
}

void updateRatchet(){
 
}