#include "mainApp.h"

//--------------------------------------------------------------
void mainApp::setup(){
	title = "openPerformanceArt";
	titleFont.loadFont("AnnabelScript.ttf", 60);

	ofSetFrameRate(30);
}

//--------------------------------------------------------------
void mainApp::update(){
}

//--------------------------------------------------------------
void mainApp::draw(){
	drawTitleScreen();
}

//--------------------------------------------------------------
void mainApp::keyPressed(int key){

}

//--------------------------------------------------------------
void mainApp::keyReleased(int key){

}

//--------------------------------------------------------------
void mainApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void mainApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void mainApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void mainApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void mainApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void mainApp::drawTitleScreen()
{
	ofBackground(150, 150, 150);	

	//Draw the lines in the background
	ofSetColor(230, 230, 230);

	for(int i = 0; i < ofRandom(0, 10); i++)
	{
		float x = ofRandom(ofGetWidth()/2, ofGetWidth());
		float y = ofRandom(0, ofGetHeight()/2);
		float t = ofRandom(0, ofGetHeight()/2);
		ofLine(x, y, x - t, y + t);
	}

	//Draw the title
	ofSetColor(0x505050);
	titleFont.drawString(title, ofGetWidth()/2-titleFont.stringWidth(title)/2, ofGetHeight()/2);
}