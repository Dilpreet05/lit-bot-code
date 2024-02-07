#pragma once

#include "EZ-Template/drive/drive.hpp"

extern int skillsDelay;


void default_constants();

void drive_example();
void turn_example();


void skills();
void skillsNew();
void match();
void matchNew();
void skillsCycle();
void skillsCycleNew();
void pushOver();
void unPushOver();

void skillsPostFix();
void cyclePostFix();

void reset();
void resetHangMotor();
void hangUp(int units, int velocity);
void hangDown(int units, int velocity);
void hangStop();
void grabberUp();
void grabberDown();
void grabberStop();