#pragma once


#include "ofMain.h"
#include "Ship.hpp"
#include "Mothership.hpp"

class Shot
{
public:
	Shot();
	
	ofPoint origin;

	ofPoint dest; 

	int duration; 

	int count; 

	void setup(ofPoint _origin, ofPoint _dest);

	void update();

	void draw();



};