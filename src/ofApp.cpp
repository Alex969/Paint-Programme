#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetBackgroundAuto(false);
    ofBackground(0);
    
    isPainting = false; // bool that states if we're painting or not
    isErasing = false;  // same but erasing
    isDynamic = false;  // same but dynamic
    brushState = (brushState + 1) % 4;
}

//--------------------------------------------------------------

void ofApp::paint(float x, float y)
{
    ofSetColor(255, 192, 203);
    ofSetRectMode(OF_RECTMODE_CENTER); // sets the x and y we pass onto DrawRectangle to the center instead of the upper left corner so that the rect in centered over the mouse
    ofDrawRectangle(x, y, 30, 30);
}

//--------------------------------------------------------------

void ofApp::erase(float x, float y)
{
    ofSetColor(0);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofDrawRectangle(x, y, 50, 50);
}

//--------------------------------------------------------------

void ofApp::dynamicBrush(float x, float y, char _brushstate)
{
    wendy.allocate(30,30, OF_IMAGE_COLOR_ALPHA);
    wendy.load("/Users/Stewbibou/Desktop/of/apps/myApps/PaintProgram/bin/data/wendymeme.jpg"); // error saying ofGLRenderer drawing an unallocated texture so I can't run the image for the dynamic brush ...
}

//--------------------------------------------------------------

void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    if(isPainting){
        paint(ofGetMouseX(), ofGetMouseY());  // if isPainting is true, then use the function paint to actually draw a rectangle using the coordinates of the mouse
    }
    
    if(isErasing){
        erase(ofGetMouseX(), ofGetMouseY());
    }
    if(isDynamic){
        wendy.draw(ofGetMouseX(), ofGetMouseY());
        
    }


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
//    std::cout << "You pressed " << key << std::endl;
    if(key == 112) {

        isPainting = true; // using key " p " to set isPainting to true to get the rectangles to draw
//        cout << "boolean value" << isPainting << std::endl;

    }
    
    if(key == 101){
        
        isErasing = true;
    }
    
//    if(key == 100){
//
//        isDynamic = true;
//    }


}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
    if(key == 112){
        
        isPainting = false; // when the " p " key is released isPainting is set to false which doesnt let the if statement in draw run, so the rectangles aren't drawn on the screen anymore
    }
    
    if(key == 101){
        
        isErasing = false;
    }
    
    if(key == 100){

        isDynamic = false;
    }

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
