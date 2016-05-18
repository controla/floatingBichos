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

  // isAlive = true;
  // bichoOpacity = 255;

  bichoSound.load(_bichoPath + "/bicho.wav");
  bichoSound.setLoop(true);

}

void Bicho::update(float _speed, float _posx, float _posy, float _offset, float _scalemin, float _scalemax) {

  if(isFadingIn && isAlive) {
    bichoOpacity += 5;
    bichoSound.setVolume(bichoVolume += .5);
    // bichoSound volume += 5; ****
  }

  // reached max
  if(isFadingIn && bichoOpacity >= 255) {
    bichoOpacity = 255;
    isFadingIn = false;
  }

  if(isFadingOut && isAlive) {
    bichoOpacity -= 5;
    bichoVolume -= .5;

    if (bichoVolume < 0) {
      bichoVolume = 0;
    }

  }

  // kill bicho
  if(bichoOpacity < 1 && isFadingOut) {
    bichoOpacity = 0;
    isFadingOut = false;
    isAlive = false; // bye bye
  }

  bichoSound.setVolume(bichoVolume); // adjust bicho volume

  _posx = seedX;
  _posy = seedY;

  // move the whole bicho
  bichoX = ofMap(ofNoise(ofGetElapsedTimef() * _speed + _posx),0,1,-10,10) * _offset;
  bichoY = ofMap(ofNoise(ofGetElapsedTimef() * _speed + _posy),0,1,-10,10) * _offset;

  if(bichoHasScale) {
		bichoScale = ofMap(ofNoise(ofGetElapsedTimef() * _speed),-1,1,_scalemin,_scalemax);
	}

  for(int i = 0; i < layersTotal; i++) {
    myLayer[i].update(_speed, bichoScale);
  }

  // sound
  //


}

void Bicho::draw() {

  ofSetColor(bichoOpacity);

  // all layers
  for(int i = 0; i < layersTotal; i++) {
    myLayer[i].draw();
  }

}

void Bicho::remove () {
  if(isFadingIn) {
    isFadingIn = !isFadingIn;
  }

  isFadingOut = true;
}
