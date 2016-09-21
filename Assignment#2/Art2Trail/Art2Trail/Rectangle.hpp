#pragma once

#include "ofMain.h"


class rectangle {

public:

	rectangle();
	void draw();

	void xenoToPoint(float catchX, float catchY);

	ofPoint pos;

	ofPoint vel; 

	float catchUpSpeed;

	int rectR;

	int rectG;

	int rectB;


};

