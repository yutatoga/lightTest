#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    ofEasyCam camera;
    ofLight lightPoint;
    ofLight lightSpot;
    ofLight lightDirectional;
    
    ofMaterial material;
    
    ofBoxPrimitive box;
    ofSpherePrimitive sphere;
    
    ofxPanel panel;
    ofParameter<ofVec3f> lightOrientation;
    ofParameter<bool> enableDrawBox;
    ofParameter<bool> enableDrawSphere;
    ofParameter<bool> enableLightPoint;
    ofParameter<bool> enableLightSpot;
    ofParameter<bool> enableLightDirectional;
};
