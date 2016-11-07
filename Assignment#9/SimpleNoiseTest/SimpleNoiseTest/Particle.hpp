#pragma once
#include "../ofMain.h"

class Particle
{
public:

	void setup(ofVec2f _vel);
	void update();
	void draw();

	void followMouse(ofVec2f _pos, float _rad, float _scale); 

	float agePct; 

	ofVec2f pos; 
	ofVec2f vel; 
	ofVec2f acc; 
	int age, lifespan; 

	float radius; 

};

