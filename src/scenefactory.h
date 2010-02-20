#ifndef _SCENE_FACTORY_H
#define _SCENE_FACTORY_H

//Includes
#include <string>
#include <vector>
#include <map>

//Forward declarations
class SceneProxy;
class Input;
class Output;
class Scene;

namespace Poco { 
	namespace XML { 
		class Node; 
		class Document;
	} 
}

using namespace std;



class SceneFactory {

public:
	static SceneFactory& the()
	{
		static SceneFactory singleton;
		return singleton;
	}

private:
	SceneFactory();                                 // Private constructor
	~SceneFactory();
	SceneFactory(const SceneFactory&);                 // Prevent copy-construction
	SceneFactory& operator=(const SceneFactory&);      // Prevent assignment

public:

	/*
	 * Load all scenes described in the given xml file
	 */
	void load(string xmlFile, vector<SceneProxy*>& scenes);

	/* 
	 * Load outputs from the given xml
	 * Ownership of pointers is transferred to the caller
	 */
	void loadOutputs(vector<Output*>& outputs, Poco::XML::Node* pRootNode);

private:
	void createInputMap();
	void createOutputMap();
	void createInputs(Poco::XML::Node* pRootNode, vector<Input*>& inputs);

private:
	map<string, Input*> inputMap;
	map<string, Output*> outputMap;

	//The documents describing the scenes
	vector<Poco::XML::Document*> documents;
};

#endif
