#pragma once

#include "BLayer.h"
#include "ofMain.h"
#include "ofxGui.h"

#define MAXLAYERS 20

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();

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

	// this should come from ofDirectory
	string layerPath = "bichos/b0";

	ofFbo fbo;

	int layersTotal;
	float areaX[2];

	int safezone = 250;

	float bX;
	float bY;

	bool debug;

	ofxPanel gui;
  ofParameter<float> positionX;
  ofParameter<float> positionY;
	ofParameter<float> bOffset;
	ofParameter<float> bSpeed;

	BLayer myLayer[MAXLAYERS];

};
