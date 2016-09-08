//
//  rectangle.cpp
//  rectangleXeno
//
//  Created by Regina Flores on 9/1/16.
//
//

#include "rectangle.hpp"


rectangle::rectangle() {
	catchUpSpeed = 0.005;

	rectR = 15; 

	rectG = 15;

	rectB = 115; 

}

void rectangle::draw() {

	ofFill();

	ofSetRectMode(OF_RECTMODE_CENTER);

	ofSetColor(rectR, rectG, rectB);

	ofRect(pos.x, pos.y, 40, 40);
}

void rectangle::xenoToPoint(float catchX, float catchY) {
	//Xeno formula:
	//myPos = (1-pct) * myPos + pct * targetPos

	pos.x = catchUpSpeed * catchX + (1 - catchUpSpeed) *pos.x;
	pos.y = catchUpSpeed * catchY + (1 - catchUpSpeed) *pos.y;

}
