#pragma once
#include "ofMain.h"

class Particle
{
public:
	void draw();
	void setup(int rad, int shape);
	void explosion();


	ofPoint pos;
	ofPoint vel;

	ofColor color;

	int radius;

	int aNum;
	int bNum;

	int shiftNum;



	int angle;





};
