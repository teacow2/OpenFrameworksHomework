#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){

	num = 10; 

	rate = 6; 

	ofBackground(0);

	for (int i = 0; i < num; i++) {
		Snowflake s; 
		s.setup();
		snowflakes.push_back(s);

	}

}

//--------------------------------------------------------------
void ofApp::update(){

	if (ofGetFrameNum() % rate == 0) {
		int newFlakes = ofRandom(3, 6);
		for (int i = 0; i < newFlakes; i++) {
			Snowflake s; 
			s.setup();
			snowflakes.push_back(s);
		}

	}

	for (int i = 0; i < snowflakes.size(); i++) {
		snowflakes[i].update();
		if (snowflakes[i].pos.y > ofGetHeight()) {
			snowflakes.erase(snowflakes.begin() + i);
		}
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	for (int i = 0; i < snowflakes.size(); i++) {

		snowflakes[i].draw();
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
