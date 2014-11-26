/* 
 * File:   AddCarEvent.cpp
 * Author: mor
 * 
 * Created on November 15, 2014, 1:27 PM
 */

#include "AddCarEvent.h"
#include "Event.h"
#include <iostream>


AddCarEvent::AddCarEvent() {
}

AddCarEvent::AddCarEvent(int time, std::string const &carID ,std::string const &roadPlan) {
    _time=time;
    _carID=carID;
    _roadPlan=roadPlan;
}

AddCarEvent::~AddCarEvent() {
    
}

void AddCarEvent::performEvent(){
    
    
}

