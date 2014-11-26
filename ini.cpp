/* 
 * File:   ini.cpp
 * Author: chen
 * 
 * Created on November 17, 2014, 9:55 AM
 */
#include "ini.h"
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
using namespace std;
int terminationTime;
int MAX_SPEED;
int DEFAULT_TIME_SLICE;
int MAX_TIME_SLICE;
int MIN_TIME_SLICE;
 
IniClass::IniClass(){}
 
IniClass::~IniClass() {}
 
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
std::vector<Road> IniClass::readRoadMap() const{
    cout << "Starting readRoadMap" << endl;
    std::vector<Road> roadMap;
    boost::property_tree::ptree pt;
    boost::property_tree::ini_parser::read_ini("RoadMap.ini", pt);
     for (auto& section : pt)
    {
        std::cout << '[' << section.first << "]\n";
        for (auto& key : section.second)
        {
            std::cout << key.first << "=" << key.second.get_value<std::string>() << "\n";
            Road* road=new Road(section.first,key.first,key.second.get_value<int>());
            roadMap.push_back( *road);
            
        }
        
        
    }
   // for(auto& keyPair : roadMap)
    //    std::cout << "road:"<<keyPair.first <<":" << keyPair.second.getSJunc()<<", "<<keyPair.second.getEJunc() <<", "<<keyPair.second.getLen()<< endl;
    return roadMap;
}
std::map<int, std::vector<Report*>> IniClass::readCommands() const{
    cout << "Starting readCommands" << endl;
    boost::property_tree::ptree pt;
    boost::property_tree::ini_parser::read_ini("Commands.ini", pt);
    std::map<int, std::vector<Report*>> reportMap;
    for (auto& section : pt)
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
                time=key.second.get_value<std::string>();
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
           Report *carReport=new CarReport(carId, id, stoi(time));
           reportMap[stoi(time)].push_back(carReport);
        }
        if(type=="road_report"){
            Report *roadReport=new RoadReport(startJunction, endJunction, stoi(time));
            reportMap[stoi(time)].push_back(roadReport);
        }
        if(type=="junction_report"){
            Junction junction(junctionId);
            Report *junctionReport=new JunctionReport(junction, stoi(time));
            reportMap[stoi(time)].push_back(junctionReport);
        }
            
        
            
     }
           
    return reportMap;
    
}
std::map<int, vector<Event*>> IniClass::readEvents() const{
   cout << "Starting readEvents" << endl;
    boost::property_tree::ptree pt;
    boost::property_tree::ini_parser::read_ini("Events", pt);
    std::map<int, std::vector<Event*>> eventsMap;
    for (auto& section : pt)
     {
        std::string type;
        std::string time;
        std::string carId;
        std::string roadPlan;
        std::string timeOfFault;
        
    
        std::cout << '[' << section.first << "]\n";
        for (auto& key : section.second)
        {
            std::cout << key.first << "=" << key.second.get_value<std::string>() << "\n";
            if(key.first=="type")
                type=key.second.get_value<std::string>();
            if(key.first=="time")
                time=key.second.get_value<std::string>();
            if(key.first=="carId")
                carId=key.second.get_value<std::string>();
            if(key.first=="roadPlan")
                roadPlan=key.second.get_value<std::string>();
            if(key.first=="timeOfFault")
                timeOfFault=key.second.get_value<std::string>();
          
        }
        if(type=="car_arrival"){
           Event *carArrivel=new AddCarEvent(stoi(time),carId, roadPlan);
           eventsMap[stoi(time)].push_back(carArrivel);//maybe we need to init the inner vector
        }
        if(type=="car_fault"){
            Event *carFault=new CarFaultEvent(stoi(time), carId ,stoi(timeOfFault) );
            eventsMap[stoi(time)].push_back(carFault);///maybe we need to init the inner vector
        } 
        
        
        
     }
           
    return eventsMap;

 
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
 
