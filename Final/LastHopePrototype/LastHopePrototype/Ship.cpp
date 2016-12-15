#include "Ship.hpp"



Ship::Ship()
{
	atTarget = false;
	attractProx = 1000; 
	motherRad = 150; 
	targetRad = 75; 

	attCount = 0;


	speedMax = ofPoint(20,20); 



	// mothership hover numbers
	shiftNum = 400;
	aNum = 10;
	bNum = 20;
	engagedM = false;
	engagedT = false; 

	swarmAngle = 0; 

	randCount = ofRandom(0, 100);
}


void Ship::setup(bool _player,  int _type, ofPoint _pos, int _id) {
	id = _id; 
	playerShip = _player;
	switch (_type) {
	case 1:
		// mothership attacker
		target.push_back(0); // mothership
		speedMod = .02; 
		health = 50;
		damMin = 1; 
		damMax = 2; 
		attFreq = 500; 
		break; 
	case 2: 
		// ship targeter 
		target.push_back(1); // ship
		target.push_back(0); // mothership 
		speedMod = .03; 
		health = 30;
		damMin = 1; //7
		damMax = 2; //10
		attFreq = 250; 
		break; 
	}

	pos = _pos; 




}

void Ship::update(ofPoint _mTarget) {

	resetForce();



}

void Ship::draw() {

	if (playerShip) {
		ofSetColor(0, 255, 0);
	}
	else ofSetColor(255, 0, 0); 


	cout << "Current Angle is " << rotateAngle << endl; 



	ofPushMatrix();
		ofTranslate(pos);
		ofRotate(rotateAngle);
		ofDrawTriangle(ofPoint(0,0), ofPoint(-10,30), ofPoint(10, 30)); 
	ofPopMatrix();
	
	// ofDrawTriangle(pos, ofPoint(pos.x - 15, pos.y + 20), ofPoint(pos.x + 15, pos.y + 20));
		
}

void Ship::calcForce() {

	
	
	vel += force;
//	if (pos.y < motherRad || pos.y > ofGetHeight() - motherRad) vel.y *= -1; 
	if (pos.x < 0 || pos.x > ofGetWidth()) vel.x *= -1;
//	cout << "with vel of " << vel << endl; 

	pos += vel;

	rotateAngle = atan2f(vel.y, vel.x) * 180;
}



void Ship::shootTarget() {


}

void Ship::resetForce() {

	force = ofPoint(0,0); 
}

void Ship::addRepel(ofPoint _pos, int _radius, float _strength) {

//	cout << "Repelled!" << endl; 

	ofPoint origin;

	

	origin.set(_pos.x, _pos.y);



	ofPoint diff = _pos - origin;





	if (diff.length() < _radius) {



		diff *= ofMap(diff.length(), 0, _radius, 1, 0);

		diff.normalize();

		diff *= -1; 

		force += diff * _strength;

	//	cout << "At difference of " << diff.length() << " with radius of " << _radius << endl << "Repelled with force " << force << " - ";


	}

}

void Ship::addAttract(ofPoint _pos, float _strength) {

	ofPoint origin;

	origin.set(pos.x, pos.y);

//	cout << "At position " << origin << " and heading to " << _pos << endl;

	ofPoint diff = _pos - origin;

	diff.normalize();
	force += diff  * _strength;

//	cout << "with force " << force << " "; 


}
