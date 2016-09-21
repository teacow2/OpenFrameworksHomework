#pragma once
#include "ofMain.h"

class Particle
{
public:
	void draw();
	void setup(int rad, int shape);
	void explosion();
	void restart(int shape);

	ofPoint pos;
	ofPoint vel;

	ofColor color;
	
	int radius; 

	int aNum;
	int bNum;

	int shiftNum; 

	int countExp;
	
	int angle; 

	



};


