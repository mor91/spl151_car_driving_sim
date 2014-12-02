/* 
 * File:   CarReport.cpp
 * Author: chen
 * 
 * Created on November 15, 2014, 1:31 PM
 */

#include "CarReport.h"
#include <string>

CarReport::CarReport() {
    
}
CarReport::CarReport(std::string &carID, int timeOfReport,std::string &typeOfReport, std::string  &reportId){
    _carID=carID;
    _reportId=reportId;
    _timeOfReport=timeOfReport;
    _type=typeOfReport;
}

CarReport::CarReport(const std::string &carID, const std::string &history,int faultyTimeLeft ) {
        _carID=carID;
        _history=history;
        _faultyTimeLeft=faultyTimeLeft;
}

CarReport::~CarReport() {
}
void CarReport::writeReport(){
    Car* car=_cars->find(_carID)->second;
    _carID=car->getCarId();
    _history=car->getHistory();
    _faultyTimeLeft=car->getRemainingTimeOfFault();
    _reoprts.push_back(this);
    
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



