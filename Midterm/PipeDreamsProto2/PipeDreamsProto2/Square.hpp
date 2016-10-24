#pragma once

#include "ofMain.h"


class Square
{
public:
	Square();

	void setup(int _count, int _row, int _col, ofPoint _margin);

	void draw();

	float sqSize; 

	ofPoint slotSize; 

	vector<bool>sideOpen;

	int neighbors[4];

	bool sqOn; 

	void rotateArray();

	string shapeType; 

	int rotation; 

	int tWeight; int lWeight; int twoWeight; 

	bool checked; 

	ofImage shape;

	ofVec2f corner;

	int sqCol; int sqRow; 


};


