/* 
 * File:   AddCarEvent.cpp
 * Author: mor
 * 
 * Created on November 15, 2014, 1:27 PM
 */

#include "AddCarEvent.h"
#include "Event.h"
#include "Car.h"
#include "Road.h"
#include <iostream>
#include <map>


AddCarEvent::AddCarEvent() {
}

AddCarEvent::AddCarEvent(int time, std::string const &carID ,std::map<int, Road*> const roadPlan,std::map<std::string, Car*> &cars) {
    _time=time;
    _roadPlan=roadPlan;
    _car=new Car(carID, _roadPlan);
    *_carsMap=cars;
}

AddCarEvent::~AddCarEvent() {
        std::cout << "AddCarEvent deleted"<< std::endl;

}

void AddCarEvent::performEvent(){
       _roadPlan[0]->addCarToRoad();
       _carsMap->insert(std::pair<std::string, Car*>(_car->getCarId(), _car));

}

