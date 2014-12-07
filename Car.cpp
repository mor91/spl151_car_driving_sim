/* 
 * File:   Car.cpp
 * Author: chen
 * 
 * Created on November 15, 2014, 2:27 PM
 */

#include "Car.h"
#include "Road.h"
#include <boost/lexical_cast.hpp>
#include <algorithm>
#include <map>
#include <string>

Car::Car(const std::string& carID, std::map<int, Road*> &roadPlan,int time) {
    _carID=carID;
    _remainingTimeToFault=0;
    _distanceFromBeginningOfRoad=0;
    _roadPlan =&roadPlan;
    _currentRoad=roadPlan[0];
    _numOfJunctionTheCarPass=0;
    _currentRoadNumber=0;
    _history= "(" + boost::lexical_cast<std::string>(time) + "," + _currentRoad->getSJunc()->getId() + "," + _currentRoad->getEJunc()->getId() + "," + boost::lexical_cast<std::string>(_distanceFromBeginningOfRoad)+ ")";
      
    
}
void Car::newSpeed(){
    int baseSpeed=_currentRoad->getBaseSpeed();
    /*for(std::map<std::string,int>::iterator it = _currentRoad->getFaultyCarsOnRoad().begin(); it!=_currentRoad->getFaultyCarsOnRoad().end(); it++){
        
        if(_distanceFromBeginningOfRoad<it->second){
            baseSpeed/=2;
        }
    }*/
    if (_currentRoad->getFaultyCarsOnRoad().size()==0) {
        _speed=baseSpeed;
        return;
    }

    for(std::map<std::string,int>::iterator it=_currentRoad->getFaultyCarsOnRoad().begin();it!=_currentRoad->getFaultyCarsOnRoad().end();it++){
        if(_distanceFromBeginningOfRoad<it->second){
            baseSpeed/=2;
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
        _currentRoad->removeFaultyCar(_carID);
    }
    if(_remainingTimeToFault>0){
        _remainingTimeToFault--;
    }
     if(_remainingTimeToFault==0 && remaining>0){
            this->newSpeed();
            if(remaining<_speed){
                _distanceFromBeginningOfRoad=_currentRoad->getLen();
                _currentRoad->addCarToWaitingList(this);
            }
            else
                _distanceFromBeginningOfRoad+=_speed;
            
            
    }
    
    _history=_history + "(" + boost::lexical_cast<std::string>(time + 1) + "," + _currentRoad->getSJunc()->getId() + "," + _currentRoad->getEJunc()->getId() + "," + boost::lexical_cast<std::string>(_distanceFromBeginningOfRoad)+ ")";
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
    if(_currentRoadNumber+1<_roadPlan->size()){
        _currentRoad->removeCarFromRoad();//noOfCarsOnRoad --
        _currentRoad->baseSpeed();//calculate new speed by num of cars on the road
        _currentRoad=_roadPlan->find(_currentRoadNumber+1)->second;
        _currentRoad->addCarToRoad();//noOfCarsOnRoad ++
        _currentRoad->baseSpeed();
        _currentRoadNumber ++;
        _distanceFromBeginningOfRoad=0;
        return 0;//dont remove car from carsmap
    }
    else{
        return 1;//remove car from carsmap
    }
    
}
