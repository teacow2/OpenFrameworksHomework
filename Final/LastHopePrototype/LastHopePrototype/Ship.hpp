#pragma once
#include "ofMain.h"
#include "Mothership.hpp"

class Ship
{
public:
	Ship();

	void setup(bool _player,  int _type, ofPoint _pos, int _ID);

	void update(ofPoint _mTarget);

	void draw();

	void addRepel(ofPoint _pos, int _radius, float _strength);
	
	void addAttract(ofPoint _pos, float _strength);

	void calcForce();

	void resetForce(); 

	void shootTarget();

	vector<int> target; 

	float motherRad; 

	float targetRad; 

	float attractProx; 

	bool atTarget; 

	ofPoint speedMax; 

	ofPoint force; 

	ofPoint vel; 
	
	ofPoint pos; 

	float speedMod; 

	int attFreq; 

	int attCount; 

	int health; 

	int damage; 

	bool playerShip; 

	int aNum;
	int bNum;

	int shiftNum;

	int swarmNum; 

	float rotateAngle; 

	float angle;

	float swarmAngle; 

	bool engagedM; 
	
	bool engagedT; 

	int randCount;

	int id; 
};

