#pragma once
#include "ofMain.h"

class Snowflake
{
public:
	Snowflake();

	void setup();

	void update();

	void draw();
	
	ofPoint vel; 

	ofPoint pos; 

	float drift; 

	float gravity; 

	int size; 

	float noise; 
};

