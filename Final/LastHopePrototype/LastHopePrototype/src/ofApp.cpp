#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);

	currentWidth = baseWidth = 40; 

	shipID = 0; 
	baseAngle = 45; 

	gameOver = false; 

	step = .001; 
	
	spacing = 150; 
	targetBarrier = 500;
	
	//enemyThres = ofRandom(1500, 1750);
	enemyThres = ofRandom(500, 750);
	// enemyThres = 1000000000; // test value 

	enemyShipCount = 0; 

	avoidForce = 20; 

	for (int i = 0; i < 2; i++) {
		Mothership m;
		m.setup(i);
		mothership.push_back(m);
	}

}

//--------------------------------------------------------------
void ofApp::update(){
	if (mothership[0].health <= 0) {
		gameOver = true;
	}
	else if (mothership[1].health <= 0) {
		gameOver = true; 
	}
	if (!gameOver) {
		enemyShipCount++;

		//	cout << "Enemy Count: " << enemyShipCount << endl; 

		if (enemyShipCount > enemyThres) {
			Ship s;
			s.setup(false, 1, ofPoint(currentWidth, 150), shipID);
			ships.push_back(s);
			currentWidth += spacing; if (currentWidth > ofGetWidth()) currentWidth = baseWidth;
			enemyShipCount = 0;
			enemyThres = ofRandom(1500, 1750);
			//enemyThres = 10000000; // test value
			shipID++;
		}

		swarmMove();


		for (int i = 0; i < shots.size(); i++) {

			shots[i].update();
			if (shots[i].count > shots[i].duration) {

				shots.erase(shots.begin() + i);

			}
		}

		for (int i = 0; i < ships.size(); i++) {

			ofPoint tempMotherTarget;

			if (ships[i].playerShip) {
				tempMotherTarget = mothership[1].center;
			}
			else {
				tempMotherTarget = mothership[0].center;
			}

			ships[i].resetForce();

			findTarget(i, tempMotherTarget);

			for (int j = 0; j < ships.size(); j++) {
				if (i == j) continue;
				ships[i].addRepel(ships[j].pos, targetBarrier, avoidForce);
			}

			//	cout << "Current force on ship " << i << ": " << ships[i].force << endl; 

			ships[i].calcForce();

			fireShots();

			killShips();




		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	for (int i = 0; i < 2; i++) {
		mothership[i].draw();
	}

	for (int i = 0; i < ships.size(); i++) {

		ships[i].draw(); 
	}

	for (int i = 0; i < shots.size(); i++) {

		shots[i].draw(); 
	}
}




void ofApp::swarmMove() {
	for (int i = 0; i < swarms.size(); i++) {
		ofPoint centerSwarm = ofPoint(ofGetWidth() / 2, ofGetHeight() / 2);
		for (int j = 0; j < swarms[i].size(); j++) {
	//		cout << "Displaying Ship " << j << " of Swarm " << i << endl; 

			ships[swarms[i][j]].swarmAngle += step;

			//ships[swarms[i][j]].pos.x = centerSwarm.x + ships[swarms[i][j]].targetRad * cos(ships[swarms[i][j]].swarmAngle);
			//ships[swarms[i][j]].pos.y = centerSwarm.y + ships[swarms[i][j]].targetRad * sin(ships[swarms[i][j]].swarmAngle);

			ships[swarms[i][j]].pos.x = (centerSwarm.x) + (ships[swarms[i][j]].shiftNum/6 * sin((ships[swarms[i][j]].aNum * ships[swarms[i][j]].swarmAngle)));
			ships[swarms[i][j]].pos.y = (centerSwarm.y)+((ships[swarms[i][j]].shiftNum/6) * sin(ships[swarms[i][j]].bNum * ships[swarms[i][j]].swarmAngle));



			ships[swarms[i][j]].rotateAngle = ships[swarms[i][j]].swarmAngle;

		}
	}

}


void ofApp::killShips() {
	for (int i = 0; i < ships.size(); i++) {
		if (ships[i].health < 0) {

	//		cout << "Ship " << i << "marked dead." << endl; 
			for (int j = 0; j < swarms[ships[i].swarmNum].size(); j++) {
				if (ships[i].id == ships[swarms[ships[i].swarmNum][j]].id) {
			//		cout << "Erased Ship " << i << " from swarm" << endl; 
				
					swarms[ships[i].swarmNum].erase(swarms[ships[i].swarmNum].begin() + j);
				}
			}
			bool testTarget = ships[swarms[ships[i].swarmNum][0]].playerShip;
			bool swarmDone = true;

			for (int j = 0; j < swarms[ships[i].swarmNum].size(); j++) {
				if (ships[swarms[ships[i].swarmNum][j]].playerShip != testTarget) {
					swarmDone = false;
				}
			}

			if (swarmDone) {
		//		cout << "Swarm dead" << endl; 
				for (int j = 0; j < swarms[ships[i].swarmNum].size(); j++) {
					ships[swarms[ships[i].swarmNum][j]].engagedT = false; 
				}

				swarms.erase(swarms.begin() + ships[i].swarmNum);
			}
			ships.erase(ships.begin() + i);
		}

	}


}

void ofApp::fireShots() {
	for (int i = 0; i < ships.size(); i++) {
		if (ships[i].engagedM || ships[i].engagedT) {
			if (ships[i].attCount < ships[i].attFreq) {
				ships[i].attCount++;
			}
			else {
		//		cout << "Ship " << i << " that is " << ships[i].playerShip << " Player ships is shooting at "; 
				ships[i].attCount = 0;
				if (ships[i].engagedM) {
					int targetM; 
					if (ships[i].playerShip) targetM = 1; else targetM = 0;
			//		cout << "the " << targetM << "mothership" << endl; 
					mothership[targetM].health -= ofRandom(ships[i].damMin, ships[i].damMax); 
					Shot s; 
					s.setupM(ships[i], mothership[targetM].center);
					shots.push_back(s);

				}
				else if (ships[i].engagedT) {
					for (int j = 0; j < swarms[ships[i].swarmNum].size(); j++) { 
					//	cout << "Checking swarm entry " << j << endl; 
						if (ships[swarms[ships[i].swarmNum][j]].playerShip != ships[i].playerShip) {
				//			cout << "the target ship " << swarms[ships[i].swarmNum][j] << endl;
							ships[swarms[ships[i].swarmNum][j]].health -= ofRandom(ships[i].damMin, ships[i].damMax);
							Shot s;
							s.setup(ships[swarms[ships[i].swarmNum][j]], ships[i]);
							shots.push_back(s);

						}

					}
				}

			}
		}
	}
	
}



void ofApp::findTarget(int _selected, ofPoint _motherTarget) {
	bool targetSet = false; 
	for (int j = 0; j < ships[_selected].target.size(); j++) {
		if (ships[_selected].engagedT) continue; 
		switch (ships[_selected].target[j]) {
//
// looking for another ship 
//

		case 1:

			int closest;
			int targetNum;
			if (ships[_selected].engagedT) {break;}
			for (int i = 0; i < ships.size(); i++) {
				if (ships[_selected].id == ships[i].id) continue;
				if (ships[i].playerShip == ships[_selected].playerShip) continue;
				ofPoint diff = ships[i].pos - ships[_selected].pos;
				if (diff.length() < closest || targetSet == false) {
					targetNum = i;
					closest = diff.length();
					targetSet = true;
				}

			}
			if (targetSet == false) break;

			if (closest < ships[_selected].targetRad) {

				ships[_selected].engagedT = true; ships[_selected].engagedM = false; 
				ships[targetNum].engagedT = true; ships[targetNum].engagedM = false;
				ships[_selected].tarNum = targetNum; ships[targetNum].tarNum = _selected; 
				bool swarmSet = false;
				for (int k = 0; k < swarms.size(); k++) {
					for (int m = 0; m < swarms[k].size(); m++) {
						if (swarms[k][m] == targetNum) {
							swarms[k].push_back(_selected); 
							ships[_selected].swarmNum = k; 
							swarmSet = true; 
							ships[_selected].swarmAngle = swarms[k].size() * baseAngle; 
						}
					}
				}
				if (!swarmSet) {
					vector<int> s;
					swarms.push_back(s);
					swarms.back().push_back(_selected);
					ships[_selected].swarmAngle = baseAngle; 
					ships[_selected].swarmNum = swarms.size() - 1; 
					swarms.back().push_back(targetNum);
					ships[targetNum].swarmAngle = baseAngle * 2; 
					ships[targetNum].swarmNum = swarms.size() - 1;
				}
			}
			else {
				ships[_selected].engagedT = false;
				ships[_selected].addAttract(ships[targetNum].pos, ships[_selected].speedMod);

			}
			break;
//
// going after mothership  
//

		case 0:
			ofPoint tempDiff;
			targetSet = true;
			tempDiff = _motherTarget - ofPoint(ships[_selected].pos.x, ships[_selected].pos.y);
			if (tempDiff.length() < ships[_selected].motherRad) { ships[_selected].engagedM = true;}
			if (ships[_selected].engagedM) {
				cout << "Ship" << ships[_selected].id << " engaged with Mothership" << " "; 
				float fixedY;
				if (ships[_selected].playerShip) {
					fixedY = 150;
					ships[_selected].angle = 90;
//					cout << "Going to: " << fixedY << " "; 
				}
				else {
					fixedY = ofGetHeight() - 150;
					ships[_selected].angle = 45;
				}

				ships[_selected].pos.x = (ofGetWidth() / 2) + (ships[_selected].shiftNum * sin((ships[_selected].aNum * ofGetElapsedTimef()) + ships[_selected].angle));
				ships[_selected].pos.y = (fixedY) + ((ships[_selected].shiftNum/6) * sin(ships[_selected].bNum * ofGetElapsedTimef()));


				/*
				ofPoint curveTarget;
				curveTarget.x = (ofGetWidth() / 2) + (ships[_selected].shiftNum * sin((ships[_selected].aNum * (ofGetElapsedTimef() + ships[_selected].randCount)) + ships[_selected].angle));
				curveTarget.y = (fixedY)+((ships[_selected].shiftNum / 10) * sin(ships[_selected].bNum * (ofGetElapsedTimef() + ships[_selected].randCount)));
				ofPoint curveDist = curveTarget - ships[_selected].pos; 
				float curveSpeed = ofMap(curveDist.length(), 0, 50, 0, ships[_selected].speedMod *10);
				ships[_selected].addAttract(curveTarget, curveSpeed);
				*/
			}
			else {
				cout << "Ship " << ships[_selected].id << " going to mothership from distance of" << tempDiff.length() << " and needs to be at " << ships[_selected].motherRad << endl;
				ships[_selected].engagedM = false;
				ships[_selected].addAttract(_motherTarget, ships[_selected].speedMod);

			}


		}

		if (targetSet) { 
			break; 
		}
	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

	if (key == '1') {
		Ship s; 
		s.setup(true, 1, ofPoint(currentWidth, ofGetHeight() - 150), shipID);
		ships.push_back(s);


	}

	if (key == '2') {
		Ship s; 
		s.setup(true, 2, ofPoint(currentWidth, ofGetHeight() - 150), shipID);
		ships.push_back(s);

	}

	currentWidth += spacing; if (currentWidth > ofGetWidth()) currentWidth = baseWidth;
	
	shipID++; 
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
