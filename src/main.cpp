/*
 * main
 *
 * Copyright 2010 Johan Robben
 * This code is distributed under the terms of the GNU General Public License
 */
#include "ofMain.h"
#include "mainApp.h"
#include "ofAppGlutWindow.h"

//========================================================================
int main( int argc, const char* argv[] ){

    ofAppGlutWindow window;

	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofSetupOpenGL(&window, 1024, 768, OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	ofRunApp(new mainApp(argc, argv));

}
