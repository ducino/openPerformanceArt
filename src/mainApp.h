#ifndef _TEST_APP
#define _TEST_APP

//Includes
#include "ofMain.h"

//Forward declarations
class SceneFactory;
class SceneProxy;
class Input;

class mainApp : public ofBaseApp{

	public:
		mainApp(int argc, const char* argv[]);
		~mainApp();

		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);

	private:

		void drawTitleScreen();

		//Go to previous scene in the scenes list
		void previousScene();

		//Go to the next scene in the scenes list
		void nextScene();

		//Unload the current scene
		void unloadCurrentScene();

	private:
		//Title
		char* title;
		ofTrueTypeFont titleFont;

		//Scenes		
		vector<SceneProxy*> scenes;
		int iCurrentScene;
		SceneProxy* pCurrentScene;
};

#endif
