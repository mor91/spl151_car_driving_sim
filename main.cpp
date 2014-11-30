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

int main(int argc, char** argv) {    
    IniClass a;
    a.readConfiguration();
    
    int const MAX_SPEED=a.getMaxSpeed();
    int const DEFAULT_TIME_SLICE=a.getDefaultTimeSlice();
    int const MAX_TIME_SLICE=a.getMaxTimeSlice();
    int const MIN_TIME_SLICE=a.getMinTimeSlice();
    
    std::map<Junction*, std::map<Junction*,Road*>> roadMap=a.readRoadMap();
    std::map<int, std::vector<Report*>> reportsMap=a.readCommands();
    std::map<int, std::vector<Event*>> eventsMap=a.readEvents();
    std::map<std::string, Car*> cars;//get on implementation time of CarArrivalEvent
    std::map<std::string, Junction*> junctuons=a.getJunctionsMap();
    
    int time=0;
    int simulationRunning=1;
    Report* rep=new CarReport();
    rep->setJunctions(junctuons);
    rep->setRoadMap(roadMap);
    Junction* junc=new Junction();
    junc->setConsts(DEFAULT_TIME_SLICE,MAX_TIME_SLICE,MIN_TIME_SLICE);
    
    while(simulationRunning){
        junc->setTime(time);
        if(eventsMap.find(time)!=eventsMap.end()){
            for(auto& event:eventsMap[time]){
               a.setCarMap(cars);
               event->performEvent();
            }
        } 
        if(reportsMap.find(time)!=reportsMap.end()){
            for(auto& report:reportsMap[time]){
                rep->setCars(cars);
                report->writeReport();
            }
        }
        for(auto& car:cars){
            car.second->advanceCar(time);
        }
        for(auto& junc:junctuons){
            junc.second->setGreenForIncomingJunction();
        }
        time++;
    }
   
        
    
}

