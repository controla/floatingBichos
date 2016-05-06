#include "BLayer.h"

BLayer::BLayer() {

};

void BLayer::setup(string _path) {
	Layer.load(_path);
}

void BLayer::update(float _x, float _y) {

	//float wave = sin(ofGetElapsedTimef()) * 1;

	speedX = ofRandom(-1,1);
	speedY = ofRandom(-1,1);

	x = _x + speedX;
	y = _y + speedY;

}

void BLayer::draw() {

	Layer.draw(x,y);

}