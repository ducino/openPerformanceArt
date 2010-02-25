/*
 * DynamicThreshold class
 * A threshold class which computes it's activation threshold 
 * from the incoming data
 *
 * Copyright 2010 Johan Robben
 * This code is distributed under the terms of the GNU General Public License
 */
#ifndef _DYNAMIC_THRESHOLD_H
#define _DYNAMIC_THRESHOLD_H

//Includes

//Forward declarations

class DynamicThreshold {

public:
	/*
	 * Create a new dynamic threshold
	 * updateTime: When the threshold has not changed for <updateTime> it is reduced bij 5%
	 * activation: If the incoming data is greater than <activation>*threshold, the threshold is activated
	 */
	DynamicThreshold(long updateTime, float activation);
	~DynamicThreshold();

	/*
	 * Check if the threshold is activated
	 * If the incoming data is greater than <activation>*threshold, the threshold is activated
	 */
	bool check(float data);

public:
	long previousUpdateTime;
	long updateTime;
	float threshold;
	float activation;

};

#endif
