#include "Vehicle.hpp"



Vehicle::Vehicle()
{
	radius = 20;
	size = 10; 
	step = 10; 
	speed = .3; 
	cap = .01; 
	
}

void Vehicle::setup() {
	pos = ofPoint(0, ofRandom(0 + size, ofGetHeight() - size));
	cout << pos << endl; 
	vel = ofPoint(ofRandom(1, 3), ofRandom(-3, 3));

}

void Vehicle::update(ofPoint _start, ofPoint _end) {
	ofPoint predict; 
	predict = vel; 
	predict.normalize();
	predict *= step; 

	ofPoint predictLoc = predict + pos; 
	target = predictLoc - _start;

	normalPoint = getNormal(target, _start, _end);
	dir = _end - _start; 
	dir.normalize();
	dir *= step; 
	ofPoint newTarget = normalPoint + dir; 
	

	float lineDist = ofDist(predictLoc.x, predictLoc.y, normalPoint.x, normalPoint.y);

	if (lineDist > radius) {
		seek(newTarget);
	}
	



}

void Vehicle::display() {
	
	ofSetColor(255);
	ofDrawCircle(pos, size);

}

void Vehicle::applyForce(ofPoint _force) {
	acc += _force; 
	vel += acc;
	pos += vel;

	cout << acc << "   " << pos << endl;
	acc *= 0;

}


void Vehicle::seek(ofPoint _target) {
	ofPoint desired = _target - pos;
	desired.normalize();
	desired *= speed; 
	ofPoint steer = vel - desired;
	if (steer.length() > cap) {
		steer.normalize();
		steer *= cap; 

	}

	applyForce(steer);
}

ofPoint Vehicle::getNormal(ofPoint _target, ofPoint _start, ofPoint _end) {
	ofPoint tempDir = _end - _start;
	tempDir.normalize();
	tempDir *= _target.dot(tempDir);

	ofPoint normal = _start + tempDir;
	return normal; 
}
