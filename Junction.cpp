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
#include <iostream>

std::string carToRemove;

Junction::Junction() {
}

Junction::Junction(const std::string &junctionID, int defaultTimeSlice, int maxTimeSlice, int minTimeSlice) {
    _junctionID=junctionID;
    std::cout << _junctionID << std::endl;
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


int Junction::setGreenForIncomingJunction() {
    int found=0;
    int removeCar=0;
    int changeLight=0;
    for(int i=0; i<_inComingRoads.size() && found>0;i++){
        if(_inComingRoads[i]->getSJunc()->getId().compare(_greenForRoad->getSJunc()->getId())==0){
            found=i+1; 
        }
    }//found the road that has a green light in the road map
    if(_currentTimeSlice==0)
        _greenForRoad->setNumOfWaitingCars();
    if(_greenForRoad->getTimeSlice()==_currentTimeSlice){//end o green light or this road
        if(_greenForRoad->getNumOfWaitingCars()>=_greenForRoad->getTimeSlice() ){
            _greenForRoad->setTimeSlice(std::min(_greenForRoad->getTimeSlice()+1,_maxTimeSlice));   
        }
        if(_greenForRoad->getNumOfWaitingCars()==0 && !_greenForRoad->getCarsWaitingForGreenLight()){
            _greenForRoad->setTimeSlice(std::max(_greenForRoad->getTimeSlice()-1, _minTimeSlice));
        }
        changeLight=1;
    }
    if(_currentTimeSlice<_greenForRoad->getTimeSlice()){
        _currentTimeSlice++;
    }
    if(_greenForRoad->getWaitingList().size()!=0 && _greenForRoad->removeCarFromWaitingList()==1){
        carToRemove=_greenForRoad->getCarToRemove()->getCarId();
        removeCar=1;  
    }
    if(changeLight){
         if(found==_inComingRoads.size()){
            _greenForRoad=_inComingRoads[0];
         }
        else _greenForRoad=_inComingRoads[found];
        _currentTimeSlice=0;
        _greenForRoad->setNumOfWaitingCars();
        _greenForRoad->setCarsWaitingForGreenLight();
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

Road* Junction::getGreenForRoad() {
    return _greenForRoad;
}

void Junction::setGreenForRoad(Road* _greenForRoad) {
    this->_greenForRoad = _greenForRoad;
}

std::string Junction::getCarToRemove() {
    return carToRemove;
}
