/* 
 * File:   Report.cpp
 * Author: chen
 * 
 * Created on November 15, 2014, 11:45 AM
 */

#include "Report.h"
#include "ini.h"
    

Report::Report() {

}

Report::Report(const std::string &reportID) {
    _reportID=reportID;
}

Report::~Report() {
}

std::map<std::string, Car*> Report::setCars(std::map<std::string, Car*> &cars) {
    *_cars=cars;
}

std::map<std::string, Junction*> Report::setJunctions(std::map<std::string, Junction*> &junctions) {
   *_junctions=junctions;
}

std::map<Junction*, std::map<Junction*, Road*> > Report::setRoadMap(std::map<Junction*, std::map<Junction*, Road*> > &roadMap) {
   *_roadMap=roadMap;
}



