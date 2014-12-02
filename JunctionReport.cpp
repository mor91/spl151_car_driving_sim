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

JunctionReport::JunctionReport() {
}

JunctionReport::JunctionReport(Junction &junction, int time,std::string& typeOfReport, std::string  &reportId){
    _junction= junction;
    _time=time;
    _reportId=reportId;
    _type=typeOfReport;
}

JunctionReport::JunctionReport(const Junction &junction, const std::string &timeSlices, const std::vector<std::string> &inComingJunctionID ) {
    _junction=junction;
    _timeSlices=timeSlices;
    _inComingJunctionID=inComingJunctionID;
    
}

JunctionReport::~JunctionReport() {
}
void JunctionReport::writeReport(){
   std::string carsWaitingList;
    Junction* junction=_junctions->find(_junction.getId())->second;
    int i=0;
    for(int i=0; i<junction->_inComingRoads.size();i++){
        i=0;
        if(junction->_greenForRoad->getSJunc().getId().compare(junction->_inComingRoads[i]->getSJunc().getId())==0)
            i=junction->getCurrentTimeSlice();
        else i=-1;
        _timeSlices.append("(").append(std::to_string(junction->_inComingRoads[i]->getTimeSlice())).append(",").append(std::to_string(i)).append(")");
        _junctionsWaitingCars.insert(std::pair<std::string,std::string>(junction->_inComingRoads[i]->getSJunc().getId(),junction->_inComingRoads[i]->getWaitingCarList()));
     }
    _reoprts.push_back(this);
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
