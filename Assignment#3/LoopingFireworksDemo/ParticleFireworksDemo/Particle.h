#pragma once
#include "ofMain.h"

class Particle
{
public:	
	void draw();
	void setup();
	void explosion();
	void restart();

	ofPoint pos; 
	ofPoint vel; 
	
	ofColor color; 

	float radius; 
	int countExp;

};

