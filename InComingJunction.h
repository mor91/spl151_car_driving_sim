/*
 * InComingJunction.h
 *
 *  Created on: Nov 20, 2014
 *      Author: mormichl
 */

#ifndef INCOMINGJUNCTION_H_
#define INCOMINGJUNCTION_H_
#include <string>
#include "Junction.h"


class InComingJunction : public Junction{
	Junction _junction;
	int _timeSlice;
        

public:
	InComingJunction();
	InComingJunction(const Junction& junction, int timeSlice);
	~InComingJunction();
	int newTimeSlice() const;
};


#endif /* INCOMINGJUNCTION_H_ */
