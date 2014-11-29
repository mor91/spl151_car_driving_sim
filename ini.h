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
    std::map<Junction*, std::map<Junction*,Road*>> readRoadMap() const;
    std::map<int, std::vector<Report*>> readCommands() const;
    std::map<int, vector<Event*>> readEvents() const;
    void writeReports(Report &report) const;
    int getMaxSpeed();
    int getDefaultTimeSlice();
    int getMaxTimeSlice();
    int getMinTimeSlice();
    int getTerminationTime();
    std::map<std::string, Junction*> getJunctionsMap();
    void setCarMap(std::map<std::string, Car*> cars);
};
 
#endif /* INI_H_ */