#include "Bicho.h"

Bicho::Bicho() {

};

void Bicho::setup(string _bichoPath) {

  ofLog(OF_LOG_NOTICE, "Creating bicho: " + _bichoPath);
  ofDirectory layerDir(_bichoPath);
  layerDir.allowExt("png");
  layerDir.listDir();
  layerDir.sort();

  layersTotal = layerDir.size();
  ofLog(OF_LOG_NOTICE, "bicho has: " + ofToString(layersTotal) + " layers");


  // put their path in an array and use it to initialize each bicho, creating an ofImage for each layer
  for(int thisLayer = 0; thisLayer < layersTotal; thisLayer++) {
    myLayer[thisLayer].setup(layerDir.getPath(thisLayer));
  }

  isAlive = true;
  bichoOpacity = 255;

}

void Bicho::update(float _speed, float _posx, float _posy, float _offset, float _scalemin, float _scalemax) {

  if(isFadingIn && isAlive) {
    bichoOpacity += 1;
  }

  if(isFadingIn && bichoOpacity >= 255) {
    bichoOpacity = 255;
    isFadingIn = false;
  }

  if(isFadingOut && isAlive) {
    bichoOpacity -= 1;
  }

  if(isFadingOut && bichoOpacity < 1) {
    bichoOpacity = 0;
    isFadingOut = false;
    isAlive = false;
  }

  // move the whole bicho
  bichoX = ofMap(ofNoise(ofGetElapsedTimef() * _speed + _posx),0,1,-10,10) * _offset;
  bichoY = ofMap(ofNoise(ofGetElapsedTimef() * _speed + _posy),0,1,-10,10) * _offset;

  if(bichoHasScale) {
		bichoScale = ofMap(ofNoise(ofGetElapsedTimef() * _speed),-1,1,_scalemin,_scalemax);
	}

  for(int i = 0; i < layersTotal; i++) {
    myLayer[i].update(_speed, bichoScale);
  }

}

void Bicho::draw() {

  ofSetColor(bichoOpacity);

  // all layers
  for(int i = 0; i < layersTotal; i++) {
    myLayer[i].draw();
  }

  ofSetColor(255);
  ofColor(255);
  ofRectangle(0,0,myLayer[0].Layer.getWidth(),myLayer[0].Layer.getHeight());

}

void Bicho::remove () {
  if(isFadingIn) {
    isFadingIn = !isFadingIn;
  }

  isFadingOut = true;
}
