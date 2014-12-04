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
    
    int _defaultTimeSlice;
    int _maxTimeSlice;
    int _minTimeSlice;
    
    int _currentTimeSlice;
 

public:
    Road* _greenForRoad;
    std::vector<Road*> _inComingRoads;
    Junction();
    Junction(const std::string &junctionID, int defaultTimeSlice, int maxTimeSlice, int minTimeSlice);
    virtual ~Junction();
    std::string getId();
    std::string setGreenForIncomingJunction();
    void setTime(int time);
    void setInComingRoads(Road &road);
    int getTimeSlice();
    std::vector<Road*> getInComingRoads();
    int getCurrentTimeSlice();
    

    
    

};

#endif	/* JUNCTION_H */

