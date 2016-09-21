#include "Particle.hpp"


void Particle::setup(int rad, int shape) {

	radius = 100;
 
	switch (shape) {
	case 0:
		shiftNum = 200;
		angle = 0;
		aNum = 20;
		bNum = 40;
		break;
	case 1:
		shiftNum = 200;
		angle = 45;
		aNum = 20;
		bNum = 40;
		break;
	case 2:
		shiftNum = 200;
		angle = 90;
		aNum = 20;
		bNum = 40;
		break;
	}

	pos.x = (ofGetWidth() / 2) + (shiftNum * sin((aNum * rad) + angle));
	pos.y = (ofGetHeight()/2) + (shiftNum * sin(bNum * rad));

	// vel.x = 0; vel.y = 0;

	vel.x = ofRandom(-2, 2); vel.y = ofRandom(-4, 0);

	color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));





}

void Particle::explosion() {



	pos -= vel;

	vel.x -= .1;

	 radius -= .0001;


}

void Particle::draw() {

	ofSetColor(color);

	ofEllipse(pos.x, pos.y, radius, radius);

}

