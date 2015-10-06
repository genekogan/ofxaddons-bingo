#include "microphone.h"

Microphone::Microphone(){

    
};

void Microphone::setup(ofBaseApp *the_app){
    ofSetCircleResolution(80);
    ofBackground(54, 54, 54);
    soundStream.listDevices();
    
    int bufferSize = 256;
    left.assign(bufferSize, 0.0);
    right.assign(bufferSize, 0.0);
    
    bufferCounter	= 0;
    drawCounter		= 0;
    smoothedVol     = 0.0;
    scaledVol		= 0.0;
    soundStream.setup(the_app, 0, 2, 44100, bufferSize, 4);
};

void Microphone::update(){
    scaledVol = ofMap(smoothedVol, 0.0, 0.17, 0.0, 1.0, true);
};

void Microphone::draw(){
        ofDrawBitmapString(ofToString((int) ofGetFrameRate()), 10, 20);
        // draw the average volume:
        ofPushStyle();
        ofPushMatrix();
            ofTranslate(565, 170, 0);
            ofSetColor(225);
            ofDrawBitmapString("Scaled average vol (0-100): " + ofToString(scaledVol * 100.0, 0), 4, 18);
            //ofRect(0, 0, 400, 400);
    
            ofSetColor(245, 58, 135);
            ofFill();
            ofCircle(200, 200, scaledVol * 190.0f);
        ofPopMatrix();
        ofPopStyle();
        drawCounter++;
    
        ofSetColor(225);
        string reportString = "buffers received: "+ofToString(bufferCounter)+"\ndraw routines called: "+ofToString(drawCounter)+"\nticks: " + ofToString(soundStream.getTickCount());
        ofDrawBitmapString(reportString, 32, 589);
};

void Microphone::audioIn(float * input, int bufferSize, int nChannels){
    float curVol = 0.0;
    // samples are "interleaved"
    int numCounted = 0;

    for (int i = 0; i < bufferSize; i++){
        left[i]		= input[i*2]*0.5;
        right[i]	= input[i*2+1]*0.5;
        
        curVol += left[i] * left[i];
        curVol += right[i] * right[i];
        numCounted+=2;
    }
    
    curVol /= (float)numCounted;
    curVol = sqrt( curVol );
    
    smoothedVol *= 0.93;
    smoothedVol += 0.07 * curVol;
    
    bufferCounter++;
    
};
