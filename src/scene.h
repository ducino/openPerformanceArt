#ifndef _SCENE_H
#define _SCENE_H

//Includes
#include <vector>
#include "ofMain.h"

//Forward declarations
class Output;
namespace Poco { namespace XML { class Node; } }

class Scene {

public:
	Scene(Poco::XML::Node* pNode);
	~Scene();

	void update();
	void draw();

	/*
	 * Add an output to this scene
	 * The scene becomes owner of the pointer
	 */
	void add(Output* output);

private:
	vector<Output*> outputs;
};

#endif
