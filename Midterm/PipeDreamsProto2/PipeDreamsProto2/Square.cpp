#include "Square.hpp"



Square::Square()
{

	checked = false; 
	sqOn = false; 

	sqSize = 75; 
	
	tWeight = 1; 
	lWeight = 3;
	twoWeight = 3; 

	int sumWeight = tWeight + lWeight + twoWeight; 

	int numSides = ofRandom(0, sumWeight+1);
	
	bool tempSideOpen[4];

	if (numSides < tWeight) {
//		cout << "Found three-way tile. ";
		string shapeURL = "C:/Users/errat/Desktop/PipeDreamsArt/Three-Way-Tile.jpg";
		// string shapeURL = "../Three-Way-Tile.jpg"; 
		shapeType = "Three Way Tile";
		tempSideOpen[0] = true; tempSideOpen[1] = false; tempSideOpen[2] = true; tempSideOpen[3] = true;
		shape.load(shapeURL);
//		cout << "Loaded file." << endl;
	} else if ((sumWeight - twoWeight) > numSides && numSides > tWeight) {
//		cout << "Found L-way tile. ";
		string shapeURL = "C:/Users/errat/Desktop/PipeDreamsArt/L-Way-Tile.jpg";
		shapeType = "L Way Tile";
		tempSideOpen[0] = false; tempSideOpen[1] = false; tempSideOpen[2] = true; tempSideOpen[3] = true;
		shape.load(shapeURL);
//		cout << "Loaded file." << endl;
	} else {
//		cout << "Found two-way tile. ";
		string shapeURL = "C:/Users/errat/Desktop/PipeDreamsArt/Two-Way-Tile.jpg";
		shapeType = "Two Way Tile";
		tempSideOpen[0] = true; tempSideOpen[1] = false; tempSideOpen[2] = true; tempSideOpen[3] = false;
		shape.load(shapeURL);
//		cout << "Loaded File." << endl;
	}
	

	for (int i = 0; i < 4; i++) {
	sideOpen.push_back(tempSideOpen[i]);
	}

//	rotation = ofRandom(0, 4);
	rotation = 0; 
//	shape.resize(sqSize, sqSize);

	cout << "Shape Type: " << shapeType << " ";

	
}

void Square::setup(int _count, int _row, int _col, ofPoint _margin) {




	slotSize.x = (ofGetWidth() - (_margin.x*2)) / _col;
	slotSize.y = (ofGetHeight() - (_margin.y*2)) / _row; 
	// cout << "Starting with width unit " << tempWidthUnit << " and height unit " << tempHeightUnit;
	sqRow = floor(_count / _col);
	sqCol = _count - ((sqRow) * _col);
	
	cout << "Square " << _count << " at row " << sqRow << " and column of " << sqCol << endl; 

	corner = ofVec2f(_margin.x + (sqCol*slotSize.x), _margin.y + (sqRow*slotSize.y));

//	cout << "Square " << _count << "Position is Col " << tempCol << " and Row " << tempRow <<  "   ";

//	cout << "Square " << _count << " has neighbors of top "; 
	
	// top neighbor
	if (_count < _col) {
		neighbors[0] = -1;
	}
	else {
		neighbors[0] = _count - _col;
	}

	// cout << neighbors[0];

	// bottom neighbor
	if (_count != _col * (_row-1) && (sqCol == 0 || _count < _col * (_row-1))) {
		neighbors[2] = _count + _col;
	}
	else {

		neighbors[2] = -1;
	}

	// cout << ", bottom " << neighbors[2];


	// right neighbor
	if ((_count+1) % _col == 0) {
		neighbors[1] = -1;
	}
	else {
		neighbors[1] = _count + 1;
	}

	// cout << ", right " << neighbors[1];

	//left neighbor 
	 
	if (_count % _col == 0 || _count == 0) {
		neighbors[3] = -1;
	}
	else {
		neighbors[3] = _count - 1;
	}

	// cout << ", and left " << neighbors[3] << endl;

	}



void Square::draw() {

	ofSetRectMode(OF_RECTMODE_CORNER);

	ofFill();
	if (sqOn) {
		ofSetColor(255, 255, 0);

	}
	else {
		ofSetColor(0, 0, 200);
	}
	
	//cout << "Drawing at " << corner << endl;
	ofDrawRectangle(corner, sqSize, sqSize);


	shape.draw(corner.x, corner.y);

}


void Square::rotateArray() {

	shape.rotate90(1);
	cout << "Start Rotation Sides:";
	for (int i = 0; i < 4; i++) {
		cout << " " << sideOpen[i] << " ";
	}
	cout << endl;
	bool temp = sideOpen[3];
	sideOpen.pop_back(); // remove last object
	sideOpen.insert(sideOpen.begin(), temp);
	cout << "New Sides: ";
	 for (int i = 0; i < 4; i++) {
		cout << sideOpen[i] << "  ";
	}
	cout << endl; 
	

 

}

