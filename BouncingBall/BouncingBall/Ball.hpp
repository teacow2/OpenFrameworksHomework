#pragma once
#include "ofMain.h"

class Ball
{
public:
	Ball();
	
	void setup(); 

	void update();

	void draw(); 

	ofPoint vel; 
	
	ofPoint pos;

	float boundX;

	float boundY; 

	ofColor color; 
	
	float radius; 

		



};

