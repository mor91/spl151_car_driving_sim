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
    std::map<std::string, Car*> cars;
    boost::property_tree::ptree pt;
    
    std::map<int, std::vector<Report*> > reportsMap;//=a.readCommands(*pt, *cars);
    std::map<int, std::vector<Event*> > eventsMap;//=a.readEvents(*cars);
    std::map<std::string, Junction*> junctions;//=a.getJunctionsMap();
    std::map<std::string, std::map<std::string,Road*> > roadMap;//=a.readRoadMap();
    IniClass a;
    a.readConfiguration();
    
    int const MAX_SPEED=a.getMaxSpeed();
    int const DEFAULT_TIME_SLICE=a.getDefaultTimeSlice();
    int const MAX_TIME_SLICE=a.getMaxTimeSlice();
    int const MIN_TIME_SLICE=a.getMinTimeSlice();
    int finishedCarsCounter=0;
    a.readRoadMap(roadMap, junctions);
    a.readCommands(pt, cars,reportsMap, roadMap ,junctions);
    a.readEvents(cars,eventsMap , roadMap);
    //a.getJunctionsMap();


    int const TERMINATION=a.getTerminationTime();
    
    int time=0;
    int simulationRunning=1;
    //junc->setConsts(DEFAULT_TIME_SLICE,MAX_TIME_SLICE,MIN_TIME_SLICE);
    int carArrivalCounter=a.getCarCounter();
    
    while(simulationRunning){
        if(eventsMap.find(time)!=eventsMap.end()){
            //for(auto& event:eventsMap[time]){
            for(std::vector<Event*>::iterator event = eventsMap[time].begin();event!=eventsMap[time].end();event++){
                    (*event)->performEvent();                      
            }
        } 
        if(reportsMap.find(time)!=reportsMap.end()){
            for(std::vector<Report*>::iterator report = reportsMap[time].begin();report!=reportsMap[time].end();report++)
            {
            //for(auto& report:reportsMap[time]){
                    (*report)->writeReport();
            }
        }
        for(std::map<std::string,Car*>::iterator car = cars.begin();car!=cars.end();car++){
        //for(auto& car:cars){
            car->second->advanceCar(time);
        }
        //for(auto& junc:junctions){
        for(std::map<std::string,Junction*>::iterator junc = junctions.begin();junc!=junctions.end();junc++){
            if(junc->second->setGreenForIncomingJunction()==1){
                std::string carToRemove=junc->second->getCarToRemove();
                cars.erase(carToRemove);
                cars.find(carToRemove)->second->~Car();
                finishedCarsCounter++;
            }
        }
        
        time++;
        if(time==TERMINATION || finishedCarsCounter== carArrivalCounter){
            simulationRunning=0;
        }
    }
    
    std::cout << "writing ini.....";
    boost::property_tree::write_ini("Reports_output.ini", pt);
    std::cout << "done" << std::endl;
    
    for(std::map<std::string,Junction*>::iterator junc = junctions.begin();junc!=junctions.end();junc++){
        junc->second->~Junction();
    }
    
    //for(auto& key:roadMap){
    for(std::map<std::string, std::map<std::string,Road*> >::iterator key = roadMap.begin();key!=roadMap.end();key++){
        //for(auto& inkey:key.second){
        for(std::map<std::string,Road*>::iterator inkey = key->second.begin();inkey!=key->second.end();inkey++){
            inkey->second->~Road();           
        }
        
    }
    
    //for(auto& key:cars){
    for(std::map<std::string, Car*>::iterator key = cars.begin();key!=cars.end();key++){
        key->second->~Car();
    }
    
    //for(auto& key:eventsMap){
    for(std::map<int, std::vector<Event*> >::iterator key=eventsMap.begin();key!=eventsMap.end();key++){
        //for(auto& inKey:key->second){
        for(std::vector<Event*>::iterator inkey = key->second.begin() ; inkey!=key->second.end();inkey++){
            (*inkey)->~Event();
        }
    }
    
    //for(auto& key:reportsMap){
    for(std::map<int, std::vector<Report*> >::iterator key=reportsMap.begin();key!=reportsMap.end();key++){
        for(std::vector<Report*>::iterator inkey = key->second.begin() ; inkey!=key->second.end();inkey++){
            (*inkey)->~Report();
        }
    }
}
