/* 
 * File:   RoadReport.cpp
 * Author: chen
 * 
 * Created on November 15, 2014, 1:32 PM
 */

#include "RoadReport.h"
#include "Car.h"
#include "Road.h"
#include <string>
#include <map>
#include <iostream>
RoadReport::RoadReport() {
}
RoadReport::RoadReport(std::string startJunction, std::string endJunction, int time){
    _startJunction=startJunction;
    _endJunction=endJunction;
    _time=time;
}

RoadReport::RoadReport(const std::string &startJunction, const std::string &endJunction, const std::string &carsList) {
    _startJunction=startJunction;
    _endJunction=endJunction;
    _carsList=carsList;
}

RoadReport::~RoadReport() {
}
void RoadReport::writeReport(){
    Road* road=_roadMap->find(_startJunction.getId())->second.find(_endJunction.getId())->second;
    for(auto& car: *_cars){
        if(car.second->getCurrentRoad()->getSJunc().getId().compare(road->getSJunc().getId())&&car.second->getCurrentRoad()->getEJunc().getId().compare(road->getEJunc().getId())){
           _carsList=_carsList.append("(").append(car.second->getCarId()).append(",").append(std::to_string(car.second->getDistanceFromBeginningOfRoad())).append(")");
        }
        
    }
    _startJunction=road->getSJunc();
    _endJunction=road->getEJunc();
    _reoprts.push_back(this);
}

