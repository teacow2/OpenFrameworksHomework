#pragma once

#include "ofMain.h"

class Square
{
public:
	Square();

	void setup(int _count, int _row, int _col);

	void update();

	void draw();

	vector<bool>sideOpen; 

	int neighbors[4];

	bool sideOn[4];

	void rotateArray(int _rotate);

	int rotation; 

	ofImage shape; 

};

