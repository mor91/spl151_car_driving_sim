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
CarReport::CarReport(std::string &carID,std::string &reportId, int timeOfReport){
    _carID=carID;
    _reportId=reportId;
    _timeOfReport=timeOfReport;
}

CarReport::CarReport(const std::string &carID, const std::string &history,int faultyTimeLeft) {
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




