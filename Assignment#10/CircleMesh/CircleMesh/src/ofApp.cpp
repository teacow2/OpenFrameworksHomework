#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	num = 2000;


	for (int i = 0; i< num; i++) {
		//we need to initliaze all of our arrays

		ofPoint p;
		points.push_back(p);

		float t;
		theta.push_back(t);

		float ph;
		phi.push_back(ph);

		int r;
		radius.push_back(r);


		float chPh;
		changePhi.push_back(chPh);

		float cT;
		changeTheta.push_back(cT);



		//to make the points randomly distributed on the sphere
		//we know that theta ranges from 0-2PI
		//phi ranges from 0-PI

		theta[i] = ofRandom(0, 2 * PI);
		phi[i] = ofRandom(0, PI);
		//        radius[i] = 180; //if you leave a constant number the points will be evenly distributed on the surface
		radius[i] = ofRandom(180, 220);


		points[i] = ofPoint(
			radius[i] * cos(theta[i])*sin(phi[i]),
			radius[i] * sin(phi[i])*sin(theta[i]),
			radius[i] * cos(phi[i])
		);


		changeTheta[i] = ofRandom(0, 0.01);
		changePhi[i] = ofRandom(0, 0.01);

	}




	//make a grid of connected lines
	//which are really this notion of vertices
	for (int i = 0; i<points.size(); i++) {
		// create variability
		points[i] = ofPoint(radius[i] * cos(theta[i])*sin(phi[i]), radius[i] * sin(theta[i])*sin(phi[i]), radius[i] * cos(phi[i]));


		noisey = sin(0.01*ofGetFrameNum());
		radius[i] = ofNoise(theta[i] * noisey, phi[i] * noisey) * 400;

		theta[i] += changeTheta[i];
		phi[i] += changePhi[i];

		//create our mesh:
		mesh.addVertex(points[i]);
		mesh.addColor(ofColor(0, 0, 0));
	}







	//create the triangle indices
	for (int i = 0; i < num; i++) {
		for (int j = i + 1; j < num; j++) {
			for (int k = j + 1; k < num; k++) {
				dist = pow(points[i].x - points[j].x, 2) + pow(points[i].y - points[j].y, 2) + pow(points[i].z - points[j].z, 2);
				dist2 = pow(points[j].x - points[k].x, 2) + pow(points[j].y - points[k].y, 2) + pow(points[j].z - points[k].z, 2);
				dist3 = pow(points[k].x - points[i].x, 2) + pow(points[k].y - points[i].y, 2) + pow(points[k].z - points[i].z, 2);
				if (dist < 2 * 1000 && dist2 < 2 * 1000 && dist3 < 2 * 1000) {

					mesh.addTriangle(i, j, k);
				}
			}
		}
	}






}

//--------------------------------------------------------------
void ofApp::update() {

	float time = ofGetElapsedTimef();

	//Now we want to loop through every vertex:
	//0, 1, 2, 3...

	for (int i = 0; i < points.size(); i++) {

		ofPoint p = mesh.getVertex(i);

		float perlin = ofNoise(points[i].x*0.05, points[i].y*0.05, points[i].z*.05, time *0.5);
		// p.z = perlin * 100;

		mesh.setVertex(i, p);
		mesh.setColor(i, ofColor(perlin * 255, perlin * 255, 255));

	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofBackground(0);

	cam.begin();

	mesh.drawWireframe();

	cam.end();

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
