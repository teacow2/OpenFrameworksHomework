#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	myField.setup(ofGetWindowWidth(), ofGetWindowHeight(), ofGetWindowWidth(), 20);

	particleList.clear();

	for (int i = 0; i<300; i++) {
		addParticle();
	}

	ofBackground(0);
}

void ofApp::addParticle() {
	Particle part;
	part.pos = ofVec3f(ofRandomWidth(), ofRandomHeight(), ofRandomWidth());

	particleList.push_back(part);
}

//--------------------------------------------------------------
void ofApp::update() {
	myField.update();

	for (int i = 0; i<particleList.size(); i++) {
		particleList[i].applyForce(myField.getForceAtPosition(particleList[i].pos) * 0.005);
		particleList[i].update();
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	myCam.begin();

	ofSetColor(255);
	myField.draw();

	ofSetColor(0, 255, 255);
	for (int i = 0; i<particleList.size(); i++) {
		particleList[i].draw();
	}

	myCam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == '1') {
		myField.setRandom(20.0);
	}
	else if (key == '2') {
		myField.setPerlin();
	}
	else if (key == 'r') {
		for (int i = 0; i<particleList.size(); i++) {
			particleList[i].pos = ofVec2f(ofRandomWidth(), ofRandomHeight());
		}
	}
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
