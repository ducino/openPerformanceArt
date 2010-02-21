#include "scenefactory.h"

#include "timerinput.h"

#include "backgroundoutput.h"
#include "rectangleoutput.h"
#include "ellipseoutput.h"
#include "imageoutput.h"

#include "timedoutput.h"
#include "roundrobin.h"


#define INPUT(__name__, __class__) inputMap.insert(make_pair(__name__, new __class__()));
#define OUTPUT(__name__, __class__) outputMap.insert(make_pair(__name__, new __class__()));

//--------------------------------------------------------------
void SceneFactory::createInputMap()
{
	INPUT("timer", TimerInput)
}
//--------------------------------------------------------------
void SceneFactory::createOutputMap()
{
	OUTPUT("background", BackgroundOutput)	
	OUTPUT("rectangle", RectangleOutput)
	OUTPUT("ellipse", EllipseOutput)
	OUTPUT("image", ImageOutput)

	OUTPUT("timed", TimedOutput)
	OUTPUT("roundrobin", RoundRobin)
}