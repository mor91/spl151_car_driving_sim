/* 
 * File:   CarFaultEvent.cpp
 * Author: chen
 * 
 * Created on November 15, 2014, 1:30 PM
 */

#include "CarFaultEvent.h"
#include "Event.h"

CarFaultEvent::CarFaultEvent() {
}

CarFaultEvent::CarFaultEvent(int time, const std::string &carID, int timeOfFault) {
    _time=time;
    _carID=carID;
    _timeOfFault=timeOfFault;
}

CarFaultEvent::~CarFaultEvent() {
}

void CarFaultEvent::performEvent(){
    
}



