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
	Layer.draw(ofRandom(x-1,x+1),ofRandom(y-1,y+1));
}
