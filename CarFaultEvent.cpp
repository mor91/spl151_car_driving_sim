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

CarFaultEvent::CarFaultEvent(int time, const std::string carId, int timeOfFault,std::map<std::string, Car*> &cars) {
    _time=time;
    _carsMap=cars;
    _carID = carId;
    _timeOfFault=timeOfFault;
}

CarFaultEvent::~CarFaultEvent() {
        std::cout << "CarFaultEvent deleted"<< std::endl;

}

void CarFaultEvent::performEvent(){
    _carsMap[_carID]->getCurrentRoad()->addFaultyCar(_carID);
    _carsMap[_carID]->setRemainingTimeToFault(_timeOfFault);
}




