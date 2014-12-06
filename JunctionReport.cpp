/* 
 * File:   JunctionReport.cpp
 * Author: chen
 * 
 * Created on November 15, 2014, 1:33 PM
 */

#include "JunctionReport.h"
#include "Junction.h"
#include <string>
#include <map>
#include <iostream>
#include <boost/property_tree/ini_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>

JunctionReport::JunctionReport() {
}

JunctionReport::JunctionReport(Junction &junction, int time, std::string  &reportId,boost::property_tree::ptree &pt,std::map<std::string, Car*> &cars,std::map<std::string, Junction*> &junctionsMap){
    _junction= junction;
    _time=time;
    _reportId=reportId;
    _cars=&cars;
    _junctionsMap=&junctionsMap;
    _pt=&pt;
}

JunctionReport::JunctionReport(const Junction &junction, const std::string &timeSlices, const std::vector<std::string> &inComingJunctionID ) {
    _junction=junction;
    _timeSlices=timeSlices;
    _inComingJunctionID=inComingJunctionID;
    
}

JunctionReport::~JunctionReport() {
        std::cout << "JunctionReport deleted"<< std::endl;

}
void JunctionReport::writeReport(){
   std::string carsWaitingList;
    Junction* junction=_junctionsMap->find(_junction.getId())->second;
    int j=0;
    for(int i=0; i<junction->getInComingRoads().size();i++){
        j=0;
        if(junction->getGreenForRoad()->getSJunc()->getId().compare(junction->getInComingRoads()[i]->getSJunc()->getId())==0)
            j=junction->getInComingRoads()[i]->getTimeSlice()-junction->getCurrentTimeSlice();
        else j=-1;
        _timeSlices.append("(").append(std::to_string(junction->getInComingRoads()[i]->getTimeSlice())).append(",").append(std::to_string(j)).append(")");
        _junctionsWaitingCars.insert(std::pair<std::string,std::string>(junction->getInComingRoads()[i]->getSJunc()->getId(),junction->getInComingRoads()[i]->getWaitingCarList()));
    }
    _pt->put(_reportId.append(".junctionId"),_junction.getId());
    _pt->put(_reportId.append(".timeSlices"), _timeSlices);
    for(int i=0; i<junction->getInComingRoads().size();i++){
        std::string juncId=junction->getInComingRoads()[i]->getSJunc()->getId();
        std::string carsWaiting=junction->getInComingRoads()[i]->getWaitingCarList();
        _pt->put(_reportId.append(".").append(juncId), carsWaiting);
    }
}

std::string JunctionReport::getReportId() {
    return _reportId;
            
}

std::string JunctionReport::getReportType() {
    return _type;
}

std::vector<std::string> JunctionReport::getInComingJunctions() {
    return _inComingJunctionID;
}

std::string JunctionReport::getJunctionId() {
    return _junction.getId();
}

std::string JunctionReport::getTimeSlices() {
    return _timeSlices;
}
