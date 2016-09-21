#include "Snowflake.hpp"



Snowflake::Snowflake()
{
	gravity = 0.5; 
}


void Snowflake::setup() {
	pos = ofPoint(ofRandom(-30, ofGetWidth()+30), 0);

	size = ofRandom(3, 6);

	noise = ofRandom(.1, 1.5);
	
}

void Snowflake::update() {

	drift = sin(ofGetElapsedTimef() + noise) * .15;
	
	vel = ofPoint(drift, gravity);

	pos += vel; 
}

void Snowflake::draw() {

	ofFill();
	ofSetColor(255);

	ofDrawCircle(pos, size);

}