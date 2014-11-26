/* 
 * File:   CarReport.cpp
 * Author: chen
 * 
 * Created on November 15, 2014, 1:31 PM
 */

#include "CarReport.h"

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
    
}

