#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(5, 5);
    vector<vector<float> > vals(4, vector<float>(4, 0.25));
    ofxMC::Matrix mat(vals);
    mc.setup(mat, 0);
    mouse.set(ofGetScreenWidth()/2, ofGetScreenHeight()/2);
}

//--------------------------------------------------------------
void ofApp::update(){
    mc.update();
    int s = mc.getState();
    if      (s == 0) mouse.y += 5;
    else if (s == 1) mouse.x += 5;
    else if (s == 2) mouse.y -= 5;
    else if (s == 3) mouse.x -= 5;

    ofxMacMouseMove(OFX_MAC_MOUSE_BUTTON_LEFT, mouse.x+150, mouse.y-50);
}

//--------------------------------------------------------------
void ofApp::draw(){
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
