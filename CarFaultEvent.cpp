/* 
 * File:   CarFaultEvent.cpp
 * Author: chen
 * 
 * Created on November 15, 2014, 1:30 PM
 */

#include "CarFaultEvent.h"
#include "Event.h"
#include "Road.h"
#include "Car.h"

CarFaultEvent::CarFaultEvent() {
}

CarFaultEvent::CarFaultEvent(int time, const std::string carId, int timeOfFault ) {
    _time=time;
    //*_car=car;
    _timeOfFault=timeOfFault;
}

CarFaultEvent::~CarFaultEvent() {
}

void CarFaultEvent::performEvent(){
    //_car->getCurrentRoad()->addFaultyCar(*_car);
    _car->setRemainingTimeToFault(_timeOfFault);
}

void CarFaultEvent::setCarsMap(std::map<std::string, Car*>& carsMap) {
    _carsMap=carsMap;
}


