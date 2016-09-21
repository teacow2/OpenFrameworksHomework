#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofBackground(255);

	for (int i = 0; i < num; i++) {
		Particle p; 
		particles.push_back(p);

		particles[i].setup();

	



	}

}

//--------------------------------------------------------------
void ofApp::update(){




}

//--------------------------------------------------------------
void ofApp::draw(){
	


	for (int i = 0; i < particles.size(); i++) {
		particles[i].explosion();
		particles[i].draw(); 

		if (ofGetFrameNum() % particles[i].countExp == 0) {
			particles.erase(particles.begin()+i);
			if (particles.size() < 1) {
				for (int i = 0; i < num; i++) {
					Particle p;
					particles.push_back(p);

					particles[i].setup();
				}

			}
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
