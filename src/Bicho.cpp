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

void Bicho::update(float _speed, float _posx, float _posy, float _offset) {

  // move the whole bicho
  bichoX = sin(ofGetElapsedTimef() + _speed + _posx) * _offset;
  bichoY = sin(ofGetElapsedTimef() + _speed + _posy) * _offset;

  for(int i = 0; i < layersTotal; i++) {
    myLayer[i].update();
  }

  if(isFadingOut && isAlive) {
    bichoOpacity -= 1;
  }

  if(isFadingIn && isAlive) {
    bichoOpacity += 1;
  }

}

void Bicho::draw() {

  ofSetColor(bichoOpacity);

  // all layers
  for(int i = 0; i < layersTotal; i++) {
    myLayer[i].draw();
  }

}

void Bicho::remove () {
  isFadingOut = true;
}
