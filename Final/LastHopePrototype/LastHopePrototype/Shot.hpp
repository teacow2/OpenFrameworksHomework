#pragma once


#include "ofMain.h"
#include "Ship.hpp"
#include "Mothership.hpp"

class Shot
{
public:
	Shot();

	ofPoint dest; 

	Ship target;

	Ship shooter; 

	int duration; 

	int count; 

	void setup(Ship _tar, Ship _shoot);

	void setupM(Ship _tar, ofPoint _dest);

	void update();

	void draw();

	bool mShot; 



};