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

//class Road;

class Junction {
    std::string _junctionID;
    Junction* _greenForIncomingJunction;
    int _currentTime;
    int _defaultTimeSlice;
    int _maxTimeSlice;
    int _minTimeSlice;
    std::vector<Junction*> _inComingRoads;
    

public:
    Junction();
    Junction(const std::string &junctionID);
    virtual ~Junction();
    std::string getId();
    Junction* getGreenForIncomingJunction();
    void setTime(int time);
    void setConsts(int const DEFAULT_TIME_SLICE,int const MAX_TIME_SLICE , int const MIN_TIME_SLICE);
    void setInComingRoads(Junction &junc);

    
    

};

#endif	/* JUNCTION_H */

