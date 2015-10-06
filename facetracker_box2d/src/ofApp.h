#pragma once

#include "ofMain.h"

#include "ofxFaceTracker.h"
#include "microphone.h"
#include "BallsGenerator.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void printDebug();
    void drawMouth(ofVec2f eye, ofImage mouth);
    ofImage grabMouth();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofVideoGrabber cam;
    ofxFaceTracker tracker;
    
    ofVec2f leftEye;
    ofVec2f rightEye;
    ofVec2f mouthPosition;
    ofImage mouthImage;
    Boolean debug;
    
    void audioIn(float * input, int bufferSize, int nChannels);
    ofSoundStream soundStream;
    Microphone microphone;
    BallsGenerator generator;
};
