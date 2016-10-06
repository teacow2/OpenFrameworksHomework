#include "ParticleMoon.hpp"



ParticleMoon::ParticleMoon()
{
	damp = .09; 
	
	force.set(0.0, 0.0); 

	repelStr = .005;

	attractStr = .0001; 

	repelRad = 200;

	attractRad = 1000; 

	angle = 0.0; 
}

void ParticleMoon :: setup(int _number) {
	x = ofRandom(sizes[_number] / 2, ofGetWidth() - (sizes[_number] / 2));
	y =	ofRandom(sizes[_number] / 2, ofGetHeight() - (sizes[_number] / 2)); 
	moonSize = sizes[_number];
	moonOrbit = orbits[_number];
	moonSpeed = speeds[_number];

	moonR = ofRandom(0, 255);
	moonG = ofRandom(0, 255);
	moonB = ofRandom(0, 255);

	vel = ofPoint((ofRandom(-1, 1)*moonSpeed), (ofRandom(-1, 1)*moonSpeed)); 

}

void ParticleMoon::update(float _step, ofPoint _center, bool _sun) {
	if (_sun) {
		ofPoint diff = *this - _center;
		if (diff.length() <= (moonOrbit+25)) {

			angle += _step;

			x = _center.x + moonOrbit * cos(angle);
			y = _center.y + moonOrbit * sin(angle);
		}
		else {

			gravityAtt(_center, attractStr, attractRad);
			vel += force; 
			*this += vel;

			if (x < moonSize || x > ofGetWidth() - moonSize) {
				vel.x *= -1;
			}

			if (y < moonSize || y > ofGetHeight() - moonSize) {
				vel.y *= -1;
			}
		}
	}
	else	{
		ofPoint diff = *this - _center;
		nullRepel(_center, repelStr, repelRad);
		vel += force; 
		*this += vel; 

		if (x < moonSize || x > ofGetWidth() - moonSize) {
			vel.x *= -1; 
		}

		if (y < moonSize || y > ofGetHeight() - moonSize) {
			vel.y *= -1;
		}

	}

}

void ParticleMoon::draw() {

	ofDrawCircle(*this, moonSize);


}

void ParticleMoon::gravityAtt(ofPoint _center, float _strength, float _radius) {

	ofPoint origin;

	origin.set(_center.x, _center.y);

	ofPoint diff = *this - origin;

	if (diff.length() < (_radius*10)) {
		diff *= ofMap(diff.length(), 0, (_radius*10), 1.0, 0.0);
		force -= diff * _strength;

	}
}

void ParticleMoon::nullRepel(ofPoint _center, float _strength, float _radius) {
	
	ofPoint origin;

	origin.set(_center.x, _center.y);

	ofPoint diff = *this - origin;



	if (diff.length() < _radius) {

		diff *= ofMap(diff.length(), 0, _radius, 1, 0);

		force += diff * _strength;
	}

}


void ParticleMoon::reset() {

	force.set(0,0); 
}