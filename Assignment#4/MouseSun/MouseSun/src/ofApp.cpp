#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	sunExists = false;
	sunRadius = 50;
	ofBackground(0);
	step = .001; 


	for (int i = 0; i < 5; i++) {
		ParticleMoon p; 
		p.setup(i);
		moons.push_back(p);
	}

	gui.setup();
	gui.add(stepSlider.setup("stepSlider", 0.001, 0.0001, .01));
}

//--------------------------------------------------------------
void ofApp::update(){
	for (int i = 0; i < moons.size(); i++) {
		moons[i].reset();
		if (sunExists) {
			moons[i].update(stepSlider*moons[i].moonSpeed, sun, sunExists);
		}
		else {
			moons[i].update(stepSlider*moons[i].moonSpeed, ofPoint(mouseX, mouseY), sunExists);
		}
	} 
}

//--------------------------------------------------------------
void ofApp::draw() {

	if (sunExists) {

		ofFill();
		ofSetColor(255, 150, 0);
		ofDrawCircle(sun, sunRadius);
	}

	for (int i = 0; i < moons.size(); i++) {
		ofFill();
		ofSetColor(moons[i].moonR, moons[i].moonG, moons[i].moonB);
		moons[i].draw();
	}

	gui.draw();
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

	if (sunExists) {
		sunExists = false; 
		for (int i = 0; i < moons.size(); i++) {

			if (moons[i].x < moons[i].moonSize || moons[i].x > ofGetWidth() - moons[i].moonSize) {
				moons[i].x = ofRandom(moons[i].moonSize / 2, ofGetWidth() - (moons[i].moonSize / 2));
			}

			if (moons[i].y < moons[i].moonSize || moons[i].y > ofGetHeight() - moons[i].moonSize) {
				moons[i].y = ofRandom(moons[i].moonSize / 2, ofGetHeight() - (moons[i].moonSize / 2));
			}
			moons[i].vel = ofPoint((ofRandom(-1, 1)*moons[i].moonSpeed), (ofRandom(-1, 1)*moons[i].moonSpeed));

		}
 	}
	else {
		sunExists = true; 
		sun.set(mouseX, mouseY);
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
