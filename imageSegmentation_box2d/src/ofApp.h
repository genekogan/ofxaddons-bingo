#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "ofxImageSegmentation.h"
#include "ofxBox2d.h"


using namespace ofxCv;
using namespace cv;


struct TexturedBox2dPolygon {
    shared_ptr<ofxBox2dPolygon> polygon;
    ofImage image;
    ofVec2f ctr;
    void draw();
};


class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);

    ofImage image;
    ofxImageSegmentation segmentation;
    ofxCv::ContourFinder contourFinder;
    ofImage segmentedImage;

    ofxBox2d box2d;
    vector<TexturedBox2dPolygon> shapes;
};
