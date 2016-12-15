#pragma once

#include "ofMain.h"
#include "Ship.hpp"

class Mothership
{
public:
	Mothership();

	void setup(int _player);

	void draw();

	float health; 

	float maxHealth; 

	float height; float width; 

	int barWidth; 

	int barHeight; 

	float tempy1;

	float tempy2;

	float barY;

	int tempR, tempB, tempG;

	ofPoint center; 

};

