#include "ofMain.h"
#include "ofxCcv.h"
#include "ofxThreadedImageLoader.h"
#include "ofxInstagram.h"

class ofApp : public ofBaseApp {
public:
    ofVideoGrabber cam;
    
    ofxCcv ccv;
    vector<ofxCcv::Classification> results;
    
    ofxInstagram instagram;
    ofxThreadedImageLoader getImages;
    deque<ofImage> images;
    
    ofVec2f scrollAmount, clickOrigin, releasePos;
    int scrollValue;
    
    
    void setup() {
        // replace MY_AUTH_TOKEN with your instagram token
        string auth_token = "MY_AUTH_TOKEN";
        
        ccv.setup("image-net-2012.sqlite3");
        cam.initGrabber(640, 480);
        instagram.setup(auth_token,"self");
        instagram.setCertFileLocation(ofToDataPath("ca-bundle.crt",false));
        scrollValue = 0;
    }
    
    void update() {
        cam.update();
        if(cam.isFrameNew()) {
            if(ofGetKeyPressed()) {

                // get libccv classification
                results = ccv.classify(cam);
                if (results.size() == 0)    return;
                string searchword = results[0].imageNetName;
                vector<string> words = ofSplitString(searchword, ",");
                if (words.size() == 0) return;
                searchword = words[0];
                ofStringReplace(searchword, " ", "");
                
                // search instagram for first word
                instagram.getListOfTaggedObjectsNormal(searchword, 20);
                images.clear();
                images.resize(20);
                if(!instagram.getBasicData().empty()) {
                    for(int i = 0; i < instagram.getBasicData().size(); i++) {
                        getImages.loadFromURL(images[i], instagram.getBasicData()[i].imageURL);
                    }
                }
            }
        }
    }

    void draw() {
        // draw camera
        cam.draw(0, 0);
        
        // draw libccv results
        ofPushStyle();
        ofTranslate(5, 5);
        ofSetColor(0, 180);
        ofRect(0, -10, 310, 90);
        for (int i = 0; i < results.size(); i++) {
            ofSetColor(ofColor::white);
            ofFill();
            ofRect(0, 0, 100, 10);
            ofSetColor(ofColor::black);
            ofRect(1, 1, (100-2) * results[i].confidence, 10-2);
            ofSetColor(ofColor::white);
            ofDrawBitmapString(results[i].imageNetName, 105, 10);
            ofTranslate(0, 15);
        }
        ofPopStyle();
        
        // draw instagram search results
        ofPushMatrix();
        ofTranslate(440, -1060);
        ofTranslate(0,scrollValue);
        if (!images.empty()) {
            for (int i = 0; i < images.size(); i++) {
                if (images[i].isAllocated()) {
                    images[i].draw(10, 10+(i*160), 150,150);
                    ofDrawBitmapString("Username: "+instagram.getBasicData()[i].user, 170,20+(i*160));
                    ofDrawBitmapString("Created At: "+instagram.getBasicData()[i].created_at, 170,35+(i*160));
                    ofDrawBitmapString("Image Url: "+instagram.getBasicData()[i].imageURL, 170,50+(i*160));
                    ofDrawBitmapString("Image ID: "+instagram.getBasicData()[i].imageID, 170,65+(i*160));
                    ofDrawBitmapString("Caption: "+instagram.getBasicData()[i].caption, 170, 80+(i*160));
                }
            }
        }
        ofPopMatrix();
    }
    
    void mousePressed(int x, int y, int button) {
        clickOrigin = ofVec2f(x,y);
    }
    
    void mouseReleased(int x, int y, int button) {
        releasePos = ofVec2f(x,y);
        scrollAmount = clickOrigin - releasePos;
        scrollValue += scrollAmount.y;
    }
};

int main() {
    ofSetupOpenGL(1280, 800, OF_WINDOW);
    ofRunApp(new ofApp());
}