#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    // comment out the code to check glEnable(GL_COLOR_MATERIAL) because of bug: every material parameter should be overwritten by ofSetColor(boxColor) on line 98 in ofApp.cpp)
    // ofSetFullscreen(true);
    
    // gui
    panel.setup("light test", "settings.xml", 0, 0);
    // - light
    panel.add(lightSpecularColor.set("lightSpecularColor", ofFloatColor(1.0f, 0.0f, 0.0f), ofFloatColor(0.0f, 0.0f, 0.0f), ofFloatColor(1.0f, 1.0f, 1.0f)));
    panel.add(lightDiffuseColor.set("lightDiffuseColor", ofFloatColor(0.0f, 1.0f, 0.0f), ofFloatColor(0.0f, 0.0f, 0.0f), ofFloatColor(1.0f, 1.0f, 1.0f)));
    panel.add(lightAmbientColor.set("lightAmbientColor", ofFloatColor(0.0f, 0.0f, 1.0f), ofFloatColor(0.0f, 0.0f, 0.0f), ofFloatColor(1.0f, 1.0f, 1.0f)));
    // - material
    panel.add(materialSpecularColor.set("materialSpecularColor", ofFloatColor(1.0f, 0.0f, 0.0f), ofFloatColor(0.0f, 0.0f, 0.0f), ofFloatColor(1.0f, 1.0f, 1.0f)));
    panel.add(materialDiffuseColor.set("materialDiffuseColor", ofFloatColor(0.0f, 1.0f, 0.0f), ofFloatColor(0.0f, 0.0f, 0.0f), ofFloatColor(1.0f, 1.0f, 1.0f)));
    panel.add(materialAmbientColor.set("materialAmbientColor", ofFloatColor(0.0f, 0.0f, 1.0f), ofFloatColor(0.0f, 0.0f, 0.0f), ofFloatColor(1.0f, 1.0f, 1.0f)));
    panel.add(materialEmissiveColor.set("materialEmissiveColor", ofFloatColor(0.0f, 0.0f, 0.0f), ofFloatColor(0.0f, 0.0f, 0.0f), ofFloatColor(1.0f, 1.0f, 1.0f)));
    panel.add(materialShininess.set("materialShininess", 64, 0, 128));
    // - sphere
    panel.add(sphereRadius.set("sphereRadius", 30, 1, 100));
    panel.add(sphereResolution.set("sphereResolution", 10, 2, 30));
    // - box
    /* comment out the code to check glEnable(GL_COLOR_MATERIAL) because of bug: every material parameter should be overwritten by ofSetColor(boxColor) on line 98 in ofApp.cpp)
     panel.add(boxSize.set("boxSize", ofVec3f(60, 60, 60), ofVec3f(1, 1, 1), ofVec3f(500, 500, 500)));
     panel.add(boxResolution.set("boxResolution", 30, 1, 100));
     panel.add(boxColor.set("boxColor", ofColor::red, ofColor::black, ofColor::white));
     */
    // - load settings data
    panel.loadFromFile("settings.xml");
    
    // light
    light.setPosition(100, 100, 100);
    light.setSpecularColor(lightSpecularColor);
    light.setDiffuseColor(lightDiffuseColor);
    light.setAmbientColor(lightAmbientColor);
    
    // material
    material.setSpecularColor(materialSpecularColor);
    material.setDiffuseColor(materialDiffuseColor);
    material.setAmbientColor(materialAmbientColor);
    material.setEmissiveColor(materialEmissiveColor);
    material.setShininess(materialShininess); // shininess is a value between 0 - 128, 128 being the most shiny //
    
    // camera
    camera.setDistance(400);
    
    // sphere
    sphere.setPosition(0, 0, 0);
    sphere.set(sphereRadius, sphereResolution);
    
    // box
    /* comment out the code to check glEnable(GL_COLOR_MATERIAL) because of bug: every material parameter should be overwritten by ofSetColor(boxColor) on line 98 in ofApp.cpp)
     box.setPosition(ofVec3f(0, 120, 0));
     box.set(boxSize->x, boxSize->y, boxSize->z);
     box.setResolution(boxResolution);
     */
}

//--------------------------------------------------------------
void ofApp::update(){
    // light
    light.setSpecularColor(lightSpecularColor);
    light.setDiffuseColor(lightDiffuseColor);
    light.setAmbientColor(lightAmbientColor);
    
    // material
    material.setSpecularColor(materialSpecularColor);
    material.setDiffuseColor(materialDiffuseColor);
    material.setAmbientColor(materialAmbientColor);
    material.setEmissiveColor(materialEmissiveColor);
    material.setShininess(materialShininess);
    
    // sphere
    sphere.set(sphereRadius, sphereResolution);
    
    // box
    /* comment out the code to check glEnable(GL_COLOR_MATERIAL) because of bug: every material parameter should be overwritten by ofSetColor(boxColor) on line 98 in ofApp.cpp)
     box.set(boxSize->x, boxSize->y, boxSize->z);
     box.setResolution(boxResolution);
     box.rotate(1, ofVec3f(0, 1, 0));
     */
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableDepthTest();{
        ofEnableLighting();{
            camera.begin();{
                light.enable();{
                    light.draw();
                    glDisable(GL_COLOR_MATERIAL);
                    material.begin();{
                        sphere.draw();
                        /* comment out the code to check glEnable(GL_COLOR_MATERIAL) because of bug: every material parameter should be overwritten by ofSetColor(boxColor) on line 98 in ofApp.cpp)
                         glEnable(GL_COLOR_MATERIAL);
                         ofSetColor(boxColor);
                         box.draw();
                         */
                    }material.end();
                    sphere.draw();
                }light.disable();
            }camera.end();
        }ofDisableLighting();
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
