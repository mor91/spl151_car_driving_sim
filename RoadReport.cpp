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
#include <boost/property_tree/ini_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>
RoadReport::RoadReport() {
}

RoadReport::RoadReport(std::string &startJunction, std::string &endJunction, int time, std::string & reportId,boost::property_tree::ptree &pt,std::map<std::string, Car*> &cars,std::map<std::string, std::map<std::string,Road*> > &roadMap,std::map<std::string, Junction*> &junctionsMap){
    _junctionsMap=&junctionsMap;
    _startJunction=_junctionsMap->find(startJunction)->second;
    _endJunction=_junctionsMap->find(endJunction)->second;
    _time=time;
    _reportId=reportId;
    _cars=&cars;
    _roadMap=&roadMap;
    _pt=&pt;
}

RoadReport::RoadReport(const std::string &startJunction, const std::string &endJunction, const std::string &carsList) {
    /*_startJunction=startJunction;
    _endJunction=endJunction;
    _carsList=carsList;
*/}

RoadReport::~RoadReport() {
        std::cout << "RoadReport deleted"<< std::endl;

}
void RoadReport::writeReport(){
    Road* road=_roadMap->find(_startJunction->getId())->second.find(_endJunction->getId())->second;
    //for(auto& car: *_cars){
    for(std::map<std::string,Car*>::iterator car = _cars->begin();car!=_cars->end();car++){
        if(
                car->second->getCurrentRoad()->getSJunc()->getId().compare(road->getSJunc()->getId()) &&
                car->second->getCurrentRoad()->getEJunc()->getId().compare(road->getEJunc()->getId())
                )
        {
           _carsList=_carsList + "(" + car->second->getCarId() + "," + boost::lexical_cast<std::string>(car->second->getDistanceFromBeginningOfRoad()) + ")" ;
        }
        
    }
    _startJunction=road->getSJunc();
    _pt->put(_reportId + ".endJunction" ,_endJunction->getId());
    _endJunction=road->getEJunc();
    _pt->put(_reportId + ".startJunction",_startJunction->getId());
    _pt->put(_reportId + ".cars" ,_carsList);
}

std::string RoadReport::getReportId() {
    return _reportId;
}

std::string RoadReport::getReportType() {
    return _type;
}

