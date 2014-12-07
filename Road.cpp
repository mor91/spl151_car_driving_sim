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
#include <queue>
#include <algorithm>


Road::Road() {
}

Road::Road( Junction &startingJunction,  Junction &endJunction, int length,int maxSpeed) {
    _startingJunction=&startingJunction;
    _endJunction=&endJunction;
    _length=length;
    _baseSpeed=0;
    _noOfCars=0;
    _timeSlice=_endJunction->getTimeSlice();
    _maxSpeed=maxSpeed;
    _carsWaitingForGreenLight=0;
}

Road::~Road() {
    std::cout << "Road deleted"<< std::endl;
}
Junction* Road::getSJunc(){
    return _startingJunction;
}
Junction* Road::getEJunc(){
    return _endJunction;
}
int Road::getLen(){
    return _length;
}
void Road::baseSpeed(){
    _baseSpeed=std::min(_maxSpeed , (int)(ceil(_length/_noOfCars)));
}
int Road::getNoOfCars(){
    return _noOfCars;
}
void Road::removeFaultyCar(std::string carID){
    _faultyCarsOnRoad.erase(carID);
}
void Road::addCarToRoad(){
    _noOfCars++;
}

void Road::removeCarFromRoad() {
    _noOfCars--;
}


std::map<std::string,int> Road::getFaultyCarsOnRoad() {
    return _faultyCarsOnRoad;

}

int Road::getBaseSpeed() {
    return _baseSpeed;
}

void Road::addCarToWaitingList(Car* car) {
    _waitingForGreenLightList.push(car);
    _carsWaitingForGreenLight=1;
}

int Road::getCarsWaitingForGreenLight() {
    return _carsWaitingForGreenLight;
}

void Road::setCarsWaitingForGreenLight() {
    _carsWaitingForGreenLight=0;
}

int Road::removeCarFromWaitingList() {
    int i=0;
    if(_waitingForGreenLightList.front()->setNextRoad()==1){
        i=1; //remove car from cars map
    }
    _waitingForGreenLightList.pop();
    return i;
    
}

Car* Road::getCarToRemove() {
    return _carToRemove;
}


void Road::addFaultyCar(std::string carID,int distance) {
    _faultyCarsOnRoad[carID]=distance;
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

std::queue<Car*> Road::getWaitingList() {
    return _waitingForGreenLightList;
}

std::string Road::getWaitingCarList() {
    std::string currentList;  
    std::queue<Car*> currentWaintingList;
    for(int i=0; i<_waitingForGreenLightList.size();i++){
        currentList + _waitingForGreenLightList.front()->getCarId();
        currentWaintingList.push(_waitingForGreenLightList.front());
        _waitingForGreenLightList.pop();
    }
    _WaitingCarList=currentList;
    _waitingForGreenLightList=currentWaintingList;
    return currentList;
}