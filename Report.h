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
    std::map<std::string, std::map<std::string, Road*>> *_roadMap;
    Report();
    Report(const std::string &reportID);
    virtual ~Report();
    virtual void writeReport()=0;
    void setCars(std::map<std::string, Car*> &cars);
    void setJunctions(std::map<std::string, Junction*> &junctions);
    void setRoadMap(std::map<std::string, std::map<std::string, Road*>> &roadMap);
    void writeReports();
    virtual std::string getReportId()=0;
    virtual std::string getReportType()=0;
private:
    

};

#endif	/* REPORT_H */

