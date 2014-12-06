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
    Road* _greenForRoad;
    std::vector<Road*> _inComingRoads; 
    

public:

    Junction();
    Junction(const std::string &junctionID, int defaultTimeSlice, int maxTimeSlice, int minTimeSlice);
    virtual ~Junction();
    std::string getId();
    int setGreenForIncomingJunction();
    Road* getGreenForRoad();
    std::vector<Road*> getInComingRoads();
    void setInComingRoads(Road &road);
    int getTimeSlice();
    int getCurrentTimeSlice();
    void setGreenForRoad(Road* _greenForRoad);
    std::string getCarToRemove();

};

#endif	/* JUNCTION_H */

