/* 
 * File:   Report.cpp
 * Author: chen
 * 
 * Created on November 15, 2014, 11:45 AM
 */

#include "Report.h"
#include "ini.h"
#include <map>
#include <vector>
#include <string>
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
    /*(auto& key:_cars){
        delete key.second;
        delete key.first;
    }
    for(auto& key:_junctions){
        delete key.second;
        delete key.first;
    }
    for(auto& key:_roadMap){
        for(auto inKey:key.second){
            delete inKey.second;
            delete inKey.first;    
        }
        delete key;
    }*/
        std::cout << "Report deleted"<< std::endl;
}

void Report::setCars(std::map<std::string, Car*> &cars) {
    _cars=&cars;
}

void Report::setJunctions(std::map<std::string, Junction*> &junctions) {
   _junctions=&junctions;
}

void Report::setRoadMap(std::map<std::string, std::map<std::string, Road*>> &roadMap) {
   _roadMap=&roadMap;
}

void Report::writeReports() {
    
    /*for(int i=0; i<_reoprts.size();i++){
        if(_reoprts[i]->getReportType()=="car_report"){
           std::string carId=_reoprts[i]->getCarId();
            std::string history=_reoprts[i]->getHistory();
            std::string faultyTimeLeft=_reoprts[i]->getFaultyTimeLeft
        }
        if(_reoprts[i]->getReportType()=="road_report"){
            
            
        }
        if(_reoprts[i]->getReportType()=="junction_report"){
            
        }
    }*/
}


