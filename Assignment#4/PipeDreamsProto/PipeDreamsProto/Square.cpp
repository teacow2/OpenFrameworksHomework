#include "Square.hpp"



Square::Square()
{
	for (int i = 0; i < 4; i++) {
		sideOn[i] = 0; 
	}

	int numSides = ofRandom(0, 3);

	string shapeType; 

	bool tempSideOpen[4];

	switch(numSides) {
	case 0:
		shapeType = "Four-Way-Tile.jpg";
		tempSideOpen[0] = true; tempSideOpen[1] = true; tempSideOpen[2] = true; tempSideOpen[3] = true; 
		shape.load(shapeType);
		break; 
	case 1:
		shapeType = "Three-Way-Tile.jpg";
		tempSideOpen[0] = true; tempSideOpen[1] = false; tempSideOpen[2] = true; tempSideOpen[3] = true;
		shape.load(shapeType);
		break;
	case 2:
		shapeType = "L-Way-Tile.jpg";
		tempSideOpen[0] = false; tempSideOpen[1] = false; tempSideOpen[2] = true; tempSideOpen[3] = true;
		shape.load(shapeType);
		break;
	case 3:
		shapeType = "Two-Way-Tile.jpg";
		tempSideOpen[0] = true; tempSideOpen[1] = false; tempSideOpen[2] = true; tempSideOpen[3] = false;
		shape.load(shapeType);
		break;
	}

	for (int i = 0; i < 4; i++) {
		sideOpen.push_back(tempSideOpen[i]);
	}

	rotation = ofRandom(0, 3);

	rotateArray(rotation);


}

void Square::setup(int _count, int _row, int _col) {
	if (_count % _row == 0) {
		neighbors[0] = NULL; 
	}
	else {
		neighbors[0] = _count - 1; 
	}

	if (_count + 1 % _row == 0) {

		neighbors[2] = NULL; 
	}
	else {

		neighbors[2] = _count + 1; 
	}

	if (_count < _row) {
		neighbors[1] = NULL; 
	}
	else {
		neighbors[1] = _count - _row; 
	}

	if (_count > _row*(_col - 1)) {
		neighbors[3] = NULL; 
	}
	else {
		neighbors[3] = _count + _row; 
	}

}

void Square::update() {
	rotation += 1; 
	if (rotation > 3) rotation = 0; 
	
	rotateArray(rotation);

}


void Square::draw() {
	// shape.draw() need to figure out how to figure out where it is


}


void Square::rotateArray(int _rotate) {
	for (int i = 0; i < _rotate; i++) {
		bool temp = sideOpen[0];
		sideOpen.push_back(temp); 
		sideOpen.erase[0];
	}

	shape.rotate90(_rotate);

}

