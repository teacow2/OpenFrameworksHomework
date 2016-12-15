#include "Mothership.hpp"


Mothership::Mothership()
{
	// establish ship health -- fixed number

	maxHealth = health = 200; 
	
	// establish ship height and weight

	width = ofGetWidth();

	height = 20.0; 

	// establish bar

	barWidth = 300; 
	barHeight = 50; 

}

void Mothership::setup(int _player) {

	switch (_player) {
	case 0: // player
		tempy1 = ofGetHeight();
		tempy2 = ofGetHeight() - height;
		tempR = 0; tempG = 255; tempB = 0;
		barY = ofGetHeight() - height - 30;
		break;
	case 1: // enemy 
		tempy1 = 0;
		tempy2 = height;
		tempR = 255; tempG = 0; tempB = 0;
		barY = height / 2;

	}

	center = ofPoint(width / 2, tempy2);

}

void Mothership::draw() {

	ofSetColor(tempR, tempG, tempB);


	ofNoFill();
	ofDrawEllipse(width/2, tempy2, width, height * 5);
	
	ofDrawRectangle((ofGetWidth() / 2) - (barWidth / 2), barY, barWidth, barHeight);
	
	ofFill();
	ofDrawRectangle((ofGetWidth() / 2) - (barWidth / 2), barY, ofMap(health, 0, maxHealth, 0, barWidth), barHeight);


	
}