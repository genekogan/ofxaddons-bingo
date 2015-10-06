#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    fbo.allocate(ofGetWidth(), ofGetHeight());
    glitch.setup(&fbo);
}

//--------------------------------------------------------------
void ofApp::update(){
    fbo.begin();
    ofClear(0, 0);
    ofBackground(255);
    japan.draw(ofGetWidth()/2, ofGetHeight()/2, 180);
    fbo.end();
    
    if (ofRandom(100) < 1)  glitch.toggleFx(OFXPOSTGLITCH_CONVERGENCE);
    if (ofRandom(100) < 1)  glitch.toggleFx(OFXPOSTGLITCH_GLOW);
    if (ofRandom(100) < 1)  glitch.toggleFx(OFXPOSTGLITCH_SHAKER);
    if (ofRandom(100) < 1)  glitch.toggleFx(OFXPOSTGLITCH_CUTSLIDER);
    if (ofRandom(100) < 1)  glitch.toggleFx(OFXPOSTGLITCH_TWIST);
    if (ofRandom(100) < 1)  glitch.toggleFx(OFXPOSTGLITCH_OUTLINE);
    if (ofRandom(100) < 1)  glitch.toggleFx(OFXPOSTGLITCH_NOISE);
    if (ofRandom(100) < 1)  glitch.toggleFx(OFXPOSTGLITCH_SLITSCAN);
    if (ofRandom(100) < 1)  glitch.toggleFx(OFXPOSTGLITCH_SWELL);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    glitch.generateFx();
    fbo.draw(0, 0);
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