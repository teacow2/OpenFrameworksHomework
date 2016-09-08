//
//  MyObj.hpp
//  MyObject
//
//  Created by Regina Flores on 9/1/16.
//
//

#pragma once //just do this dont ask question FOR NOW

#include "ofMain.h"

class MyObj {

public:

	MyObj(); 

	void setSrc(float _x, float _y);
	void setDst(float _x, float _y);


	//    void updatePct(float _pct);

	void powUpdatePct(float _pct, float _shaper);

	void draw();
	


private:

	ofPoint src, dst;
	ofPoint pos;

	float sizeMin; 
	float sizeMax; 

	float sizeCurrent; 

};






