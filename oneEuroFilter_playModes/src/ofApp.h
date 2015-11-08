#pragma once

#include "ofMain.h"
#include "VideoBuffer.h"
#include "VideoHeader.h"
#include "VideoGrabber.h"
#include "FileGrabber.h"
#include "VideoRenderer.h"
#include "VideoRate.h"
#include "VideoMixerGPU.h"
#include "BasicVideoRenderer.h"
#include "ofxGui.h"
#include "ofxOneEuroFilter.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofxPm::FileGrabber grabber;
    ofxPm::VideoBuffer vBuffer;
    ofxPm::VideoHeader vHeader;
    ofxPm::BasicVideoRenderer vRenderer;
    ofxPm::VideoRate vRate;
    ofxPm::VideoMixerGPU vMixer;
    
    ofxPanel gui;
    ofxIntSlider fps;
    ofxIntSlider delay;
    
    ofxOneEuroFilter filter;
    
    deque<float> rawArray;
    deque<float> filterArray;

};
