#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

  ofSetWindowTitle("Floating Bichos v0.1-alpha");

  fbo.allocate(ofGetHeight()/3,ofGetHeight()/3);
  fbo.begin();
    ofClear(0);
  fbo.end();

  gui.setup();
  gui.add(positionX.set("posX", 100.0, -500.0, 500.0));
  gui.add(positionY.set("posY", 200.0, -500.0, 500.0));
  gui.add(bOffset.set("offset", 50.0, -200.0, 200.0));
  gui.add(bSpeed.set("speed", 0.1, -1.0, 1.0));

  // dir object with the layers that make up the full image
  ofDirectory dir(layerPath);
  dir.allowExt("png");
  dir.listDir();

	layersTotal = dir.size();

	for(int i = 0; i < layersTotal; i++) {
		myLayer[i].setup(dir.getPath(i));
	}

	ofEnableAlphaBlending();
  // ofSetRectMode(OF_RECTMODE_CENTER);

}

//--------------------------------------------------------------
void ofApp::update(){

	areaX[0] = (ofGetWidth() / 2) - (ofGetHeight() / 2);
	areaX[1] = (ofGetWidth() / 2) + (ofGetHeight() / 2);

  // update all layers
	for(int i = 0; i < layersTotal; i++) {
		myLayer[i].update();
	}

  bOffset = bOffset;
  bSpeed = bSpeed;

  // move the bicho
  //sin(ofGetElapsedTimef() * bSpeed + positionX);

  bX = sin(ofGetElapsedTimef() + bSpeed + positionX) * bOffset;
  bY = sin(ofGetElapsedTimef() + bSpeed + positionY) * bOffset;
  //bY = 0;

  //ofMap(sin(time), -1, 1, 0, ofGetWidth())

}

//--------------------------------------------------------------
void ofApp::draw(){

  ofBackground(0);

  ofFill();
	// draw the debugging X
  if(debug) {
	   ofDrawLine(areaX[0], 0, areaX[1], ofGetHeight());
     ofDrawLine(areaX[0], ofGetHeight(), areaX[1], 0);
  }

  // draw to the fbo
  fbo.begin();

    ofClear(0);

    if(debug) {
      ofSetColor(100);
      ofNoFill();
      ofDrawRectangle(1,1,fbo.getWidth()-1,fbo.getHeight()-1);
    }

    ofSetColor(255);

    for(int i = 0; i < layersTotal; i++) {
  	  myLayer[i].draw();
    }

  fbo.end();

  ofPushMatrix();
    ofTranslate(ofGetWidth() / 2 - fbo.getHeight() / 2, ofGetHeight() / 2 - fbo.getHeight() / 2 - safezone);
    ofRotate(0);
    fbo.draw(bX,bY);
  ofPopMatrix();

  ofPushMatrix();
    ofTranslate(ofGetWidth() / 2 + fbo.getHeight() / 2 + safezone, ofGetHeight() / 2 - fbo.getHeight() / 2 );
    ofRotate(90);
    fbo.draw(bX,bY);
  ofPopMatrix();

  ofPushMatrix();
    ofTranslate(ofGetWidth() / 2 + fbo.getHeight() / 2, ofGetHeight() / 2 + fbo.getHeight() / 2 + safezone);
    ofRotate(180);
    fbo.draw(bX,bY);
  ofPopMatrix();

  ofPushMatrix();
    ofTranslate(ofGetWidth() / 2 - fbo.getHeight() / 2 - safezone, ofGetHeight() / 2 + fbo.getHeight() / 2);
    ofRotate(270);
    fbo.draw(bX,bY);
  ofPopMatrix();

  if(debug) {
    gui.draw();
    ofDrawBitmapString("x: " + ofToString(bX), 30, ofGetHeight() - 60);
    ofDrawBitmapString("y: " + ofToString(bY), 30, ofGetHeight() - 30);
  }


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
//  if (key == 'x') { debug = !debug;}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
  if(button == 2) {
    debug = !debug;
  }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
