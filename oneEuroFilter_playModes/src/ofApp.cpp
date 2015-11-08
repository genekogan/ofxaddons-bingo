#include "ofApp.h"
using namespace ofxPm;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(480, 480);
    gui.setup();
    gui.add(fps.setup("fps",30,1,60));
    gui.add(delay.setup("delay",1000,0,2000));
    
    grabber.loadMovie("edgertronic2.mp4");
    grabber.setLoopState(OF_LOOP_NORMAL);
    grabber.play();
    
    vHeader.setup(vBuffer);
    vMixer.setup(grabber,vHeader);
    vRate.setup(vMixer,fps);
    vBuffer.setup(vRate,400,false);
    vHeader.setDelayMs(1000);
    vRenderer.setup(vMixer);
    
    ofEnableAlphaBlending();
    ofSetVerticalSync(true);
    ofBackground(0);    
    
    double frequency = 60; // Hz
    double mincutoff = 1.0 ; // FIXME
    double beta = 1.0 ;      // FIXME
    double dcutoff = 1.0 ;   // this one should be ok
    filter.setup(frequency, mincutoff, beta, dcutoff);
    rawArray.assign(ofGetWidth(), 0.0);
    filterArray.assign(ofGetWidth(), 0.0);
}

//--------------------------------------------------------------
void ofApp::update(){
    // update oneEuroFilter
    float v = (float)mouseY / (float)ofGetHeight();
    float fv = filter.filter(v, ofGetElapsedTimef());
    rawArray.pop_front();
    rawArray.push_back(v);
    filterArray.pop_front();
    filterArray.push_back(fv);
    
    // update delay from oneEuroFilter
    delay = 2000 * filterArray[filterArray.size()-1];

    // update playmodes
    grabber.update();
    vRate.setFps(fps);
    vHeader.setFps(fps);
    vHeader.setDelayMs(delay);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
//    vBuffer.draw();
    vRenderer.draw();
    ofPushMatrix();
    ofTranslate(0, -300);   // just because the header gets drawn too low
    vHeader.draw();
    ofPopMatrix();
    gui.draw();
    
    ofPushStyle();
    ofPushMatrix();
    
    ofNoFill();
    ofSetLineWidth(2);
    
    // draw raw
    ofSetColor(245, 58, 135);
    ofBeginShape();
    for (unsigned int i = 0; i < rawArray.size(); i++){
        float x =  ofMap(i, 0, rawArray.size(), 0, ofGetWidth(), true);
        ofVertex(x, rawArray[i] * ofGetHeight() );
    }
    ofEndShape(false);
    
    // draw filtered
    ofSetColor(58, 245, 135);
    ofBeginShape();
    for (unsigned int i = 0; i < filterArray.size(); i++){
        float x =  ofMap(i, 0, filterArray.size(), 0, ofGetWidth(), true);
        ofVertex(x, filterArray[i] * ofGetHeight() );
    }
    ofEndShape(false);
    
    ofPopStyle();
    ofPopMatrix();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key==' '){
        if(vBuffer.isStopped()){
            vBuffer.resume();
        }else{
            vBuffer.stop();
        }
    }
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
