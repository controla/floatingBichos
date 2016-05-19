#include "Bicho.h"

Bicho::Bicho() {

};

void Bicho::setup(int id, string _bichoPath) {

  // sound
  bichoSound.load(_bichoPath + "/bicho.wav");
  bichoSound.setLoop(true);

  // find layers
  ofLog(OF_LOG_NOTICE, "Creating bicho: " + _bichoPath);
  ofDirectory layerDir(_bichoPath);
  layerDir.allowExt("png");
  layerDir.listDir();
  layerDir.sort();

  layersTotal = layerDir.size();
  ofLog(OF_LOG_NOTICE, "bicho has: " + ofToString(layersTotal) + " layers");

  // layer settings
  string bichoSettings = ofToString(_bichoPath + "/bicho.xml");

  if (settings.loadFile(bichoSettings)) {
    ofLog(OF_LOG_NOTICE, "loading xml: " + bichoSettings);
  } else {
    ofLog(OF_LOG_WARNING, "error loading xml: " + bichoSettings);
  }

  // initialize each layer
  for(int thisLayer = 0; thisLayer < layersTotal; thisLayer++) {

    settings.pushTag("settings");
    settings.pushTag("layer" + ofToString(thisLayer));

    int layerHasOpacity = settings.getValue("hasOpacity", 0);
    int layerHasScale = settings.getValue("hasScale", 0);
    int layerHasRotate = settings.getValue("hasRotate", 0);
    int layerIsShy = settings.getValue("isShy", 0);

    settings.popTag();
    settings.popTag();

    myLayer[thisLayer].setup(thisLayer, layerDir.getPath(thisLayer), layerHasOpacity, layerHasScale, layerHasRotate, layerIsShy);

  }

}

void Bicho::update(float _speed, float _posx, float _posy, float _offset, float _scalemin, float _scalemax) {

  bichoSound.setVolume(bichoVolume); // adjust bicho volume

  angle = ofMap(sin(ofGetElapsedTimef()), 0, 1, 0, 359);

  // fading in
  if(isFadingIn && isAlive) {
    bichoOpacity += 5;
    bichoSound.setVolume(bichoVolume += .5);
  }
  // reached max
  if(isFadingIn && bichoOpacity >= 255) {
    bichoOpacity = 255;
    isFadingIn = false;
  }
  // fading out
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


  // use seeds
  _posx = seedX;
  _posy = seedY;

  // move the whole bicho
  bichoX = ofMap(ofNoise(ofGetElapsedTimef() * _speed + _posx),0,1,-10,10) * _offset;
  bichoY = ofMap(ofNoise(ofGetElapsedTimef() * _speed + _posy),0,1,-10,10) * _offset;

  if(bichoHasScale) {
		bichoScale = ofMap(ofNoise(ofGetElapsedTimef() * _speed),-1,1,_scalemin,_scalemax);
	}

  for(int i = 0; i < layersTotal; i++) {
    myLayer[i].update(_speed, bichoScale, bichoOpacity);
  }

}

void Bicho::draw() {

  ofSetColor(bichoOpacity);

  ofPushMatrix();

  //ofTranslate(myLayer[0].Layer.getWidth()/2, myLayer[0].Layer.getHeight()/2,0);
  //ofRotate(angle);
  //ofRotate(angle, 0, 0, 1);
    // all layers
    for(int i = 0; i < layersTotal; i++) {

      myLayer[i].draw();
    }

  ofPopMatrix();

}

void Bicho::remove () {
  if(isFadingIn) {
    isFadingIn = !isFadingIn;
  }

  isFadingOut = true;
}
