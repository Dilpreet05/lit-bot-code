#include "main.h"

pros::Motor hangMotor(11,MOTOR_GEARSET_18,false);


void setHangBrake(){
        hangMotor.set_brake_mode(MOTOR_BRAKE_HOLD);
}

void updateHang(){
 

        if((master.get_digital(pros::E_CONTROLLER_DIGITAL_R1) == 1) && (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1) != 1)){
                ratchetMotor = -127;
                pros::delay(50);
                hangMotor = 85;
                pros::delay(50);
                ratchetMotor = 0;
        }else if((master.get_digital(pros::E_CONTROLLER_DIGITAL_L1) == 1) && (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1) != 1) && !(LimitSwitch.get_value() == 1)){
                ratchetMotor = 127;
                pros::delay(50);
                hangMotor = -85;
                pros::delay(50);
                ratchetMotor = 0;
        }else{
                ratchetMotor = 0;
                hangMotor.brake();
        }
        pros::delay(20);        
}
