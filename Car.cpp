/* 
 * File:   Car.cpp
 * Author: chen
 * 
 * Created on November 15, 2014, 2:27 PM
 */

#include "Car.h"
#include "Road.h"
#include <algorithm>
#include <map>
#include <string>

Car::Car(const std::string& carID, std::map<int, Road*> roadPlan) {
    _carID=carID;
    _remainingTimeToFault=0;
    _distanceFromBeginningOfRoad=0;
    _currentRoad=_roadPlan[0];
    _numOfJunctionTheCarPass=0;
    _currentRoadNumber=0;
    
}
void Car::newSpeed(){
    int baseSpeed=_currentRoad->getBaseSpeed();
    for(auto& key:_currentRoad->getFaultyCarsOnRoadMap()){
        if(_distanceFromBeginningOfRoad<key.first){
            for(auto& car:key.second ){
                baseSpeed=baseSpeed/2;
            }
        }
    }
    _speed=baseSpeed;
}

Car::~Car() {//check that everything is deleted
        std::cout << "Car deleted"<< std::endl;

}



void Car::advanceCar(int time){
    int remaining=_currentRoad->getLen()-_distanceFromBeginningOfRoad;
    if(_remainingTimeToFault==1){
        _currentRoad->removeFaultyCar(*this);
    }
    if(_remainingTimeToFault>0){
        _remainingTimeToFault--;
    }
    else if(remaining>0){
            this->newSpeed();
            if(remaining<_speed){
                _distanceFromBeginningOfRoad=_currentRoad->getLen();
                _currentRoad->addCarToWaitingList(this);
            }
            else
                _distanceFromBeginningOfRoad+=_speed;
            
            
    }
    _history=_history.append("(").append(std::to_string(time)).append(",").append(_currentRoad->getSJunc().getId()).append(",").append(_currentRoad->getEJunc().getId()).append(",").append(std::to_string(_distanceFromBeginningOfRoad)).append(")");
    
}
int Car::getDistanceFromBeginningOfRoad(){
    return _distanceFromBeginningOfRoad;
}

std::string Car::getCarId(){
    return _carID;
}

Road* Car::getCurrentRoad() {
    return _currentRoad;
}

void Car::setRemainingTimeToFault(int time) {
     _remainingTimeToFault=_remainingTimeToFault+time;
}

std::string Car::getHistory() {
    return _history;
}

int Car::getRemainingTimeOfFault() {
    return _remainingTimeToFault;
}

void Car::setCurrentRoad(Road* road) {
    _currentRoad=road;
}

int Car::setNextRoad() {
    if(_currentRoadNumber+1<_roadPlan.size()){
        _currentRoad=_roadPlan.find(_currentRoadNumber+1)->second;
        return 0;//dont remove car from carsmap
    }
    else{
        return 1;//remove car from carsmap
    }
    
}
