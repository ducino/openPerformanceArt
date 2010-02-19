#ifndef _SCENE_PROXY_H
#define _SCENE_PROXY_H

#include <string>
using namespace std;

class Scene;
class ofTrueTypeFont;

namespace Poco { namespace XML { class Node; }}

class SceneProxy {

	public:
		SceneProxy(Poco::XML::Node* pRootNode);
		~SceneProxy();

		/*
		 * Load the scene
		 */
		void load();

		/*
		 * Unload the scene, releasing its resources
		 */
		void unload();

		/*
		 * Update the scene, should be called whenever the scene is active 
		 * and the main update method is called
		 */
		void update();

		/*
		 * Draw the scene, should be called whenever the scene is active 
		 * and the main draw method is called
		 */
		void draw();

	private:
		string name;
		Scene* pScene;
		Poco::XML::Node* pNode;

		ofTrueTypeFont* pFont;
};

#endif
