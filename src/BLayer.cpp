#include "BLayer.h"

BLayer::BLayer() {

};

void BLayer::setup(int _layerId, string _layerpath, int lOpacity, int lScale, int lRotate, int lShy) {

	ofLog(OF_LOG_NOTICE, "loading layer: " + ofToString(_layerpath));
	Layer.load(_layerpath);
	Layer.resize(ofGetHeight()/4,ofGetHeight()/4);

	layerAngle = 50;
	layerSeed = ofRandom(100);

	HasOpacity = lOpacity;
	HasScale = lScale;
	HasRotate = lRotate;
	isShy = lShy;

	ofLog(OF_LOG_NOTICE, ofToString(HasOpacity) + " " + ofToString(HasScale) + " " + ofToString(HasRotate) + " " + ofToString(isShy));

	if(isShy) {
		diff = ofRandom(1000);
	}

}

void BLayer::update( float _speed, float _scale, int _bichoOpacity) {

	// apply transformations

	if(HasOpacity) {
		if(isShy) {
			layerOpacity = ofMap(ofNoise(ofGetElapsedTimef() + diff),0,1,100,255);
		} else {
			layerOpacity = ofMap(ofNoise(ofGetElapsedTimef() + diff),0,1,0,255);
		}
	} else {
		layerOpacity = _bichoOpacity;
	}

	if(HasScale) {
		layerScale = _scale; // duh
	}

	if(HasRotate) {
		layerAngle = ofMap(ofNoise(ofGetElapsedTimef() * _speed), 0, 1, -20, 20);
	}

	layerX = ofGetHeight() / 6; // half the size of the fbo
	layerY = ofGetHeight() / 6;

}

void BLayer::draw() {

	ofSetColor(255,255,255,layerOpacity);

	ofPushMatrix();

		// draw from center
		Layer.setAnchorPercent(.5, .5);

		ofTranslate(layerX, layerY, 0);		// origin on the layer center (center of fbo size)
		ofRotate(layerAngle);
		ofScale(layerScale, layerScale, 1);

		// found something here!
		float lX = ofMap(ofNoise( (ofGetElapsedTimef() + layerSeed) * 0.1), 0, 1, -7, 7);
		float lY = ofMap(ofNoise( (ofGetElapsedTimef() + layerSeed) * 0.1), 0, 1, -7, 7);

		Layer.draw(lX, lY);

		//ofNoFill();
	  //ofDrawRectangle(0,0,Layer.getWidth(),Layer.getHeight());

	ofPopMatrix();

}
