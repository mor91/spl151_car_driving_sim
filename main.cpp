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
#include <boost/property_tree/ini_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>

using namespace std;


int main(int argc, char** argv) {    
    std::map<std::string, Car*>* cars;
    boost::property_tree::ptree *pt;
    std::map<int, std::vector<Report*>>* reportsMap;//=a.readCommands(*pt, *cars);
    std::map<int, std::vector<Event*>>* eventsMap;//=a.readEvents(*cars);
    std::map<std::string, Junction*> *junctuons;//=a.getJunctionsMap();
    std::map<std::string, std::map<std::string,Road*>>* roadMap;//=a.readRoadMap();
    IniClass a;
    a.readConfiguration();
    
    int const MAX_SPEED=a.getMaxSpeed();
    int const DEFAULT_TIME_SLICE=a.getDefaultTimeSlice();
    int const MAX_TIME_SLICE=a.getMaxTimeSlice();
    int const MIN_TIME_SLICE=a.getMinTimeSlice();
    int finishedCarsCounter=0;
    a.readCommands(*pt, *cars,*reportsMap, *roadMap ,*junctuons);
    a.readEvents(*cars,*eventsMap , *roadMap);
    //a.getJunctionsMap();
    a.readRoadMap(*roadMap, *junctuons);
    
    
    

    int const TERMINATION=a.getTerminationTime();
    
    int time=0;
    int simulationRunning=1;
    //junc->setConsts(DEFAULT_TIME_SLICE,MAX_TIME_SLICE,MIN_TIME_SLICE);
    int carArrivalCounter=a.getCarCounter();
    
    while(simulationRunning){
        if(eventsMap->find(time)!=eventsMap->end()){
            for(auto& timeUnit:eventsMap[time]){
                for(auto& event:timeUnit.second){
                    event->performEvent();                       
                }
            
            }
        } 
        if(reportsMap->find(time)!=reportsMap->end()){
            for(auto& timeUnit:reportsMap[time]){
                for(auto& report:timeUnit.second){
                    report->writeReport();
                }
            }
        }
        for(auto& car:*cars){
            car.second->advanceCar(time);
        }
        for(auto& junc:*junctuons){
            std::string carToRemove=junc.second->setGreenForIncomingJunction();
            cars->erase(carToRemove);
            cars->find(carToRemove)->second->~Car();
            finishedCarsCounter++;
        }
        
        time++;
        if(time==TERMINATION || finishedCarsCounter== carArrivalCounter){
            simulationRunning=0;
        }
    }
    boost::property_tree::write_ini("Reports", *pt);
    for(auto& key:*junctuons){
        key.second->~Junction();
    }
    for(auto& key:*roadMap){
        for(auto& inkey:key.second){
            inkey.second->~Road();           
        }
        
    }
    for(auto& key:*cars){
        key.second->~Car();
    }
    for(auto& key:*eventsMap){
        for(auto& inKey:key.second){
            inKey->~Event();
        }
    }
    for(auto& key:*reportsMap){
        for(auto& inkey:key.second){
            inkey->~Report();
        }
        
    
}
}
