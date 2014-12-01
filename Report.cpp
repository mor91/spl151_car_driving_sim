/* 
 * File:   Report.cpp
 * Author: chen
 * 
 * Created on November 15, 2014, 11:45 AM
 */

#include "Report.h"
#include "ini.h"
#include <boost/property_tree/ini_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp> 

Report::Report() {

}

Report::Report(const std::string &reportID) {
    _reportID=reportID;
}

Report::~Report() {
}

void Report::setCars(std::map<std::string, Car*> &cars) {
    *_cars=cars;
}

void Report::setJunctions(std::map<std::string, Junction*> &junctions) {
   *_junctions=junctions;
}

void Report::setRoadMap(std::map<std::string, std::map<std::string, Road*>> &roadMap) {
   *_roadMap=roadMap;
}

void Report::writeReports() {
    
}


