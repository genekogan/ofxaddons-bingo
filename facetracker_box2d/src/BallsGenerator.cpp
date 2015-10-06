#include "BallsGenerator.h"

BallsGenerator::BallsGenerator(){
    
}

void BallsGenerator::setup(){
    ofVec2f left_eye = ofVec2f(300, 400);
    ofVec2f right_eye = ofVec2f(600, 400);
    origins.push_back(left_eye);
    origins.push_back(right_eye);
    
    box2d.init();
    box2d.setGravity(0, 8);
    box2d.createBounds();
    box2d.setFPS(60.0);
    box2d.registerGrabbing();
}

void BallsGenerator::update(ofVec2f left_eye, ofVec2f right_eye){
    origins[0] = left_eye;
    origins[1] = right_eye;
    box2d.update();
}

void BallsGenerator::draw(){
    int colors[] = {0xcae72b, 0xe63b8f, 0x2bb0e7};
    for(int i=0; i<circles.size(); i++) {
        ofFill();
        ofSetHexColor(colors[(int)ofRandom(0, 3)]);
        circles[i].get()->draw();
    }
    box2d.drawGround();
}

void BallsGenerator::blow(float blow_power){
    float freq = 3.0;
    float time = ofGetElapsedTimef() * 0.02;
    float noiseValue = ofSignedNoise(time*freq*blow_power);
    float mapped = ofMap(noiseValue, 0, 1, 0, 15);
    int n_balls = int(mapped + 0.5);
    
    for (int i =1; i <= n_balls; i ++) {
        float r = ofRandom(4, 20);
        vector<ofVec2f>::iterator origin;
        for (origin = origins.begin(); origin != origins.end(); origin++) {
            circles.push_back(shared_ptr<ofxBox2dCircle>(new ofxBox2dCircle));
            circles.back().get()->setPhysics(3.0, 0.53, 0.1);
            circles.back().get()->setup(box2d.getWorld(), origin->x, origin->y, ofRandom(5, 25));
            circles.back().get()->setVelocity(ofRandom(-30, 30), -40);
        }
    }
}
