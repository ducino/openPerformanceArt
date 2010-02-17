#ifndef _SCENE_PROXY_H
#define _SCENE_PROXY_H

#include <string>
using namespace std;

class Scene;
class ofTrueTypeFont;

namespace Poco { namespace XML { class Node; }}

class SceneProxy {

	public:
		SceneProxy(Poco::XML::Node* pNode);
		~SceneProxy();

		void load();
		void unload();

		void update();
		void draw();

	private:
		string name;
		Scene* pScene;
		Poco::XML::Node* pNode;

		ofTrueTypeFont* pFont;
};

#endif
