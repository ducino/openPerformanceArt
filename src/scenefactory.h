#ifndef _SCENE_FACTORY_H
#define _SCENE_FACTORY_H

#include <string>
#include <vector>
using namespace std;

class SceneProxy;

class SceneFactory {

	public:
		SceneFactory();
		~SceneFactory();

		/*
		 * Load all scenes described in the given xml file
		 */
		void loadScenes(string xmlFile, vector<SceneProxy*>& scenes);
};

#endif
