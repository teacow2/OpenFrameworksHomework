#pragma once

#include "ofMain.h"

class Square
{
public:
	Square();

	void setup(int _count, int _row, int _col, ofPoint _margin);

	void rotate();

	void draw();

	vector<bool>sideOpen; 

	int neighbors[4];

	bool sideOn[4];

	void rotateArray(int _rotate, Square _square);

	int rotation; 

	ofImage shape; 

	ofPoint corner; 

};

