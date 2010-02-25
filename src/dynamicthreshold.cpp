/*
 * DynamicThreshold implementation
 *
 * Copyright 2010 Johan Robben
 * This code is distributed under the terms of the GNU General Public License
 */
#include "dynamicthreshold.h"
#include "ofUtils.h"
#include <iostream>

//--------------------------------------------------------------
DynamicThreshold::DynamicThreshold(long updateTime, float activation)
: previousUpdateTime(0),
  updateTime(updateTime),
  activation(activation)
{

}
//--------------------------------------------------------------
DynamicThreshold::~DynamicThreshold()
{
}
//--------------------------------------------------------------
bool DynamicThreshold::check(float data)
{
	if(data > threshold)
	{
		threshold = data;
		previousUpdateTime = ofGetElapsedTimeMillis();
	}

	if(ofGetElapsedTimeMillis() - previousUpdateTime > updateTime)
	{
		threshold = 0.95*threshold;
		previousUpdateTime = ofGetElapsedTimeMillis();
	}

	if(data > activation*threshold)
	{
		return true;
	}

	return false;
}
