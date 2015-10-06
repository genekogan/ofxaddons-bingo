#include "ofApp.h"
//--------------------------------------------------------------
using namespace ofxCv;
using namespace cv;

void ofApp::setup() {
    debug = false;
    ofSetVerticalSync(true);
    //cam.initGrabber(640, 480);
    cam.initGrabber(1200, 750);
    tracker.setup();
    tracker.setRescale(.5);
    microphone.setup(this);
    generator.setup();
}

void ofApp::update() {
    cam.update();
    if(cam.isFrameNew()) {
        tracker.update(toCv(cam));
    }
    leftEye = tracker.getImageFeature(ofxFaceTracker::LEFT_EYE).getCentroid2D();
    rightEye = tracker.getImageFeature(ofxFaceTracker::RIGHT_EYE).getCentroid2D();
    microphone.update();
    generator.update(leftEye, rightEye);
    generator.blow(microphone.scaledVol);
}

void ofApp::draw() {
    mouthImage = grabMouth();
    
    cam.draw(0, 0);
    drawMouth(leftEye, mouthImage);
    drawMouth(rightEye, mouthImage);
    generator.draw();
    ofSetColor(225);
    printDebug();
}

void ofApp::drawMouth(ofVec2f eye, ofImage mouth){
    mouth.draw(eye.x -mouth.width/2, eye.y - mouth.height/2);
}

ofImage ofApp::grabMouth(){
    ofPolyline mouthProfile = tracker.getImageFeature(ofxFaceTracker::OUTER_MOUTH);
    mouthProfile.getSmoothed(100);
    ofPixels pixels;
    cam.getTextureReference().readToPixels(pixels);
    ofRectangle mouthBox = mouthProfile.getBoundingBox();
    pixels.crop(mouthBox.x,mouthBox.y,mouthBox.width,mouthBox.height);
    
    ofPixels alphaPixels;
    alphaPixels.allocate(pixels.getWidth(), pixels.getHeight(), OF_IMAGE_COLOR_ALPHA);
    int totalPixels = pixels.getWidth()*pixels.getHeight();
    for (int x = 0; x < pixels.getWidth(); x++){
        for (int y = 0; y < pixels.getHeight(); y++){
            ofPoint checkpoint = ofPoint(x+mouthBox.x,y+mouthBox.y);
            if(mouthProfile.inside(checkpoint)){
                ofColor c = pixels.getColor(x,y);
                alphaPixels.setColor(x,y,c);
            } else {
                ofColor transparent = ofColor(0,0,0,0);
                alphaPixels.setColor(x,y,transparent);
            }
        }
    }
    ofImage videoImage;
    videoImage.setFromPixels(alphaPixels);
    return videoImage;
}

void ofApp::audioIn(float * input, int bufferSize, int nChannels){
    microphone.audioIn(input, bufferSize, nChannels);
}

void ofApp::printDebug(){
    if (debug){
        ofSetLineWidth(2);
        tracker.draw();
        microphone.draw();
    };
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
