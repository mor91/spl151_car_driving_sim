/* 
 * File:   Report.h
 * Author: chen
 *
 * Created on November 15, 2014, 11:45 AM
 */

#ifndef REPORT_H
#define	REPORT_H
#include <string>
#include <map>
#include <vector>
#include "Car.h"
#include "Junction.h"
#include "Road.h"

class Report {
    std::string _reportID;
public:
    std::vector<Report*> _reoprts;
    std::map<std::string, Car*> *_cars;
    std::map<std::string, Junction*> *_junctions;
    std::map<Junction*, std::map<Junction*,Road*>> *_roadMap;
    Report();
    Report(const std::string &reportID);
    virtual ~Report();
    virtual void writeReport()=0;
    std::map<std::string, Car*> setCars(std::map<std::string, Car*> &cars);
    std::map<std::string, Junction*> setJunctions(std::map<std::string, Junction*> &junctions);
    std::map<Junction*, std::map<Junction*,Road*>> setRoadMap(std::map<Junction*, std::map<Junction*,Road*>> &roadMap);
private:
    

};

#endif	/* REPORT_H */

