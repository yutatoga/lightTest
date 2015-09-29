#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    panel.setup("light test", "settings.xml", 0, 0);
    panel.add(specularColor.set("specularColor", ofFloatColor(0.5, 0.5, 0.5), ofFloatColor(0.0, 0.0, 0.0), ofFloatColor(1.0, 1.0, 1.0)));
    panel.add(diffuseColor.set("diffuseColor", ofFloatColor(0.5, 0.5, 0.5), ofFloatColor(0.0, 0.0, 0.0), ofFloatColor(1.0, 1.0, 1.0)));
    panel.add(ambientColor.set("ambientColor", ofFloatColor(0.5, 0.5, 0.5), ofFloatColor(0.0, 0.0, 0.0), ofFloatColor(1.0, 1.0, 1.0)));
    panel.add(sphereResolution.set("sphereResolution", 10, 2, 100));
    panel.add(sphereRadius.set("sphereRadius", 100, 1, 300));
    panel.add(enableDrawWireFrame.set("enableDrawWireFrame", false));
    panel.loadFromFile("settings.xml");
    
    ofEnableAlphaBlending();
    ofEnableSmoothing();
    //    ofSetGlobalAmbientColor(ofColor(0, 0, 0));
    ofSetSmoothLighting(true);
    
    ofBackgroundHex(0x000000);
    ofSetSphereResolution(100);
    ofSetBoxResolution(100);
    
    camera.setDistance(600);
    
    ofLogNotice("initial light type: "+ofToString(light.getType()));
    
    // set light type
    light.setPointLight();
    light.setPosition(0, 0, 0);
    
    // for spot light
//    setLightOri(light, ofVec3f(0, 90, 0));
//    light.setSpotConcentration(0); // gradation of spot light which is between  0 ~ 128
//    light.setSpotlightCutOff(30); // cone angle of spot light which is between 0 ~ 90 (degree)
    
    // color of light for each light type
    light.setDiffuseColor(diffuseColor);
    light.setSpecularColor(specularColor);
    light.setAmbientColor(ambientColor);
    
    // color of material for each material type
    material.setShininess(128); // shininess is a value between 0 - 128, 128 being the most shiny //
    material.setSpecularColor(ofFloatColor(1.0, 1.0, 1.0));
    material.setDiffuseColor(ofFloatColor(1.0, 1.0, 1.0));
    material.setAmbientColor(ofFloatColor(1.0, 1.0, 1.0));
    
    // sphere
    sphere.set(sphereRadius, sphereResolution);
    sphere.setPosition(-200, 0, 0);
}

//--------------------------------------------------------------
void ofApp::update(){
    // update light
    light.setDiffuseColor(diffuseColor);
    light.setSpecularColor(specularColor);
    light.setAmbientColor(ambientColor);
    
    // update sphere
    sphere.set(sphereRadius, sphereResolution);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableDepthTest();{
        camera.begin();{
            ofEnableLighting();{
                light.enable();{
                    material.begin();{
                        light.draw();
                        ofSetHexColor(0xffffff);
                        if (enableDrawWireFrame) {
                            sphere.drawWireframe();
                        } else{
                            sphere.draw();
                        }
                    }material.end();
                }light.disable();
            }ofDisableLighting();
        }camera.end();
    }ofDisableDepthTest();

    // gui
    panel.draw();
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
    ofShowCursor();
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
