#pragma once

#include "ofMain.h"

class ParticleMoon: public ofPoint 
{
public:
	ParticleMoon();

	void setup(int _number);

	void update(float _step, ofPoint _center, bool _sun);

	void draw();
	
	void reset();

	float damp; 

	float moonSize; 

	float moonOrbit;

	float moonSpeed; 

	int moonR; 

	int moonG;

	int moonB; 

	float angle; 

	bool target; 

	int targetNum; 

	int repelRad;

	int attractRad; 

	ofPoint vel; 

	ofPoint force; 

	vector<float>sizes = { 10, 15, 20, 5, 30 };

	vector<float>orbits = { 150, 200, 300, 100, 400 };
	 
	vector<float>speeds = { 5, 4, 3, 2, 1};

private: 
	void gravityAtt(ofPoint _center, float _strength, float _radius);

	void nullRepel(ofPoint _center, float _strength, float _radius);

	float attractStr;

	float repelStr; 

};

