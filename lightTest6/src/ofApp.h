#pragma once

#include "ofMain.h"
#include "ofxGui.h"

#define INITIAL_SPHERE_NUMBER_X 10
#define INITIAL_SPHERE_NUMBER_Y 10
#define INITIAL_SPHERE_NUMBER_Z 10

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    void setLightOri(ofLight &light, ofVec3f rot);
    
    ofEasyCam camera;
    ofLight light;
    ofMaterial material;
    vector<ofSpherePrimitive> spheres;
    
    ofxPanel panel;
    ofParameter<ofFloatColor> specularColor;
    ofParameter<ofFloatColor> diffuseColor;
    ofParameter<ofFloatColor> ambientColor;
    ofParameter<int> sphereResolution;
    ofParameter<float> sphereRadius;
    ofParameter<bool> enableDrawWireFrame;
    ofParameter<ofVec3f> attenuation;
};
