/* 
 * File:   main.cpp
 * Author: chen
 *
 * Created on November 15, 2014, 11:42 AM
 */


#include <iostream>
#include <string>
#include "ini.h"
#include <vector>
#include <map>
#include "AddCarEvent.h"
#include "Car.h"
#include "CarFaultEvent.h"
#include "CarReport.h"
#include "Event.h"
#include "InComingJunction.h"
#include "Junction.h"
#include "JunctionReport.h"
#include "Report.h"
#include "Road.h"
#include "RoadReport.h"
#include <typeinfo>

using namespace std;

bool termination(int terminationTime, int time , std::map<int,Road> roads){
    if(time==terminationTime){
        return true;
    }
    int noOfCars=0;
    for(auto& valueRoad:roads ){
        noOfCars=+valueRoad.second.getNoOfCars();
        return noOfCars==0;
    }
    return false;
                
}

int main(int argc, char** argv) {    
    IniClass a;
    a.readConfiguration();
    int const MAX_SPEED=a.getMaxSpeed();
    int const DEFAULT_TIME_SLICE=a.getDefaultTimeSlice();
    int const MAX_TIME_SLICE=a.getMaxTimeSlice();
    int const MIN_TIME_SLICE=a.getMinTimeSlice();
    std::vector<Road> roadMap=a.readRoadMap();
    std::map<int, std::vector<Report*>> reportsMap=a.readCommands();
    std::map<int, std::vector<Event*>> eventsMap=a.readEvents();
    std::map<std::string, Car> cars;// sort by id
    std::map<std::string, Road> roads;// 
    std::map<std::string, Junction> junctuons;//sort by id
    for(auto& road:roadMap){
        //initializing roads
        //initializing junctions
    }
    int time=0;
    int simulationRunning=1;
    while(simulationRunning){
        if(eventsMap.find(time)!=eventsMap.end()){
            for(auto& event:eventsMap[time]){
               event->performEvent();
            }
        } 
        if(reportsMap.find(time)!=reportsMap.end()){
            for(auto& report:reportsMap[time]){
                report->writeReport();
            }
        }
        //advance cars- Car.advance function
        time++;
    }
   
        
    
}

