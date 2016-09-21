#include "Ball.hpp"



Ball::Ball()
{
	boundX = 100.0; 
	boundY = 100.0; 


}


void Ball::setup() {
	
	pos = ofPoint(ofRandom(boundX+1, ofGetWidth()-boundX), ofRandom(boundY+1, ofGetHeight()-boundY));

	vel = ofPoint(ofRandom(-2, 2), ofRandom(-5, 5));
	
	color = ofColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255)); 

	radius = ofRandom(20, 100);


}
void Ball::update() {

	pos += vel; 

	if (pos.x<boundX || pos.x>(ofGetWidth() - boundX)) {
		vel.x *= -1;
		pos += vel; 
	}

	if (pos.y<boundY || pos.y>(ofGetHeight() - boundY)) {
		vel.y *= -1;
		pos += vel;
	}


}

void Ball::draw() {

	ofFill(); 
	ofSetColor(color);
	ofDrawCircle(pos, radius);

}
