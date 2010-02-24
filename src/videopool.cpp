/*
 * VideoPool implementation
 *
 * Copyright 2010 Johan Robben
 * This code is distributed under the terms of the GNU General Public License
 */
#include "videopool.h"
#include <iostream>
#include "ofVideoPlayer.h"

//--------------------------------------------------------------
VideoPool::VideoPool()
{
	for(int i = 0; i < NB_ALLOCATED_PLAYERS; i++)
	{
		players.push_back(new ofVideoPlayer());
		acquired[i] = false;
	}
}
//--------------------------------------------------------------
VideoPool::~VideoPool()
{
	for(int i = 0; i < NB_ALLOCATED_PLAYERS; i++)
	{
		delete players[i];
	}
}
//--------------------------------------------------------------
ofVideoPlayer* VideoPool::acquire()
{
	for(int i = 0; i < NB_ALLOCATED_PLAYERS; i++)
	{
		if(!acquired[i])
		{
			acquired[i] = true;
			return players[i];
		}
	}
	return NULL;
}
//--------------------------------------------------------------
void VideoPool::release(ofVideoPlayer* player)
{
	for(int i = 0; i < NB_ALLOCATED_PLAYERS; i++)
	{
		if( players[i] == player )
		{
			acquired[i] = false;
		}
	}
}