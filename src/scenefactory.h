#ifndef _SCENE_FACTORY_H
#define _SCENE_FACTORY_H

#include <string>
#include <vector>
using namespace std;

class SceneProxy;
namespace Poco { namespace XML {class Node;} }

class SceneFactory {

	public:
		SceneFactory();
		~SceneFactory();

		/*
		 * Load all scenes described in the given xml file
		 */
		void loadScenes(string xmlFile, vector<SceneProxy*>& scenes);

	private:

		//Check if the tag of the node matches the given name
		bool match(Poco::XML::Node* pNode, string tag);
};

#endif
