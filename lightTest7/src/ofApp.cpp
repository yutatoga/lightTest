#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(ofColor::black);

    // model explanation
    modelExplanationString[0] = "plane model";
    modelExplanationString[1] = "thick model";
    modelExplanationString[2] = "low polygon model";

    // listener
    enableSmoothLighting.addListener(this, &ofApp::enableSmoothLightingChanged);
    
    // gui
    panel.setup("light test", "settings.xml", 0, 0);
    for (int i = 0; i < MODEL_NUMBER; i++) {
        if (i == 0) {
            panel.add(enableDrawSakuraModel[i].set("enableDrawSakuraModel"+ofToString(i), true));
        } else {
            panel.add(enableDrawSakuraModel[i].set("enableDrawSakuraModel"+ofToString(i), false));
        }
        panel.add(modelExplanationLabel[i].setup("  type", modelExplanationString[i]));
        panel.add(spacer.setup("", ""));
    }
    panel.add(enableDrawWireFrame.set("enableDrawWireFrame", false));
    panel.add(specularColor.set("specularColor", ofFloatColor(1.0, 0.0, 0.0), ofFloatColor(0.0, 0.0, 0.0), ofFloatColor(1.0, 1.0, 1.0)));
    panel.add(diffuseColor.set("diffuseColor", ofFloatColor(0.0, 1.0, 0.0), ofFloatColor(0.0, 0.0, 0.0), ofFloatColor(1.0, 1.0, 1.0)));
    panel.add(ambientColor.set("ambientColor", ofFloatColor(0.0, 0.0, 1.0), ofFloatColor(0.0, 0.0, 0.0), ofFloatColor(1.0, 1.0, 1.0)));
    panel.add(enableSmoothLighting.set("enableSmoothLighting", true));
    panel.loadFromFile("settings.xml");
    
    // model
    for (int i = 0; i < MODEL_NUMBER; i++) {
        models[i].loadModel("sakura"+ofToString(i+1)+"/sakura"+ofToString(i+1)+".3ds");
        models[i].setPosition(0, 0, 0);
    }
    
    // camera
    camera.setDistance(1000);
    
    // light
    light.setPointLight();
    light.setPosition(300, 300, 300);
    light.lookAt(ofVec3f(0, 0, 0));
    ofSetSmoothLighting(enableSmoothLighting);
}

void ofApp::enableSmoothLightingChanged(bool &enableSmoothLightingStatus){
    ofSetSmoothLighting(enableSmoothLighting);
}

//--------------------------------------------------------------
void ofApp::update(){
    // model
    for (int i = 0; i < MODEL_NUMBER; i++) {
        models[i].setRotation(0, ofGetFrameNum(), -1, -1, -1);
    }
    
    // light
    light.setSpecularColor(specularColor);
    light.setDiffuseColor(diffuseColor);
    light.setAmbientColor(ambientColor);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableDepthTest();{
        camera.begin();{
            ofEnableLighting();{
                light.enable();{
                    // light
                    light.draw();
                    
                    // model
                    for (int i = 0; i < MODEL_NUMBER; i++) {
                        if (enableDrawSakuraModel[i]) {
                            if (enableDrawWireFrame) {
                                models[i].drawWireframe();
                            }else{
                                models[i].drawFaces();
                            }
                        }
                    }
                }light.disable();
            }ofDisableLighting();
        }camera.end();
    }ofDisableDepthTest();
    
    // gui
    panel.draw();
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
