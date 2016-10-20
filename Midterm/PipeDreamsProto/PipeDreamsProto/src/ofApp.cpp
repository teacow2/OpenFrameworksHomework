#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	col = 8;
	row = 4;
	squareSize = 75; 

	startSquare = 8; 
	startSide = 3; 

	margin = ofPoint(200,100); 

	numSquare = col* row; 
	// set up array 
	for (int i = 0; i < numSquare; i++) {
		Square s;
		s.setup(i, row, col, margin);
		squares.push_back(s);
		bool temp = false; 
		squareOn.push_back(temp);

	}
	
	// ofHideCursor();

	ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update(){



	if (squares[startSquare].sideOpen[startSide]) squares[startSquare].sideOn[startSide] = true; 

	bool lightCount = true; 
	
	while (lightCount) {
		lightCount = false; 
		for (int i = 0; i < squares.size(); i++) {
			//resetSquare(squares[i]);
			for (int j = 0; j < 4; j++) {
				int k = j - 2; if (k < 0) k = 4 + k;
				if (squares[i].sideOpen[j] && squares[i].neighbors[j] != NULL) {
					if (squares[squares[i].neighbors[j]].sideOpen[k] && squares[squares[i].neighbors[j]].sideOn[k]) {
						squares[i].sideOn[j] = true;
						lightCount = true; 
					}
				}

			}

		}
	}
	

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255);
	for (int i = 0; i < squares.size(); i++) {

		squares[i].draw(); 
	}


}

void ofApp::resetSquare(Square _current) {
	
		for (int j = 0; j < 4; j++) {
			_current.sideOn[j] = false; 
		}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	for (int i = 0, i < squares.size(); i++) {
		if (mouseX > squares[i].corner.x && mouseX < (squares[i].corner.x + squareSize) && mouseY > squares[i].corner.y && mouseY < (squares[i].corner.y + squareSize)) {
			squares[i].rotate();

		}

	}
} 

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
