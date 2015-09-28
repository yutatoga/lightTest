#include "ofApp.h"

void ofApp::setup(){
    ofBackground(ofColor::black);
    
    // gui
    panel.setup("light test", "settings.xml", 0, 0);
    panel.add(lightOrientation.set("lightOrientation", ofVec3f(0, 0, 0), ofVec3f(-180, -180, -180), ofVec3f(180, 180, 180)));
    panel.add(enableDrawBox.set("drawBox", false));
    panel.add(enableDrawSphere.set("drawShpere", true));
    panel.add(enableLightPoint.set("enableLightPoint", true));
    panel.add(enableLightSpot.set("enableLightSpot", false));
    panel.add(enableLightDirectional.set("enableLightDirectional", false));
    
    panel.loadFromFile("settings.xml");
    
    camera.setAutoDistance(false);
    camera.setPosition(0, 0, 500);
    camera.lookAt(ofVec3f(0, 0, 0));
    
    // set up primitive shape
    // - box
    box.set(30, 30, 30);
    box.setPosition(0, 0, 0);
    // - sphere
    sphere.set(50, 100);
    sphere.setPosition(0, 0, 0);

    // LIGHT
    ofFloatColor diffuseColor(1, 0, 0);
    ofFloatColor specularColor(0, 1, 0);
    ofFloatColor ambientColor(0, 0, 1);
    ofVec3f lightPosition(50, 50, 100);
    
    // - point light
    lightPoint.setDiffuseColor(diffuseColor);
    lightPoint.setSpecularColor(specularColor);
    lightPoint.setAmbientColor(ambientColor);
    lightPoint.setPosition(lightPosition);
    lightPoint.setPointLight();
    
    // - spot light
    lightSpot.setDiffuseColor(diffuseColor);
    lightSpot.setSpecularColor(specularColor);
    lightSpot.setAmbientColor(ambientColor);
    lightSpot.setPosition(lightPosition);
    lightSpot.setSpotlight();
    
    // - directional light
    lightDirectional.setDiffuseColor(diffuseColor);
    lightDirectional.setSpecularColor(specularColor);
    lightDirectional.setAmbientColor(ambientColor);
    lightDirectional.setPosition(lightPosition);
    lightDirectional.setDirectional();
    
    // material
    // color of material for each material type
    material.setShininess(64); // shininess is a value between 0 - 128, 128 being the most shiny //
    material.setSpecularColor(ofFloatColor(1.0, 1.0, 1.0));
    material.setDiffuseColor(ofFloatColor(1.0, 1.0, 1.0));
    material.setAmbientColor(ofFloatColor(1.0, 1.0, 1.0));
}


//--------------------------------------------------------------
void ofApp::update(){
    float lightPointPositionX = lightPoint.getPosition().x;
    float lightSpotPositionX = lightSpot.getPosition().x;
    float lightDirectionalPositionX = lightDirectional.getPosition().x;
    
    lightPointPositionX += 0.1;
    lightSpotPositionX += 0.1;
    lightDirectionalPositionX += 0.1;
    
    lightPoint.setPosition(lightPointPositionX, lightPoint.getPosition().y, lightPoint.getPosition().z);
    lightSpot.setPosition(lightSpotPositionX, lightSpot.getPosition().y, lightSpot.getPosition().z);
    lightDirectional.setPosition(lightDirectionalPositionX, lightDirectional.getPosition().y, lightDirectional.getPosition().z);
    
    lightPoint.setOrientation(lightOrientation);
    lightSpot.setOrientation(lightOrientation);
    lightDirectional.setOrientation(lightOrientation);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableDepthTest();{
        camera.begin();{
            ofEnableLighting();{
                if (enableLightPoint) {
                    lightPoint.enable();
                    lightPoint.draw();
                }
                if (enableLightSpot) {
                    lightSpot.enable();
                    lightSpot.draw();
                }
                if (enableLightDirectional) {
                    lightDirectional.enable();
                    lightDirectional.draw();
                }
                material.begin();{
                    if (enableDrawBox) {
                        box.draw();
                        box.drawAxes(100);
                    }
                    if (enableDrawSphere) {
                        sphere.draw();
                        sphere.drawAxes(100);
                    }
                }material.end();
                if (enableLightPoint) {
                    lightPoint.disable();
                }
                if (enableLightSpot) {
                    lightSpot.disable();
                }
                if (enableLightDirectional) {
                    lightDirectional.disable();
                }
            }ofDisableLighting();
        }camera.end();
    }ofDisableDepthTest();
    
    // gui
    panel.draw();
}
