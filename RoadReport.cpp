/* 
 * File:   RoadReport.cpp
 * Author: chen
 * 
 * Created on November 15, 2014, 1:32 PM
 */

#include "RoadReport.h"

RoadReport::RoadReport() {
}
RoadReport::RoadReport(std::string startJunction, std::string endJunction, int time){
    _startJunction=startJunction;
    _endJunction=endJunction;
    _time=time;
}

RoadReport::RoadReport(const std::string &startJunction, const std::string &endJunction, const std::string &cars) {
    _startJunction=startJunction;
    _endJunction=endJunction;
    _cars=cars;
}

RoadReport::~RoadReport() {
}
void RoadReport::writeReport(){
    
}

