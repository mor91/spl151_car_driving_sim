/* 
 * File:   Junction.cpp
 * Author: chen
 * 
 * Created on November 15, 2014, 1:36 PM
 */

#include "Junction.h"
#include "Road.h"
#include <vector>
#include <string>

Junction::Junction() {
}

Junction::Junction(const std::string& junctionID, int defaultTimeSlice, int maxTimeSlice, int minTimeSlice) {
    _junctionID=junctionID;
    _currentTimeSlice=0;
    _defaultTimeSlice=defaultTimeSlice;
    _maxTimeSlice=maxTimeSlice;
    _minTimeSlice=minTimeSlice;
}

Junction::~Junction() {
    // _currentTime;
    //delete _currentTimeSlice;
    //delete _greenForRoad;
    //delete _inComingRoads;
    //delete _junctionID;
    //delete _maxTimeSlice;
    //delete _minTimeSlice;
    std::cout << "Junction deleted"<< std::endl;
}

std::string Junction::getId(){
    return _junctionID;
}


std::string Junction::setGreenForIncomingJunction() {
    int found=0;
    for(int i=0; i<_inComingRoads.size() && !found;i++){
        if(_inComingRoads[i]->getSJunc().getId().compare(_greenForRoad->getSJunc().getId())==0){
            found=1; 
        }
        if(_greenForRoad->getTimeSlice()==_currentTimeSlice){
            if(_greenForRoad->getNumOfWaitingCars()>=_greenForRoad->getTimeSlice())
                _greenForRoad->setTimeSlice(std::min(_greenForRoad->getTimeSlice()+1,_maxTimeSlice));
            if(_greenForRoad->getNumOfWaitingCars()==0)
                _greenForRoad->setTimeSlice(std::min(_greenForRoad->getTimeSlice()-1, _minTimeSlice));
            if(i+1==_inComingRoads.size())
                _greenForRoad=_inComingRoads[0];
            _currentTimeSlice=0;
            _greenForRoad->setNumOfWaitingCars();
        }
    }
    if(_currentTimeSlice<_greenForRoad->getTimeSlice()){
        _currentTimeSlice++;
        if(_greenForRoad->removeCarFromWaitingList()==1)
            return _greenForRoad->getCarToRemove()->getCarId();
    }

}

void Junction::setInComingRoads(Road &road) {
    _inComingRoads.push_back(&road);
}

int Junction::getTimeSlice() {
    return _defaultTimeSlice;
}

std::vector<Road*> Junction::getInComingRoads() {
    return _inComingRoads;
}

int Junction::getCurrentTimeSlice() {
    return _currentTimeSlice;
}
