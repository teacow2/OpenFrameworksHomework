#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	col = 8;
	row = 4;

	startSquare = 8; 
	startSide = 3; 

	numSquare = col* row; 

	for (int i = 0; i < numSquare; i++) {
		Square *s = new Square;
		s -> setup(i, row, col);
		squares.push_back(s);

	}

	ofHideCursor();

	ofBackground(255);
}
-
//--------------------------------------------------------------
void ofApp::update(){

	resetGrid();  

	if (squares[startSquare]->sideOpen[startSide]) squares[startSquare]->sideOn[startSide] = true; 


	// need to go back over grid
	for(auto &sq: squares) {
		for (int j = 0; j < 4; j++) {
			int k = j - 2; if (k < 0) k = 4 + k; 
			if (sq->sideOpen[j] && sq->neighbors[j] != NULL) {
				if(squares[sq->neighbors[j]]->sideOpen[k] && squares[sq->neighbors[j]]->sideOn[k]) {
				sq->sideOn[j] = true;
				}
			}

		}

	}

	// indicate which squares are colored 

}

//--------------------------------------------------------------
void ofApp::draw(){
	// draw colored backgrounds

	//draw squares 
}

void ofApp::resetGrid() {
	for (auto &sq : squares) {
		for (int j = 0; j < 4; j++) {
			sq->sideOn[j] = false; 
		}
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
	// add mousePress rotation 
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
