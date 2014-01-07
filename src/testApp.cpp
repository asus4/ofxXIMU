#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
//    ximu.setup("/dev/tty.usbserial-AM01L7PN"); // with usb
    ximu.setup("/dev/tty.x-IMU-626E-RNI-SPP"); // with bluetooth
    
    ofBackground(0);
}

//--------------------------------------------------------------
void testApp::update(){
    ximu.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetLineWidth(1.0f);
    ofNoFill();
    ofSetColor(255);
    
    QuaternionStruct qs = ximu.armsQuaternion;
    ofQuaternion q(qs.x, qs.y, qs.z, qs.w);
    
    ofPushMatrix();
    {
        
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2, 0.0);
        
        ofVec3f qAxsis;
        float angle;
        q.getRotate(angle, qAxsis);
        ofRotate(angle, -qAxsis.x, -qAxsis.z, -qAxsis.y);
        ofBox(150, 50, 100);
    }
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
