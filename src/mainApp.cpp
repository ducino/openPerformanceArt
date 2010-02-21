#include "mainApp.h"
#include "scenefactory.h"
#include "sceneproxy.h"
#include "input.h"
#include "inputmanager.h"

using namespace std;

//--------------------------------------------------------------
mainApp::mainApp(int argc, const char* argv[])
: pCurrentScene(NULL),
  iCurrentScene(-1)
{
	if(argc == 1)
	{
		xmlFile = "config.xml";
	}
	else
	{
		xmlFile = string(argv[1]);
	}
}
//--------------------------------------------------------------
mainApp::~mainApp() 
{
}
//--------------------------------------------------------------
void mainApp::setup()
{
	title = "openPerformanceArt";
	titleFont.loadFont("AnnabelScript.ttf", 60);

	ofSetFrameRate(30);
	ofSetVerticalSync(true);

	SceneFactory::the().load(xmlFile, scenes);
}

//--------------------------------------------------------------
void mainApp::update()
{
	if(pCurrentScene)
	{
		pCurrentScene->update();
	}
}

//--------------------------------------------------------------
void mainApp::draw()
{
	if(iCurrentScene == -1)
	{
		drawTitleScreen();
	}
	else
	{
		pCurrentScene->draw();
	}
}

//--------------------------------------------------------------
void mainApp::keyPressed(int key)
{

	if(key == OF_KEY_LEFT)
	{
		previousScene();
	}
	else if(key == OF_KEY_RIGHT)
	{
		nextScene();
	}
	else if(key == OF_KEY_RETURN)
	{
		if(pCurrentScene)
		{
			pCurrentScene->load();
		}
	}
	else if(key == OF_KEY_BACKSPACE)
	{
		unloadCurrentScene();
		iCurrentScene = -1;
		pCurrentScene = NULL;
	}
}

//--------------------------------------------------------------
void mainApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void mainApp::mouseMoved(int x, int y )
{

}

//--------------------------------------------------------------
void mainApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void mainApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void mainApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void mainApp::windowResized(int w, int h)
{

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
//--------------------------------------------------------------
void mainApp::previousScene()
{
	if(scenes.size() > 0)
	{
		iCurrentScene = (scenes.size()+iCurrentScene-1)%scenes.size();

		unloadCurrentScene();

		pCurrentScene = scenes.at(iCurrentScene);
	}
}
//--------------------------------------------------------------
void mainApp::nextScene()
{
	if(scenes.size() > 0)
	{
		iCurrentScene = (iCurrentScene+1)%scenes.size();

		unloadCurrentScene();

		pCurrentScene = scenes.at(iCurrentScene);
	}
}
//--------------------------------------------------------------
void mainApp::unloadCurrentScene()
{
	if(pCurrentScene)
	{
		pCurrentScene->unload();
		InputManager::the().unregisterAllObservers();
	}
}