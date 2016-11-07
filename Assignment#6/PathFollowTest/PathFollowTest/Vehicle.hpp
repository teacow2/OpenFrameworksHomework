#pragma once

#include "ofMain.h"

class Vehicle
{
public:
	Vehicle();

	void setup();
	void update(ofPoint _start, ofPoint _end);
	void display();
	void applyForce(ofPoint _force);
	void seek(ofPoint _target);
	ofPoint getNormal(ofPoint _target, ofPoint _start, ofPoint _end);

	ofPoint pos;
	ofPoint vel; 
	ofPoint acc; 
	ofPoint dir; 
	ofPoint target; 
	ofPoint normalPoint; 
	float cap; 

	float radius; 
	float speed; 

	int size; 

	int step; 


};

