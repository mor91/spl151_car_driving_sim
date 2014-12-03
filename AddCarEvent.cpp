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

AddCarEvent::AddCarEvent(int time, std::string const &carID ,std::map<int, Road*> const roadPlan) {
    _time=time;
    _carID=carID;
    _roadPlan=roadPlan;
}

AddCarEvent::~AddCarEvent() {
        std::cout << "AddCarEvent deleted"<< std::endl;

}

void AddCarEvent::performEvent(){
    Car* car=new Car(_carID,_roadPlan);
    _roadPlan[0]->addCarToRoad();
}

