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

	rotateArray(rotation, *this);


}

void Square::setup(int _count, int _row, int _col, ofPoint _margin) {
	
	
	if (_count % _col == 0) {
		neighbors[0] = NULL; 
	}
	else {
		neighbors[0] = _count - 1; 
	}

	if (_count + 1 % _col == 0) {

		neighbors[2] = NULL; 
	}
	else {

		neighbors[2] = _count + 1; 
	}

	if (_count < _col) {
		neighbors[1] = NULL; 
	}
	else {
		neighbors[1] = _count - _row; 
	}

	if (_count >+ _row*(_col - 1)) {
		neighbors[3] = NULL; 
	}
	else {
		neighbors[3] = _count + _row; 
	}

	float tempWidthUnit = (ofGetWidth() - _margin.x)/_col; 
	float tempHeightUnit = ofGetHeight() - _margin.y/_row;
	int tempRow = floor(_count / _col) + 1; 
	int tempCol; 
	if (_count < _col) {
		tempCol = _count; 
	}
	else {
		tempCol = _count - (tempRow * _col);
	}

	corner = ofPoint(_margin.x + (tempCol*tempWidthUnit), _margin.y + (tempRow*tempHeightUnit)); 

}

void Square::rotate() {
	rotation += 1; 
	if (rotation > 3) rotation = 0; 
	
	rotateArray(rotation, this);

}


void Square::draw() {

	ofRectMode(CORNER);
	int sideCount = 0; 
	while (sideCount < 4) {
		if (!this.sideOn[sideCount]) {
			sideCount++;
			continue;
		}
		ofSetColor(255, 255, 0);
		ofDrawRectangle(this.corner, 75, 75);

	}
	
	shape.draw(this.corner);
}


void Square::rotateArray(int _rotate, Square _square) {
	for (int i = 0; i < _rotate; i++) {
		bool temp = _square.sideOpen[0];
		_square.sideOpen.push_back(temp); 
		_square.sideOpen.erase(_square.sideOpen.begin());
	}

	_square.shape.rotate90(_rotate);

}

