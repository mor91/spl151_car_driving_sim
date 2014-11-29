/* 
 * File:   Junction.h
 * Author: chen
 *
 * Created on November 15, 2014, 1:36 PM
 */

#ifndef JUNCTION_H
#define	JUNCTION_H
#include <string>
#include <vector>
//#include "Road.h"

class Road;

class Junction {
    std::string _junctionID;
    Road* _greenForRoad;
    int _currentTime;
    int _defaultTimeSlice;
    int _maxTimeSlice;
    int _minTimeSlice;
    std::vector<Road*> _inComingRoads;
    int _currentTimeSlice;
 

public:
    Junction();
    Junction(const std::string &junctionID);
    virtual ~Junction();
    std::string getId();
    void setGreenForIncomingJunction();
    void setTime(int time);
    void setConsts(int const DEFAULT_TIME_SLICE,int const MAX_TIME_SLICE , int const MIN_TIME_SLICE);
    void setInComingRoads(Road &road);
    int getTimeSlice();
    

    
    

};

#endif	/* JUNCTION_H */

