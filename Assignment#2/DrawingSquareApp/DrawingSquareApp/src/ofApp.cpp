#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetBackgroundAuto(false);
	
	shapeType = ofRandom(0,2); 

	delayCount = 10; 

	textDraw = true; 
}

//--------------------------------------------------------------
void ofApp::update(){

	shapeB = ofRandom(0, 255);

	
	
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSetColor(0);
	ofDrawBitmapString("Click mouse to change color and shape. Color based on mouse position.", 20, 1078);

	ofSetColor(shapeR, shapeG, shapeB);

	pos = ofPoint(mouseX, mouseY);
	if(ofGetFrameNum() % delayCount == 0) {
		switch (shapeType) {
		case 0:
			ofDrawCircle(pos, ofRandom(25.0, 75.0));
			break;
		case 1:
			ofSetRectMode(OF_RECTMODE_CENTER);
			ofDrawRectangle(pos, ofRandom(50, 100), ofRandom(50, 100));
			break;
		case 2:
			ofDrawTriangle(pos, ofPoint(pos.x + ofRandom(-100, 100), pos.y + ofRandom(-100, 100)), ofPoint(pos.x + ofRandom(-100, 100), pos.y + ofRandom(-100, 100)));
			break;
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
	shapeR = ofMap(mouseX, 0, ofGetWidth(), 0, 255);
	shapeG = ofMap(mouseY, 0, ofGetHeight(), 0, 255);
	
	shapeType++; 
	if (shapeType >= 3) shapeType = 0; 


	

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
