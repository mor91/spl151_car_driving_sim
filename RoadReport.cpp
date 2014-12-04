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

RoadReport::RoadReport(std::string &startJunction, std::string &endJunction, int time,std::string &typeOfReport, std::string & reportId,boost::property_tree::ptree &pt,std::map<std::string, Car*> &cars,std::map<std::string, std::map<std::string,Road*>> &roadMap,std::map<std::string, Junction*> &junctionsMap){
    *_junctionsMap=junctionsMap;
    _startJunction=_junctionsMap->find(startJunction)->second;
    _endJunction=_junctionsMap->find(endJunction)->second;
    _time=time;
    _reportId=reportId;
    _type=typeOfReport;
    *_cars=cars;
    *_roadMap=roadMap;
    *_pt=pt;
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
    for(auto& car: *_cars){
        if(car.second->getCurrentRoad()->getSJunc().getId().compare(road->getSJunc().getId())&&car.second->getCurrentRoad()->getEJunc().getId().compare(road->getEJunc().getId())){
           _carsList=_carsList.append("(").append(car.second->getCarId()).append(",").append(std::to_string(car.second->getDistanceFromBeginningOfRoad())).append(")");
        }
        
    }
    *_startJunction=road->getSJunc();
    *_endJunction=road->getEJunc();
    _pt->put(_reportId.append(".startJunction"),_startJunction->getId());
    _pt->put(_reportId.append(".endJunction"),_endJunction->getId());
    _pt->put(_reportId.append(".cars"),_carsList);
}

std::string RoadReport::getReportId() {
    return _reportId;
}

std::string RoadReport::getReportType() {
    return _type;
}

void RoadReport::setPTree(boost::property_tree::ptree& pt) {
    *_pt=pt;
}

boost::property_tree::ptree* RoadReport::getPTree() {
    return _pt;
}
