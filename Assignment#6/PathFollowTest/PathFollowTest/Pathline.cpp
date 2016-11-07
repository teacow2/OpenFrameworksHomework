#include "Pathline.hpp"



Pathline::Pathline()
{


	start = ofPoint(0, ofGetHeight() / 3);
	end = ofPoint(ofGetWidth(), 2 * (ofGetHeight() / 3));

}

void Pathline::display() {
	ofSetColor(255);
	ofDrawLine(start, end);
	
}
