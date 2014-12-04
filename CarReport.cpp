/* 
 * File:   CarReport.cpp
 * Author: chen
 * 
 * Created on November 15, 2014, 1:31 PM
 */

#include "CarReport.h"
#include <string>
#include <boost/property_tree/ini_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>

CarReport::CarReport() {
    
}
CarReport::CarReport(std::string &carID, int timeOfReport,std::string &typeOfReport, std::string  &reportId,boost::property_tree::ptree &pt,std::map<std::string, Car*> &cars){
    _carID=carID;
    _reportId=reportId;
    _timeOfReport=timeOfReport;
    _type=typeOfReport;
    *_cars=cars;
    *_pt=pt;
}

CarReport::CarReport(const std::string &carID, const std::string &history,int faultyTimeLeft ) {
        _carID=carID;
        _history=history;
        _faultyTimeLeft=faultyTimeLeft;
}

CarReport::~CarReport() {
        std::cout << "CarReport deleted"<< std::endl;

}
void CarReport::writeReport(){
    Car* car=_cars->find(_carID)->second;
    _carID=car->getCarId();
    _history=car->getHistory();
    _faultyTimeLeft=car->getRemainingTimeOfFault();
    _pt->put(_reportId.append(".carId"),_carID);
    _pt->put(_reportId.append(".history"),_history);
    _pt->put(_reportId.append(".faultyTimeLeft"),_faultyTimeLeft);
    
}

std::string CarReport::getReportId() {
    return _reportId;
            
}

std::string CarReport::getReportType() {
    return _type;
}

std::string CarReport::getCarId() {
    return _carID;
}

std::string CarReport::getFaultyTimeLeft() {
    return std::to_string(_faultyTimeLeft);
}

std::string CarReport::getHistory() {
    return _history;
}

void CarReport::setPTree(boost::property_tree::ptree& pt) {
    *_pt=pt;
}

boost::property_tree::ptree* CarReport::getPTree() {
    return _pt;

}
