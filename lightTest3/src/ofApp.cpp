#include "ofApp.h"

void ofApp::setup(){
    ofBackground(ofColor::black);
    
    // gui
    panel.setup("light test", "settings.xml", 0, 0);
    panel.add(lightOrientation.set("lightOrientation", ofVec3f(0, 0, 0), ofVec3f(-180, -180, -180), ofVec3f(180, 180, 180)));
    panel.add(enableDrawBox.set("drawBox", false));
    panel.add(enableDrawSphere.set("drawShpere", true));
    //    panel.add(enableMouseInput.set("enableMouseInput", false));
    panel.loadFromFile("settings.xml");
    
//    camera.disableMouseInput();
    camera.setPosition(0, 0, 100);
    camera.lookAt(ofVec3f(0, 0, 0));
    camera.setTarget(box.getPosition());
    
    light.setOrientation(lightOrientation);
    light.setDiffuseColor(ofFloatColor(1, 0, 0));
    light.setSpecularColor(ofFloatColor(0, 0, 0));
    light.setAmbientColor(ofFloatColor(0, 0, 0));

    light.setDirectional();
    light.setPosition(100, 100, 100);
    
//    light.setPointLight();
    
    // set up primitive shape
    // - box
    box.set(30, 30, 30);
    box.setPosition(0, 0, 0);
    // - sphere
    sphere.set(30, 100);
    sphere.setPosition(0, 0, 0);
}


//--------------------------------------------------------------
void ofApp::update(){
    light.setOrientation(lightOrientation);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableDepthTest();{
        camera.begin();{
            ofEnableLighting();{
                light.enable();{
                    light.draw();
                    if (enableDrawBox) {
                        box.draw();
                        box.drawAxes(100);
                    }
                    if (enableDrawSphere) {
                        sphere.draw();
                        sphere.drawAxes(100);
                    }
                }light.disable();
            }ofDisableLighting();
        }camera.end();
    }ofDisableDepthTest();
    
    // gui
    panel.draw();
}