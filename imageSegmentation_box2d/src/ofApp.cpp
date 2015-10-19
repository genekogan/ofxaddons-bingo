#include "ofApp.h"

//--------------------------------------------------------------
static bool shouldRemove(shared_ptr<ofxBox2dBaseShape>shape) {
    return !ofRectangle(0, -400, ofGetWidth(), ofGetHeight()+400).inside(shape->getPosition());
}

//--------------------------------------------------------------
void TexturedBox2dPolygon::draw() {
    ofPushMatrix();
    ofTranslate(polygon->getPosition());
    ofRotate(polygon->getRotation());
    ofSetColor(255);
    image.draw(ctr.x - image.width/2, ctr.y - image.height/2);
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetVerticalSync(true);
    ofSetWindowShape(640, 640);
    //ofSetFullscreen(true);
    
    // Box2d
    box2d.init();
    box2d.setGravity(0, 10);
    box2d.createGround();
    box2d.setFPS(30.0);
    box2d.createBounds(ofRectangle(0, 0, ofGetWidth(), ofGetHeight()));
 
    // mask
    ofShader shader;
    ofFbo mask;
    ofFbo final;
    ofPixels pixels;
    
    // load the image to break
    image.loadImage("Geo-Map--USA.jpg");

    // segment the image
    segmentation.sigma = 1.0;
    segmentation.k = 300;
    segmentation.min = 2000;
    segmentation.segment(image);
    segmentedImage.setFromPixels(segmentation.getSegmentedPixels());
    segmentedImage.update();

    // grab the contours of the individual segments
    contourFinder.setMinArea(1000);
    contourFinder.setMaxArea(image.width * image.height);

    // for each segment found, create a TexturedBox2dPolygon
    for (int c = 0; c < segmentation.numSegments; c++)
    {
        contourFinder.findContours(segmentation.getSegmentMask(c));
        if (contourFinder.getBoundingRect(0).width * contourFinder.getBoundingRect(0).height > image.getWidth()*image.getHeight()*0.15) {
            continue;
        }
        
        // get contour points
        ofPolyline points;
        for (auto p : contourFinder.getContour(0)) {
            points.addVertex(toOf(p));
        }
        //points.simplify(2);   // this seems to cause box2d to crash sometimes

        // get bounding box
        cv::Rect box = contourFinder.getBoundingRect(0);
        ofImage segmentImage;
        segmentImage.setFromPixels(image);
        segmentImage.crop(box.x, box.y, box.width, box.height);
        
        mask.allocate(box.width, box.height);
        final.allocate(box.width, box.height);
        shader.load("standard.vert", "alphamask.frag");
        
        // make mask from contour points
        mask.begin();
        ofClear(0,0);
        ofSetColor(255);
        ofBeginShape();
        vector<ofPoint> & vertices = points.getVertices();
        for (int i=0; i<vertices.size(); i++) {
            ofVertex(vertices[i].x - box.x, vertices[i].y - box.y);
        }
        ofEndShape();
        mask.end();
        
        // make final masked texture and read into pixels
        final.begin();
        ofClear(0, 0);
        shader.begin();
        shader.setUniformTexture("maskTex", mask.getTextureReference(), 1);
        segmentImage.draw(0,0);
        shader.end();
        final.end();
        final.readToPixels(pixels);

        // create box2d polygon
        shared_ptr<ofxBox2dPolygon> polygon = shared_ptr<ofxBox2dPolygon>(new ofxBox2dPolygon);
        polygon->addVertices(points.getVertices());
        polygon->setPhysics(1.0, 0.1, 0.3);
        //polygon->triangulatePoly();
        polygon->simplify();
        //polygon->setVelocity(ofRandom(-10,10), ofRandom(-10, 10));
        polygon->create(box2d.getWorld());

        // get vector from center of image bounding box to position of box2d polygon
        ofVec2f pos = polygon->getPosition();
        ofVec2f ctr = ofVec2f(box.x + box.width/2 - pos.x, box.y + box.height/2 - pos.y);
        
        // finally create the TexturedBox2dPolygon
        TexturedBox2dPolygon tp;
        tp.image.setFromPixels(pixels);
        tp.polygon = polygon;
        tp.ctr = ctr;
        
        shapes.push_back(tp);
    }
}

//--------------------------------------------------------------
void ofApp::update() {
    if (ofGetFrameNum() < 120) {return;}

    box2d.update();
}

//--------------------------------------------------------------
void ofApp::draw() {
    ofBackground(ofColor::darkBlue);
    ofSetColor(255);
    for (auto tp : shapes) {
        tp.draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ) {
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {
}

