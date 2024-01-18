#pragma once

#include "EZ-Template/drive/drive.hpp"

extern Drive chassis;
extern Drive r;
extern int skillsDelay;


void default_constants();


void skills();
void match();
void skillsCycle();
void pushOver();
void unPushOver();

void reset();
void hangUp();
void hangDown();
void hangStop();
void grabberUp();
void grabberDown();
void grabberStop();