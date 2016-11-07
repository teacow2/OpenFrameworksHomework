#pragma once
#include "ofMain.h"

typedef vector<ofVec2f> VectorList;

class FlowField {
public:
	FlowField();

	void setup(int width, int height, int depth, int res);
	void setRandom(const float &strength = 10.0f);
	void setPerlin();

	void update();
	void draw();

	ofVec2f getForceAtPosition(ofVec3f pos);

	void drawVector(const ofVec3f &start, const ofVec3f &end, float headLength = 0.2f, float headRadius = 0.05f);
	void drawVectorAt(const ofVec3f &vec, const ofVec3f &pos, const float &strength = 10.0);
	void addRepelForce(float x, float y, float z, float radius, float strength);
	void addAttractForce(float x, float y, float z, float radius, float strength);
	// void addCircularForce(float x, float y, float z, float radius, float strength);

	vector<vector<vector<ofVec3f>>>  flowList;
	int fieldWidth, fieldHeight, fieldDepth, resolution;
};

