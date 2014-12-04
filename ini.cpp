/* 
 * File:   ini.cpp
 * Author: chen
 * 
 * Created on November 17, 2014, 9:55 AM
 */
#include "ini.h"
#include "Junction.h"
#include "Road.h"
#include "Event.h"
#include "Report.h"
#include "CarReport.h"
#include "RoadReport.h"
#include "JunctionReport.h"
#include "AddCarEvent.h"
#include "CarFaultEvent.h"
#include <iostream>
#include <map> 
#include <vector>
#include <boost/property_tree/ini_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>

using namespace std;
int terminationTime;
int MAX_SPEED;
int DEFAULT_TIME_SLICE;
int MAX_TIME_SLICE;
int MIN_TIME_SLICE;
int carCounter=0;

IniClass::IniClass(){}
 
IniClass::~IniClass() {
        std::cout << "IniClass deleted"<< std::endl;

}
 
void IniClass::readConfiguration() const{
  cout << "Starting readConfiguration" << endl;
  boost::property_tree::ptree pt;
  boost::property_tree::ini_parser::read_ini("Configuration.ini", pt);
  MAX_SPEED = pt.get<int>("Configuration.MAX_SPEED");
  DEFAULT_TIME_SLICE = pt.get<int>("Configuration.DEFAULT_TIME_SLICE");
  MAX_TIME_SLICE = pt.get<int>("Configuration.MAX_TIME_SLICE");
  MIN_TIME_SLICE = pt.get<int>("Configuration.MIN_TIME_SLICE");
  std::cout << "MAX_SPEED = " << MAX_SPEED << endl;
  std::cout << "DEFAULT_TIME_SLICE = " << DEFAULT_TIME_SLICE << endl;
  std::cout << "MAX_TIME_SLICEE = " << MAX_TIME_SLICE << endl;
  std::cout << "MIN_TIME_SLICEE = " << MIN_TIME_SLICE << endl;
  
  

}

void IniClass::readRoadMap(std::map<std::string, std::map<std::string, Road*> >& roadMap, std::map<std::string, Junction*>& junctionsMap) const {
    cout << "Starting readRoadMap" << endl;
    boost::property_tree::ptree pt;
    boost::property_tree::ini_parser::read_ini("RoadMap.ini", pt);
     for (auto& section : pt)
    {   
        Junction* startJunction=new Junction(section.first,  DEFAULT_TIME_SLICE, MAX_TIME_SLICE, MIN_TIME_SLICE);
        junctionsMap.insert(pair<std::string , Junction*>(startJunction->getId(),startJunction));
        std::cout << '[' << section.first << "]\n";
        for (auto& junc : section.second)
        {
            Junction* endJunction;
            std::cout << junc.first << "=" << junc.second.get_value<std::string>() << "\n";
            if(junctionsMap.find(junc.first)==junctionsMap.end()){
                endJunction=new Junction(junc.first,DEFAULT_TIME_SLICE, MAX_TIME_SLICE, MIN_TIME_SLICE);
            }
            else  endJunction=junctionsMap.find(junc.first)->second;
            Road* road=new Road(*startJunction,*endJunction ,junc.second.get_value<int>());
            roadMap[startJunction->getId()].insert(pair<std::string,Road*>(endJunction->getId(),road));
            startJunction->setInComingRoads(*road);
        }
        
        
    }
   // for(auto& keyPair : roadMap)
    //    std::cout << "road:"<<keyPair.first <<":" << keyPair.second.getSJunc()<<", "<<keyPair.second.getEJunc() <<", "<<keyPair.second.getLen()<< endl;
}

