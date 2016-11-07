#include "Particle.hpp"

void Particle::setup(ofVec2f rVel) {
	vel = rVel;
	age = 0;
	lifespan = ofRandom(50, 150);
	radius = 4.0; 

	pos = ofGetWindowSize() / 2.0;
};

void Particle::update() {

	// float noise = ofNoise(pos.x * 0.005, pos.y*0.005, ofGetElapsedTimef() * 0.1) * 15.0;

	//    float noise = 1;
	float agePct = 1.0 - ((float)age / (float)lifespan);

	// use sin and cos to give us some sweepy circular motion.  The closer we are to death, the more noise we add.
	// pos += ofVec2f(cos(noise), sin(noise)) * (1.0 - agePct);
	//vel += ofNoise(acc.x*.005, acc.y*.005, ofGetElapsedTimef()*.00015);
	vel += acc; 
	if (pos.x < radius || pos.x > ofGetWidth() - radius) vel.x *= -1;
	if (pos.y < radius || pos.y > ofGetHeight() - radius) vel.y *= -1;
	pos += vel;
	acc = ofVec2f(0.0, 0.0);
	// vel *= 0.97;

	age++;

}

void Particle::followMouse(ofVec2f _pos, float _rad, float _scale) {

	ofPoint diff = _pos - pos;
		if (diff.length() < _rad) {
			diff *= 1.0 - diff.length() / _rad;
		}
		acc += (diff*_scale);
}

void Particle::draw() {


	float agePct = 1.0 - ((float)age / (float)lifespan);

	ofCircle(pos, radius);

}
