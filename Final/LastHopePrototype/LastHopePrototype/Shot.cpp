#include "Shot.hpp"



Shot::Shot(){
	
	duration = 25;
	count = 0; 
}


void Shot::setup(Ship _tar, Ship _shoot) {
	target = _tar; 
	shooter = _shoot; 
	mShot = false; 

} 

void Shot::setupM(Ship _tar, ofPoint _dest) {
	target = _tar;
	dest = _dest;
	mShot = true;
}


void Shot::update() {
	count++; 
	
}

void Shot::draw() {

	ofSetColor(255);
	if (mShot) ofDrawLine(target.pos, dest); else ofDrawLine(target.pos, shooter.pos);
}