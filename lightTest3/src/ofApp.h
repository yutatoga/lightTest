#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    ofEasyCam camera;
    ofLight light;
    
    ofBoxPrimitive box;
    ofSpherePrimitive sphere;

    ofxPanel panel;
    ofParameter<ofVec3f> lightOrientation;
    ofParameter<bool> enableMouseInput;
    ofParameter<bool> enableDrawBox;
    ofParameter<bool> enableDrawSphere;
};
