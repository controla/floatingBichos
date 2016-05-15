#include "ofApp.h"

/* TODO:

  - Create Bicho class
  - behaviours (class? functions?)
  - Learn animation techniques (OFBOOK)

*/

//--------------------------------------------------------------
void ofApp::setup(){

  // used for sorting through Z
  // glEnable(GL_DEPTH);

  ofSetWindowTitle("Floating Bichos v0.1-alpha");

  // parameters gui
  gui.setup();
  gui.add(positionX.set("posX", 100.0, -500.0, 500.0));
  gui.add(positionY.set("posY", 200.0, -500.0, 500.0));
  gui.add(bOffset.set("offset", 50.0, -200.0, 200.0));
  gui.add(bSpeed.set("speed", 0.1, -1.0, 1.0));

  // create an fbo for display of bicho
  fbo.allocate(ofGetHeight()/3,ofGetHeight()/3);
  fbo.begin();
    ofClear(0);
  fbo.end();

  // search for all 'bichos' (subfolders inside bichos folder)
  ofDirectory bichosDir(bichosBasePath);
  bichosDir.listDir();
  bichosDir.sort();
  bichosTotal = bichosDir.size();

  // setup found bichos (load its layers)
  for(int thisBicho = 0; thisBicho < bichosTotal; thisBicho++) {
    myBicho[thisBicho].setup(bichosDir.getPath(thisBicho));
  }

  // init bicho 0
  bichoActive = 0;

  // popit:
	ofEnableAlphaBlending();
  // ofSetRectMode(OF_RECTMODE_CENTER);

}

//--------------------------------------------------------------
void ofApp::update(){

	myBicho[bichoActive].update(bSpeed,positionX,positionY,bOffset);

  // update all bichos
	for(int i = 0; i < bichosTotal; i++) {
		myBicho[i].update(bSpeed,positionX,positionY,bOffset);
	}

  if(myBicho[bichoActive].bichoOpacity <= 0) {
    myBicho[bichoActive].isAlive = false;
  }

  // bicho is dead
  if(!myBicho[bichoActive].isAlive) {
    // clean up
    myBicho[bichoActive].isFading = false;

    // call the next guy
    bichoActive = bichoNext;
    myBicho[bichoActive].isAlive = true;
    myBicho[bichoActive].bichoOpacity = 255;

  }
}

//--------------------------------------------------------------
void ofApp::draw(){

  ofBackground(0);

  // ofFill();

	// draw the debugging X
  if(debug) {
  	areaX[0] = (ofGetWidth() / 2) - (ofGetHeight() / 2);
  	areaX[1] = (ofGetWidth() / 2) + (ofGetHeight() / 2);

	  ofDrawLine(areaX[0], 0, areaX[1], ofGetHeight());
    ofDrawLine(areaX[0], ofGetHeight(), areaX[1], 0);
  }

  // draw to the fbo
  fbo.begin();

    ofClear(0);
    ofSetColor(255); // need this?

  	myBicho[bichoActive].draw();

    // add a frame around the fbo to check boundries
    if(debug) {
      ofSetColor(100);
      ofNoFill();
      ofDrawRectangle(1,1,fbo.getWidth()-1,fbo.getHeight()-1);
    }

  fbo.end();

  ofPushMatrix();
    ofTranslate(ofGetWidth() / 2 - fbo.getHeight() / 2, ofGetHeight() / 2 - fbo.getHeight() / 2 - safezone);
    ofRotate(0);
    fbo.draw(myBicho[bichoActive].bichoX,myBicho[bichoActive].bichoY);
  ofPopMatrix();

  ofPushMatrix();
    ofTranslate(ofGetWidth() / 2 + fbo.getHeight() / 2 + safezone, ofGetHeight() / 2 - fbo.getHeight() / 2 );
    ofRotate(90);
    fbo.draw(myBicho[bichoActive].bichoX,myBicho[bichoActive].bichoY);
  ofPopMatrix();

  ofPushMatrix();
    ofTranslate(ofGetWidth() / 2 + fbo.getHeight() / 2, ofGetHeight() / 2 + fbo.getHeight() / 2 + safezone);
    ofRotate(180);
    fbo.draw(myBicho[bichoActive].bichoX,myBicho[bichoActive].bichoY);
  ofPopMatrix();

  ofPushMatrix();
    ofTranslate(ofGetWidth() / 2 - fbo.getHeight() / 2 - safezone, ofGetHeight() / 2 + fbo.getHeight() / 2);
    ofRotate(270);
    fbo.draw(myBicho[bichoActive].bichoX,myBicho[bichoActive].bichoY);
  ofPopMatrix();

  if(debug) {
    gui.draw();
    ofDrawBitmapString("bicho: " + ofToString(bichoActive), 30, ofGetHeight() - 90);
    ofDrawBitmapString("x: " + ofToString(myBicho[bichoActive].bichoX), 30, ofGetHeight() - 60);
    ofDrawBitmapString("y: " + ofToString(myBicho[bichoActive].bichoY), 30, ofGetHeight() - 30);
  }

}

void ofApp::summon(int _bichoNew) {
  myBicho[bichoActive].remove();
  bichoNext = _bichoNew;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  if (key == '0') { summon(0);}
  if (key == '1') { summon(1);}
  if (key == '2') { summon(2);}
  if (key == '3') { summon(3);}
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
