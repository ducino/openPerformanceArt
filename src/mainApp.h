#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"

class SceneFactory;
class SceneProxy;

class mainApp : public ofBaseApp{

	public:
		mainApp();
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

	private:
		//Title
		char* title;
		ofTrueTypeFont titleFont;

		//Scenes		
		vector<SceneProxy*> scenes;
		SceneFactory* pSceneFactory;
		SceneProxy* pCurrentScene;
};

#endif
