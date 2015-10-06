#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"


class BallsGenerator{
public:
    
    BallsGenerator();
    void setup();
    void update(ofVec2f left_eye, ofVec2f right_eye);
    void draw();
    void blow(float blow_power);
    vector<ofVec2f> origins;
    
    ofxBox2d                            box2d;
    vector    <shared_ptr<ofxBox2dCircle> >	circles;
    

};

