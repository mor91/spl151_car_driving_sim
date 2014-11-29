/* 
 * File:   Junction.cpp
 * Author: chen
 * 
 * Created on November 15, 2014, 1:36 PM
 */

#include "Junction.h"
#include <vector>

Junction::Junction() {
}

Junction::Junction(const std::string &junctionID) {
    _junctionID=junctionID;
    _currentTimeSlice=0;
}

Junction::~Junction() {
}

std::string Junction::getId(){
    return _junctionID;
}

void Junction::setTime(int time) {
    _currentTime=time;
}

void Junction::setConsts(const int DEFAULT_TIME_SLICE, const int MAX_TIME_SLICE, const int MIN_TIME_SLICE) {
    _defaultTimeSlice=DEFAULT_TIME_SLICE;
    _maxTimeSlice=MAX_TIME_SLICE;
    _minTimeSlice=MIN_TIME_SLICE;
}


Junction* Junction::getGreenForIncomingJunction() {
    
    return _greenForIncomingJunction;
}

void Junction::setInComingRoads(Junction &junc) {
    _inComingRoads.push_back(&junc);
}

int Junction::getTimeSlice() {
    return _defaultTimeSlice;
}


