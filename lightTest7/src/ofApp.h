#pragma once

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
#include "ofxGui.h"

#define MODEL_NUMBER 3

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

    void enableSmoothLightingChanged(bool &enableSmoothLightingStatus);
    
    // gui
    ofxPanel panel;
    ofParameter<bool> enableDrawSakuraModel[MODEL_NUMBER];
    ofParameter<bool> enableDrawWireFrame;
    ofxLabel modelExplanationLabel[MODEL_NUMBER];
    ofxLabel spacer;
    string modelExplanationString[MODEL_NUMBER];
    ofParameter<ofFloatColor> specularColor;
    ofParameter<ofFloatColor> diffuseColor;
    ofParameter<ofFloatColor> ambientColor;
    ofParameter<bool> enableSmoothLighting;
    
    // model
    ofxAssimpModelLoader models[MODEL_NUMBER];
    
    // camera
    ofEasyCam camera;
    
    // light
    ofLight light;
};
