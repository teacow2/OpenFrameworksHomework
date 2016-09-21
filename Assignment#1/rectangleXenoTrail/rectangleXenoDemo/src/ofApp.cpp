#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetVerticalSync(true);
	ofEnableAlphaBlending();


	for (int i = 0; i< 4; i++) {
		rectangle temp;
		myRect.push_back(temp);

		myRect[i].catchUpSpeed /= i + 1; 
		
	//	myRect[i].pos.x = 100+(i*20);
	//	myRect[i].pos.y = 50+(i*10);

		myRect[i].pos.x = ofRandom(0.0, ofGetWidth());
		myRect[i].pos.y = ofRandom(0.0, ofGetHeight());

		myRect[i].rectR += (i * 30);
	//	myRect[i].rectG += (i * 30);
	//	myRect[i].rectB += (i * 30);

		
	}

}

//--------------------------------------------------------------
void ofApp::update() {
	for (int i = 0; i < 4; i++) {
		if (i == 0) {
			myRect[i].xenoToPoint(mouseX, mouseY);
		}
		else {
			myRect[i].xenoToPoint(myRect[i - 1].pos.x, myRect[i - 1].pos.y);
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	for (int i = 0; i < 4; i++) {
		myRect[i].draw();
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
