/*
 * VideoPool class
 * A class to avoid destruction of ofVideoPlayers
 * (it doesn't handle that very well it seems)
 *
 * Copyright 2010 Johan Robben
 * This code is distributed under the terms of the GNU General Public License
 */
#ifndef _VIDEO_POOL_H
#define _VIDEO_POOL_H

//Includes
#include <string>
#include <vector>
#include <map>

//Forward declarations
class ofVideoPlayer;

using namespace std;

#define NB_ALLOCATED_PLAYERS 10

class VideoPool {

public:
	VideoPool();
	~VideoPool();

	/*
	 * Acquire an ofVideoPlayer, returns NULL if none available
	 */
	ofVideoPlayer* acquire();

	/*
	 * Release an ofVideoPlayer back to the pool
	 */
	void release(ofVideoPlayer* player);

public:
	vector<ofVideoPlayer*> players;
	bool acquired[NB_ALLOCATED_PLAYERS];

};

#endif