void IniClass::readCommands(boost::property_tree::ptree& pt, std::map<std::string, Car*>& cars, std::map<int, std::vector<Report*> >& reportsMap, std::map<std::string, std::map<std::string,Road*>> & roadMap,std::map<std::string, Junction*> &junctionsMap) const {
    cout << "Starting readCommands" << endl;
    boost::property_tree::ptree ptIn;
    boost::property_tree::ini_parser::read_ini("Commands.ini", ptIn);
    std::map<int, std::vector<Report*>> reportMap;
    for (auto& section : ptIn)
     {
        std::string type;
        std::string time;
        std::string id;
        std::string carId;
        std::string startJunction;
        std::string endJunction;
        std::string junctionId;
        
    
        std::cout << '[' << section.first << "]\n";
        for (auto& key : section.second)
        {
            std::cout << key.first << "=" << key.second.get_value<std::string>() << "\n";
            if(key.first=="type")
                type=key.second.get_value<std::string>();
            if(key.first=="time")
                time=key.second.get_value<std::string>();
            if(key.first=="id")
                id=key.second.get_value<std::string>();
            if(key.first=="carId")
                carId=key.second.get_value<std::string>();
            if(key.first=="startJunction")
                startJunction=key.second.get_value<std::string>();
            if(key.first=="endJunction")
                endJunction=key.second.get_value<std::string>();
            if(key.first=="junctionId")
                junctionId=key.second.get_value<std::string>();
        
       
            
            
        }
        
        if(type=="termination"){
           //std::cout<< "termination time=" << time << endl;
           terminationTime=stoi(time);
        }    
        if(type=="car_report"){
           Report *carReport=new CarReport(carId, stoi(time), type,id,pt,cars);
           reportsMap[stoi(time)].push_back(carReport);
        }
        if(type=="road_report"){
            Report *roadReport=new RoadReport(startJunction, endJunction, stoi(time),type,id,pt, cars, roadMap, junctionsMap);
            reportsMap[stoi(time)].push_back(roadReport);
        }
        if(type=="junction_report"){
            Junction* junction=junctionsMap.find(junctionId)->second;
            Report *junctionReport=new JunctionReport(*junction, stoi(time), type, id,pt,cars,junctionsMap);
            reportsMap[stoi(time)].push_back(junctionReport);
        }
            
        
            
     }
           

    
}

void IniClass::readEvents(std::map<std::string, Car*>& cars, std::map<int, std::vector<Event*> >& eventsMap, std::map<std::string, std::map<std::string,Road*>> &roadMap) const {
    cout << "Starting readEvents" << endl;
    boost::property_tree::ptree pt;
    boost::property_tree::ini_parser::read_ini("Events.ini", pt);
    for (auto& section : pt) {
        std::string type;
        std::string time;
        std::string carId;
        std::string roadPlan;
        std::string timeOfFault;


        std::cout << '[' << section.first << "]\n";
        for (auto& key : section.second) {
            std::cout << key.first << "=" << key.second.get_value<std::string>() << "\n";
            if (key.first == "type")
                type = key.second.get_value<std::string>();
            if (key.first == "time")
                time = key.second.get_value<std::string>();
            if (key.first == "carId")
                carId = key.second.get_value<std::string>();
            if (key.first == "roadPlan")
                roadPlan = key.second.get_value<std::string>();
            if (key.first == "timeOfFault")
                timeOfFault = key.second.get_value<std::string>();

        }
        if (type == "car_arrival") {
            std::map<int, Road*> roadPlanMap;
            std::vector<std::string> roadPlanJunctions;
            boost::split(roadPlanJunctions,roadPlan,boost::is_any_of(","));
            for(int i=0; i<roadPlanJunctions.size()-1; i++){
                cout<<roadPlanJunctions[i]<<endl;
                        roadPlanMap.insert(std::pair<int, Road*>(i,roadMap.find(roadPlanJunctions[i])->second.find(roadPlanJunctions[i+1])->second));
                    }
            carCounter++;
            Event *carArrivel=new AddCarEvent(stoi(time),carId, roadPlanMap, cars);
            eventsMap[stoi(time)].push_back(carArrivel);//maybe we need to init the inner vector
        }
        if(type=="car_fault"){
            Event *carFault=new CarFaultEvent(stoi(time), carId ,stoi(timeOfFault),cars );
            eventsMap[stoi(time)].push_back(carFault);///maybe we need to init the inner vector
        } 
        
        
        
     }
           
    
}
           
    

 

void IniClass::writeReports(Report &report) const{
   /* boost::property_tree::ptree pt;
    pt.p
    pt.put_value(report);
    boost::property_tree::ini_parser::write_ini("Reports.ini",pt);*/
    
    
}
int IniClass::getMaxSpeed(){
    return MAX_SPEED;
}
int IniClass::getDefaultTimeSlice(){
    return DEFAULT_TIME_SLICE;
}
int IniClass::getMaxTimeSlice(){
    return MAX_TIME_SLICE;
}
int IniClass::getMinTimeSlice(){
    return MIN_TIME_SLICE;
}
int IniClass::getTerminationTime(){
    return terminationTime;
}



int IniClass::getCarCounter() {
    return carCounter;
}

