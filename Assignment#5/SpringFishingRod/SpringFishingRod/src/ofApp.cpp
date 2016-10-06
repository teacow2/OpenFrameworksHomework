#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofBackground(0);
	k = 5000;
	restLength = 200;
	
	anchor = ofVec2f(10, 300);
	pivot = ofVec2f(ofGetWidth() / 2, 10);
	ball = ofVec2f((ofGetWidth() - 300), 10);

	gravity = ofVec2f(0,.028);
 
}
//--------------------------------------------------------------

//Our own function in the main

void ofApp::applyForce(ofVec2f _force) {
	acc += _force;
	
}

//--------------------------------------------------------------
void ofApp::update() {

	count++; 

	if (count < 2000) return; 
	
	//Steps to create the springy effect
	ofVec2f force = ball - pivot; // the direction of the vector

	float currentLength = force.length();
	float x = currentLength - restLength;
	//normalize refers to vector math whereby you multiply the vector by the "unit vector"
	force.normalize();
	force *= -1 * k * x;  //applying Hooke's Law
	


	// if(ball.x <= pivot.x) applyForce(force);
	
	if (x < 0)  applyForce(force);
	applyForce(gravity);
    applyForce(ofVec2f(0, 1.0));//brings the x component back to 0

								//Add dynamic movement
	vel += acc;
	ball += vel;
	cout << "Force: " << force << "Acc: " << acc << "Ball.y: " << ball.y << endl; 
	if (pivot.y < anchor.y) {
		pivot += vel;
	}
	acc *= 0; //set back to 0 to bring the spring thing back to a neutral position.


}

//--------------------------------------------------------------
void ofApp::draw() {
	
	ofDrawLine(pivot, ball);
	ofDrawLine(anchor, pivot);
	ofSetColor(255, 0, 0);
	ofDrawCircle(pivot, 10);
	ofSetColor(0, 255, 0);
	ofDrawCircle(anchor, 10);
	ofSetColor(255);
	ofDrawCircle(ball, 20);
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