#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetVerticalSync(true);
    ofBackground(54, 54, 54);
    ofSetFrameRate(60);
    
    int ticksPerBuffer = 8;
    bufferSize = 1024; //pdBlock-64
    inChan  = 2;
    outChan = 0;
    sampleRate = 44100;
    
    int midiMin = 21;
    int midiMax = 108;
    
    filterBank.setup(bufferSize, midiMin, midiMax, inChan, 1.0, sampleRate, 1.0);
    filterBank.setColor(ofColor::orange);
    
    soundStream.setup(this, outChan, inChan, sampleRate, bufferSize, ticksPerBuffer);	}

//--------------------------------------------------------------
void ofApp::update(){
    float * sme = filterBank.getSmthEnergies();
    for(int n=filterBank.midiMinVar; n<filterBank.midiMaxVar; n++){
        if(sme[n] > filterBank.treshold){
            ofxNotification("You sang a MIDI note "+ofToString(n));
        }
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(225);
    ofNoFill();
    
    float chSz = bufferSize/3;
    // draw the left channel:
    {
        ofPushStyle();
        ofPushMatrix();
        ofTranslate(100, 15, 0);
        ofSetColor(225);
        ofDrawBitmapString("Left Channel", 4, 18);
        ofSetLineWidth(1);
        ofRect(0, 0, chSz, 200);
        ofSetColor(ofColor::orange);
        ofSetLineWidth(3);
        ofBeginShape();
        for (int i = 0; i < bufferSize; i++){
            ofVertex(i/(bufferSize/chSz), 100 - filterBank.getLeftBuffer()[i]*45);
        }
        ofEndShape(false);
        ofPopMatrix();
        ofPopStyle();
    }
    // draw the right channel:
    {
        ofPushStyle();
        ofPushMatrix();
        ofTranslate(200+chSz, 15, 0);
        ofSetColor(225);
        ofDrawBitmapString("Right Channel", 4, 18);
        ofSetLineWidth(1);
        ofRect(0, 0, chSz, 200);
        ofSetColor(ofColor::orange);
        ofSetLineWidth(3);
        ofBeginShape();
        for (int i = 0; i < bufferSize; i++){
            ofVertex(i/(bufferSize/chSz), 100 - filterBank.getRightBuffer()[i]*45);
        }
        ofEndShape(false);
        ofPopMatrix();
        ofPopStyle();
    }
    
    ///Draw FilterBank
    {
        ofPushStyle();
        ofPushMatrix();
        ofTranslate (100,250,0);
        //*
        filterBank.draw(800,400);
        //*
        ofPopMatrix();
        ofPopStyle();
    }
    ofSetColor(225);
    
    string reportString =  "Sampling Rate: "+ ofToString(44100) +"\nBuffer size: "+ ofToString(bufferSize);
    ofDrawBitmapString(reportString, 10, 700);
}

//--------------------------------------------------------------
void ofApp::audioIn(float * input, int bufferSize, int nChannels){
    filterBank.analyze(input);
}

//--------------------------------------------------------------
void ofApp::audioOut(float * output, int bufferSize, int nChannels){
    
}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){
    switch (key){
        case 'q':
            filterBank.showAll = !filterBank.showAll;
            break;
        default:
            break;
    }
}


//--------------------------------------------------------------
void ofApp::exit(){
    printf("------- CLOSING...\n");
    soundStream.stop();
    soundStream.close();
    filterBank.exit();
    cout<<"CLOSED SUCCESSFULLY!"<<endl;
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

