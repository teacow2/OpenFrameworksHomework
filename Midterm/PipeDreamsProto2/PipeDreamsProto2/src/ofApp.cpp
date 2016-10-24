#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	col = 6;
	row = 6;


	startSquare = 0;
	startSide = 0;

	margin = ofPoint(200, 100);

	numSquare = col* row;

	ofBackground(0);
	// set up array 
	for (int i = 0; i < numSquare; i++) {
		// cout << "Setting up Square " << i << "  "; 
		Square s;
		s.setup(i, row, col, margin);
		squares.push_back(s);
		
		int tempRotate = squares[i].rotation; 
		while (tempRotate > 0) {
			squares[i].rotateArray();
			tempRotate--; 
		}



		
	}

	// ofHideCursor();

}

//--------------------------------------------------------------
void ofApp::update() {


	for (int i = 0; i < squares.size(); i++) {
		squares[i].sqOn = false;
		squares[i].checked = false;
	}

	tempList.clear();
	lightCount = 0;

//	if (squares[startSquare].sideOpen[startSide]) {
		squares[startSquare].sqOn = true; squares[startSquare].checked = true;
		tempList.push_back(startSquare);
		while (lightCount < tempList.size()) {
	//		cout << "Checking square " << tempList[lightCount] << endl;
			checkNeighbors(tempList[lightCount]);
			lightCount++;
	//		cout << (tempList.size() - lightCount) << " of " << tempList.size() << " squares left to check." << endl;

		}

//	}

	
	
}

//--------------------------------------------------------------
void ofApp::draw() {

		
	for (int i = 0; i < squares.size(); i++) {
	//	cout << "Drawing Square " << i << endl;
		squares[i].draw();
	/*	cout << "Sides for Square " << i << ": "; 
		for (int j = 0; j < 4; j++) {
			cout << squares[i].sideOpen[j] << " "; 
		}
		cout << endl; */ 
	}

}

void ofApp::checkNeighbors(int _current) {

	for (int i = 0; i < 4; i++) {
		if (squares[_current].sideOpen[i]) {
			int j = i - 2; if (j < 0) j = i + 2; 
			int neighCount = squares[_current].neighbors[i];
	//		cout << "On square " << _current << ", a " << squares[_current].shapeType << endl;
	//		cout << "Checking neighboring square:" << neighCount;
			if (neighCount == -1) {
	//			cout << " doesn't exist. It's not a valid side." << endl;
				continue; 
			}
	//		else cout << ", a " << squares[neighCount].shapeType << endl << "It's ";
			if (squares[neighCount].checked) {
	//			cout << "already checked." << endl;
				continue;
			}
			if (!squares[neighCount].sideOpen[j]) {
	//			cout << "not connected because " << i << " on square " << _current << " isn't open to " << j << " on square " << neighCount << endl;
				continue;
			}
	//		cout << "turned on and added to the list" << endl << endl;
			squares[neighCount].sqOn = true;
			squares[neighCount].checked = true;
			tempList.push_back(neighCount);
		}
	}
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

	// add a click block to prevent spamming
	
	for (int i = 0;  i < squares.size(); i++) {
		if (mouseX > squares[i].corner.x && mouseX < (squares[i].corner.x + squares[i].sqSize) && mouseY > squares[i].corner.y && mouseY < (squares[i].corner.y + squares[i].sqSize)) {
			cout << "Click Square " << i << endl; 
			squares[i].rotation++; 
			if (squares[i].rotation == 4) squares[i].rotation = 0; 
			squares[i].rotateArray();
		}

	}
	
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
