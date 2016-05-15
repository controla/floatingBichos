#pragma once

#include "Bicho.h"
#include "ofMain.h"
#include "ofxGui.h"

#define MAXBICHOS 20

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		void summon(int _bichoNew);

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);


	string bichosBasePath = "bichos";
	// this should come from ofDirectory
	string bichoPath[MAXBICHOS];

	// string layerPath = "bichos/b0";
	//string layerPath[MAXLAYERS];

	ofFbo fbo;

	int bichosTotal;
	int bichoActive;
	int bichoNext;

	float areaX[2];

	int safezone = 250;

	bool debug;

	ofxPanel gui;
  ofParameter<float> positionX;
  ofParameter<float> positionY;
	ofParameter<float> bOffset;
	ofParameter<float> bSpeed;

	Bicho myBicho[MAXBICHOS];

};
