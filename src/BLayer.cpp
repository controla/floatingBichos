#include "BLayer.h"

BLayer::BLayer() {

};

void BLayer::setup(string _path) {
	Layer.load(_path);
	ofLog(OF_LOG_NOTICE, "loading layer: " + ofToString(_path));
	Layer.resize(ofGetHeight()/4,ofGetHeight()/4);
}

void BLayer::update() {
}

void BLayer::draw() {

	// calculate padding to center the image on the fbo
	float padding = (ofGetHeight()/3 - ofGetHeight()/4) / 2;

	Layer.draw(padding + ofRandom(x-1,x+1), padding + ofRandom(y-1,y+1));
	
}
