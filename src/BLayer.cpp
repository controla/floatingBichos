#include "BLayer.h"

BLayer::BLayer() {

};

void BLayer::setup(string _path) {
	ofLog(OF_LOG_NOTICE, "loading layer: " + ofToString(_path));
	Layer.load(_path);
	Layer.resize(ofGetHeight()/4,ofGetHeight()/4);

	layerOpacity = 255;

	layerHasOpacity = true;
	layerHasScale = true;
	layerHasRotate = true;

}

void BLayer::update() {

	// apply transformations

	if(layerHasOpacity) {
	// layerOpacity = ofMap(sin(ofGetElapsedTimef()),-1,1,0,255);
	}

	if(layerHasScale) {
		layerScale = ofMap(sin(ofGetElapsedTimef()),-1,1,1,2);
	}

	if(layerHasRotate) {
		layerAngle = ofMap(ofNoise(ofGetElapsedTimef()),-1,1,-30,30);
	}

	layerX = ofGetHeight() / 3 / 2;
	layerY = ofGetHeight() / 3 / 2;

}

void BLayer::draw() {

	// calculate padding to center the image on the fbo -> should use setAnchorPoint on Layer image
	// float padding = (ofGetHeight()/3 - ofGetHeight()/4) / 2;

	// ofSetColor(layerOpacity);

	ofPushMatrix();
		ofTranslate(layerX,layerY,0);
		ofRotate(layerAngle);
		// ofScale(layerScale,layerScale,layerScale);

		Layer.setAnchorPoint(Layer.getWidth()/2, Layer.getHeight()/2);
		// Layer.draw(padding + layerX, padding + layerY);

		Layer.draw(ofRandom(-2,2), ofRandom(-1,1));
		//Layer.draw(padding + ofRandom(x-1,x+1), padding + ofRandom(y-1,y+1));

	ofPopMatrix();

}
