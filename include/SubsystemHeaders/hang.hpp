#include "main.h"

extern pros::Motor hangMotor;
extern pros::Motor ratchetMotor;
extern pros::ADIDigitalIn LimitSwitch;

void setHangBrake();
void updateHang();
void updateRatchet();