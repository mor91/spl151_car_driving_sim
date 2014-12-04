/* 
 * File:   ini.h
 * Author: chen
 *
 * Created on November 17, 2014, 9:55 AM
 */
#ifndef INI_H_
#define INI_H_
 
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Report.h"
#include "Event.h"
#include "Road.h"
 
using namespace std;
 
class IniClass{
  
private:
    
public:
    IniClass();
    virtual ~IniClass();
    void readConfiguration() const;
    void readRoadMap(std::map<std::string, std::map<std::string,Road*>> &roadMap,std::map<std::string, Junction*> &junctionsMap) const;
    void readCommands(boost::property_tree::ptree &pt,std::map<std::string, Car*> &cars, std::map<int, std::vector<Report*>> &reportsMap ,std::map<std::string, std::map<std::string,Road*>> &roadMap ,std::map<std::string, Junction*> &junctionsMap) const;
    void readEvents(std::map<std::string, Car*> &cars,std::map<int, std::vector<Event*>> &eventsMap,std::map<std::string, std::map<std::string,Road*>> &roadMap) const;
    void writeReports(Report &report) const;
    int getMaxSpeed();
    int getDefaultTimeSlice();
    int getMaxTimeSlice();
    int getMinTimeSlice();
    int getTerminationTime();
    int getCarCounter();
};
 
#endif /* INI_H_ */