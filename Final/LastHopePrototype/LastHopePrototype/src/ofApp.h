#pragma once

#include "ofMain.h"
#include "../Ship.hpp"
#include "../Mothership.hpp"
#include "../Shot.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void findTarget(int _selected, ofPoint _motherTarget);

		void swarmMove();


		void fireShots();
		void killShips();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		
	
		bool gameOver; 

		int baseWidth; 

		int spacing; 

		float targetBarrier;

		float avoidForce;

		int enemyShipCount; 

		int enemyThres; 

		int currentWidth; 

		int baseAngle; 

		float step;

		vector<Ship> ships; 

		vector< vector<int> > swarms; 

		vector <Mothership> mothership;

		vector <Shot> shots; 

		int shipID; 


		
		
};
