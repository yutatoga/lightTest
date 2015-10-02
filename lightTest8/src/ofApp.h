#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxXmlSettings.h"

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
    
    // gui
    ofxPanel panel;
    // - light
    ofParameter<ofFloatColor> lightSpecularColor;
    ofParameter<ofFloatColor> lightDiffuseColor;
    ofParameter<ofFloatColor> lightAmbientColor;
    // - material
    ofParameter<ofFloatColor> materialSpecularColor;
    ofParameter<ofFloatColor> materialDiffuseColor;
    ofParameter<ofFloatColor> materialAmbientColor;
    ofParameter<ofFloatColor> materialEmissiveColor;
    ofParameter<float> materialShininess;
    // - sphere
    ofParameter<int> sphereRadius;
    ofParameter<int> sphereResolution;
    // - box
    ofParameter<ofVec3f> boxSize;
    ofParameter<int> boxResolution;
    ofParameter<ofColor> boxColor;
    
    // camera
    ofEasyCam camera;
    
    // material
    ofMaterial material;
    
    // sphere
    ofSpherePrimitive sphere;
    
    // box
    // comment out the code to check glEnable(GL_COLOR_MATERIAL) because of bug: every material parameter should be overwritten by ofSetColor(boxColor) on line 98 in ofApp.cpp)
    // ofBoxPrimitive box;
    
    // light
    ofLight light;
};
