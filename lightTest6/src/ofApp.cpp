#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    panel.setup("light test", "settings.xml", 0, 0);
    panel.add(specularColor.set("specularColor", ofFloatColor(0.0, 0.0, 0.0), ofFloatColor(0.0, 0.0, 0.0), ofFloatColor(1.0, 1.0, 1.0)));
    panel.add(diffuseColor.set("diffuseColor", ofFloatColor(1.0, 1.0, 1.0), ofFloatColor(0.0, 0.0, 0.0), ofFloatColor(1.0, 1.0, 1.0)));
    panel.add(ambientColor.set("ambientColor", ofFloatColor(0.0, 0.0, 0.0), ofFloatColor(0.0, 0.0, 0.0), ofFloatColor(1.0, 1.0, 1.0)));
    panel.add(attenuation.set("attenuatioin", ofVec3f(1.0, 0.0, 0.0), ofVec3f(0.0, 0.0, 0.0), ofVec3f(5.0, 0.01, 0.0001)));
    panel.add(sphereResolution.set("sphereResolution", 15, 2, 100));
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
    
    camera.setAutoDistance(false);
    camera.setPosition(1500, -1500, 1500);
    camera.lookAt(ofVec3f(0, 0, 0));
    
    ofLogNotice("initial light type: "+ofToString(light.getType()));
    
    // set light type
    light.setPointLight();
    light.setPosition(0, 0, 0);
    light.setAttenuation(attenuation->x, attenuation->y, attenuation->z);
    
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
    for (int y = 0; y < INITIAL_SPHERE_NUMBER_Y; y++){
        for (int x = 0; x < INITIAL_SPHERE_NUMBER_X; x++) {
            for (int z = 0; z < INITIAL_SPHERE_NUMBER_Z; z++) {
                if (!(z == 0 && x == 0 && y == 0)) {
                    ofSpherePrimitive instantSpherePrimitive;
                    instantSpherePrimitive.set(sphereRadius, sphereResolution);
                    instantSpherePrimitive.setPosition(x*sphereRadius*-3, y*sphereRadius*3, z*sphereRadius*-3);
                    spheres.push_back(instantSpherePrimitive);
                }
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    // update light
    light.setDiffuseColor(diffuseColor);
    light.setSpecularColor(specularColor);
    light.setAmbientColor(ambientColor);
    light.setAttenuation(attenuation->x, attenuation->y, attenuation->z);
    
    // update sphere
    for (int i = 0; i < (int)spheres.size(); i++) {
        spheres[i].set(sphereRadius, sphereResolution);
    }
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
                        for (int i = 0; i < (int)spheres.size(); i++) {
                            if (enableDrawWireFrame) {
                                spheres[i].drawWireframe();
                            }else{
                                spheres[i].draw();
                            }
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
