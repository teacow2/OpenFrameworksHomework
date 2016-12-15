#include "Shot.hpp"



Shot::Shot(){
	
	duration = 25;
	count = 0; 
}


void Shot::setup(ofPoint _origin, ofPoint _dest) {
	origin = _origin; 
	dest = _dest; 

} 

void Shot::update() {
	count++; 
	
}

void Shot::draw() {

	ofSetColor(255);
	ofDrawLine(origin, dest);
}