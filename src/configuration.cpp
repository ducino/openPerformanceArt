/*
 * Configuration
 *
 * Copyright 2010 Johan Robben
 * This code is distributed under the terms of the GNU General Public License
 */
#include "scenefactory.h"

#include "timerinput.h"
#include "audioinput.h"

#include "backgroundoutput.h"
#include "rectangleoutput.h"
#include "ellipseoutput.h"
#include "imageoutput.h"
#include "videooutput.h"

#include "timedoutput.h"
#include "roundrobin.h"
#include "randompick.h"


#define INPUT(__name__, __class__) inputMap.insert(make_pair(__name__, new __class__()));
#define OUTPUT(__name__, __class__) outputMap.insert(make_pair(__name__, new __class__()));

//--------------------------------------------------------------
void SceneFactory::createInputMap()
{
	INPUT("timer", TimerInput)
	INPUT("audio", AudioInput)
}
//--------------------------------------------------------------
void SceneFactory::createOutputMap()
{
	OUTPUT("background", BackgroundOutput)	
	OUTPUT("rectangle", RectangleOutput)
	OUTPUT("ellipse", EllipseOutput)
	OUTPUT("image", ImageOutput)
	OUTPUT("video", VideoOutput)

	OUTPUT("timed", TimedOutput)
	OUTPUT("roundrobin", RoundRobin)
	OUTPUT("randompick", RandomPick)
}