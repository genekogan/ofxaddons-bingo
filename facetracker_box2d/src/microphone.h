#pragma once

#include "ofMain.h"

class Microphone {
public:
    Microphone();
    void setup(ofBaseApp *app);
    void update();
    void draw();

    void audioIn(float * input, int bufferSize, int nChannels);
    
    vector <float> left;
    vector <float> right;
    vector <float> volHistory;
    
    int 	bufferCounter;
    int 	drawCounter;
    
    float smoothedVol;
    float scaledVol;
    
    ofSoundStream soundStream;
    
};
