/* 
 * File:   JunctionReport.cpp
 * Author: chen
 * 
 * Created on November 15, 2014, 1:33 PM
 */

#include "JunctionReport.h"
#include "Junction.h"

JunctionReport::JunctionReport() {
}

JunctionReport::JunctionReport(Junction &junction, int time){
    _junction= junction;
    _time=time;
    
}

JunctionReport::JunctionReport(const Junction &junction, const std::string &timeSlices, const std::vector<std::string> &inComingJunctionID ) {
    _junction=junction;
    _timeSlices=timeSlices;
    _inComingJunctionID=inComingJunctionID;
    
}

JunctionReport::~JunctionReport() {
}
void JunctionReport::writeReport(){
    
}

