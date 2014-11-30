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
    /*std::string carsWaitingList;
    Junction* junction=_junctions->find(_junction.getId())->second;
    int i=0;
    for(int i=0; i<junction->_inComingRoads.size();i++){
        i=0;
        if(junction->_greenForRoad->getSJunc().getId().compare(junction->_inComingRoads[i])==0)
            i=junction->getCurrentTimeSlice();
        else i=-1;
        _timeSlices.append("(").append(junction->_inComingRoads[i]->getTimeSlice()).append(",").append(std::to_string(i)).append(")");
        std::queue<*Car> waitingListQ= junction->_inComingRoads[i]->getWaitingList();
        for(intj=0,j<waitingListQ.size();j++){
            carsWaitingList.append(waitingListQ.front().getId());
            
        }
        _junctionsWaitingCars.insert(std::pair<std::string,std::string>(_junctions->find(_junction.getId())->second->_inComingRoads[i]->getSJunc(),))
     }*/
}

