/* 
 * File:   Road.cpp
 * Author: chen
 * 
 * Created on November 15, 2014, 2:34 PM
 */

#include "Road.h"
#include "Car.h"
#include <math.h>
#include <string>
#include <iostream>
#include <vector>

Road::Road() {
}

Road::Road(const Junction &startingJunction, const Junction &endJunction, int length) {
    *_startingJunction=startingJunction;
    *_endJunction=endJunction;
    _length=length;
    _baseSpeed=0;
    _noOfCars=0;
    _timeSlice=_endJunction->getTimeSlice();
}

Road::~Road() {
}
Junction Road::getSJunc(){
    return *_startingJunction;
}
Junction Road::getEJunc(){
    return *_endJunction;
}
int Road::getLen(){
    return _length;
}
void Road::baseSpeed(){
    _baseSpeed=ceil(_length/_noOfCars);
}
int Road::getNoOfCars(){
    return _noOfCars;
}
void Road::removeFaultyCar(Car& car){
    int position;
    for(int i=0; i<_faultyCarsOnRoad[car.getDistanceFromBeginningOfRoad()].size();i++){//find the position of the car in the vector
        if(car.getCarId().compare(_faultyCarsOnRoad[car.getDistanceFromBeginningOfRoad()][i]->getCarId())==0)
            position=i;
    }
    _faultyCarsOnRoad[car.getDistanceFromBeginningOfRoad()]
    .erase(_faultyCarsOnRoad[car.getDistanceFromBeginningOfRoad()].begin()+position);
}
void Road::addCarToRoad(){
    _noOfCars++;
}

std::map<int, std::vector<Car*> > Road::getFaultyCarsOnRoadMap() {
    return _faultyCarsOnRoad;

}

int Road::getBaseSpeed() {
    return _baseSpeed;
}

void Road::addCarToWaitingList(Car* car) {
    _waitingForGreenLightList.push(car);
}

void Road::removeCarFromWaitingList() {
    _waitingForGreenLightList.front()->setNextRoad();
    _waitingForGreenLightList.pop();
}

void Road::addFaultyCar(Car& car) {

}

int Road::getTimeSlice() {
    return _timeSlice;
}

int Road::getNumOfWaitingCars() {
    return _numOfWaitingCars;
}

void Road::setNumOfWaitingCars() {
    _numOfWaitingCars=_waitingForGreenLightList.size();
}

void Road::setTimeSlice(int time) {
    _timeSlice=time;
}





