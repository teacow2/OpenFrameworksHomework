#include "Particle.h"



void Particle::setup() {

	pos.x = ofGetWidth() / 2; 

	pos.y = 50; 

	radius = 7.5; 

	vel.x = ofRandom(-2, 2);

	vel.y = ofRandom(-4, 0);

	color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));

	countExp = ofRandom(100, 200);

}

void Particle::explosion() {
	pos -= vel; 
	
}

void Particle::draw() {

	ofSetColor(color);

	ofEllipse(pos.x, pos.y, radius, radius);

}

void Particle::restart() {
	pos.x = ofGetWidth() / 2;

	pos.y = 50;

	vel.x = ofRandom(-1, 1);

	vel.y = ofRandom(-2, 0);

	color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));

	countExp = ofRandom(100, 200);
}