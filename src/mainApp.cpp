#include "mainApp.h"
#include "scenefactory.h"
#include "sceneproxy.h"

//--------------------------------------------------------------
mainApp::mainApp()
: pCurrentScene(NULL),
  iCurrentScene(-1)
{
	pSceneFactory = new SceneFactory();
}
//--------------------------------------------------------------
mainApp::~mainApp() 
{
	delete pSceneFactory;
}
//--------------------------------------------------------------
void mainApp::setup()
{
	title = "openPerformanceArt";
	titleFont.loadFont("AnnabelScript.ttf", 60);

	ofSetFrameRate(30);

	pSceneFactory->loadScenes("Test.xml", scenes);
}

//--------------------------------------------------------------
void mainApp::update()
{
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
		iCurrentScene = (iCurrentScene+1)%scenes.size();

		//Unload previous scene
		if(pCurrentScene)
		{
			pCurrentScene->unload();
		}

		pCurrentScene = scenes.at(iCurrentScene);
	}
}
//--------------------------------------------------------------
void mainApp::nextScene()
{
	if(scenes.size() > 0)
	{
		iCurrentScene = (iCurrentScene+1)%scenes.size();

		//Unload previous scene
		if(pCurrentScene)
		{
			pCurrentScene->unload();
		}

		pCurrentScene = scenes.at(iCurrentScene);
	}
}
//--------------------------------------------------------------
