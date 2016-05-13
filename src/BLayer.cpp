#include "BLayer.h"

BLayer::BLayer() {

};

void BLayer::setup(string _path) {
	Layer.load(_path);
	Layer.resize(ofGetHeight()/4,ofGetHeight()/4);
}

void BLayer::update() {


}

void BLayer::draw() {
	ofSetColor(255);
	float padding = 25;
	Layer.draw(padding + ofRandom(x-1,x+1), padding + ofRandom(y-1,y+1));
}
