#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	// define (search) the layers that make up the image
	ofDirectory dir(layerPath);
	dir.allowExt("png");
	dir.listDir();

	layersTotal = dir.size();
	
	for(int i = 0; i < layersTotal; i++) {
		myLayer[i].setup(dir.getPath(i));
	}

	ofEnableAlphaBlending();

}

//--------------------------------------------------------------
void ofApp::update(){

	ofBackground(0);

	for(int i = 0; i < layersTotal; i++) {
		myLayer[i].update(mouseX, mouseY);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	ofSetColor(255);

	for(int i = 0; i < layersTotal; i++) {
		myLayer[i].draw();
	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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