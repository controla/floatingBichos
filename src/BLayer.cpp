#include "BLayer.h"

BLayer::BLayer() {

};

void BLayer::setup(string _path) {
	ofLog(OF_LOG_NOTICE, "loading layer: " + ofToString(_path));
	Layer.load(_path);
	Layer.resize(ofGetHeight()/4,ofGetHeight()/4);

	layerOpacity = 255;


	// get settings for layer
	layerHasOpacity = true;
	layerHasScale = true;
	layerHasRotate = true;

	layerScaleMin = -1 * ofGetHeight()/4;
	layerScaleMax = ofGetHeight()/4;

	layerAngleMin = -20;
	layerAngleMax = 20;

}

void BLayer::update(float _speed, float _scale) {

	// apply transformations

	if(layerHasOpacity) {
		// layerOpacity = ofMap(sin(ofGetElapsedTimef()),-1,1,0,255);
	}

	if(layerHasScale) {
		layerScale = _scale;
	}

	if(layerHasRotate) {
		layerAngle = ofMap(ofNoise(ofGetElapsedTimef() * _speed),0,1,layerAngleMin,layerAngleMax);
	}

	layerX = ofGetHeight() / 6;
	layerY = ofGetHeight() / 6;

}

void BLayer::draw() {

	// ofSetColor(layerOpacity);

	ofPushMatrix();

		ofTranslate(layerX,layerY,0);		// origin on the layer center
		ofRotate(layerAngle);
		ofScale(layerScale,layerScale,1);

		// center within the fbo size
		//Layer.setAnchorPoint(Layer.getWidth()/2, Layer.getHeight()/2);
		Layer.setAnchorPercent(.5, .5);
		Layer.draw(ofRandom(-1,1), ofRandom(-1,1));	// draw layer at origin (center)

	ofPopMatrix();

}
