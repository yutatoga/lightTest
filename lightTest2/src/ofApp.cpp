#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableAlphaBlending();
    ofEnableSmoothing();
    //    ofSetGlobalAmbientColor(ofColor(0, 0, 0));
    ofSetSmoothLighting(true);
    
    ofBackgroundHex(0x000000);
    glEnable(GL_DEPTH_TEST);
    ofSetSphereResolution(100);
    ofSetBoxResolution(100);
    
    camera.setDistance(600);
    
    ofLogNotice("initial light type: "+ofToString(light.getType()));
    
    // set light type
    light.setSpotlight();
    light.setPosition(0, 0, 0);
    
    light.setSpotConcentration(10); // gradation of spot light which is between  0 ~ 128
    light.setSpotlightCutOff(60); // cone angle of spot light which is between 0 ~ 90 (degree)
    
    // color of light for each light type
    light.setSpecularColor(ofFloatColor(0.0, 0.0, 1.0));
    light.setDiffuseColor(ofFloatColor(1.0, 0, 0));
    light.setAmbientColor(ofFloatColor(0, 0.2, 0));
    
    // color of material for each material type
    material.setShininess(64); // shininess is a value between 0 - 128, 128 being the most shiny //
    material.setSpecularColor(ofFloatColor(1.0, 1.0, 1.0));
    material.setDiffuseColor(ofFloatColor(1.0, 1.0, 1.0));
    material.setAmbientColor(ofFloatColor(1.0, 1.0, 1.0));
}

//--------------------------------------------------------------
void ofApp::update(){
    setLightOri(light, ofVec3f(0, ofGetFrameNum(), 0));
}

//--------------------------------------------------------------
void ofApp::draw(){
    glEnable(GL_CULL_FACE);{//enable culling
        // glCullFace(GL_FRONT);//culling front which means draw only back face
        glCullFace(GL_BACK);//culling back face which means draw only front face
        camera.begin();{
            light.enable();{
                material.begin();{
                    light.draw();
                    ofSetHexColor(0xffffff);
                    glFrontFace(GL_CCW); // for box
                    ofDrawBox(-200, 0, 0, 200);
                    glFrontFace(GL_CW); // for sphere (different from box!)
                    ofDrawSphere(200, 0, 0, 100);
                }material.end();
            }light.disable();
        }camera.end();
    }glDisable(GL_CULL_FACE); // disable culling
}

void ofApp::setLightOri(ofLight &light, ofVec3f rot){
    ofVec3f xax(1, 0, 0);
    ofVec3f yax(0, 1, 0);
    ofVec3f zax(0, 0, 1);
    ofQuaternion q;
    q.makeRotate(rot.x, xax, rot.y, yax, rot.z, zax);
    light.setOrientation(q);
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
