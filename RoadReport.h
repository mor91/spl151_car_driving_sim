/* 
 * File:   RoadReport.h
 * Author: chen
 *
 * Created on November 15, 2014, 1:32 PM
 */

#ifndef ROADREPORT_H
#define	ROADREPORT_H

#include "Report.h"
#include <boost/property_tree/ini_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>

class RoadReport:public Report {
    Junction *_startJunction;
    Junction *_endJunction;
    std::string _carsList;
    std::string _reportId;
    int _time;
    std::string _type;
    boost::property_tree::ptree* _pt;
    std::map<std::string, std::map<std::string,Road*> >* _roadMap;
    std::map<std::string, Car*> *_cars;
    std::map<std::string, Junction*> *_junctionsMap;
public:
    RoadReport();
    RoadReport(std::string& startJunction, std::string& endJunction, int time, std::string & reportId,boost::property_tree::ptree &pt,std::map<std::string, Car*> &cars, std::map<std::string, std::map<std::string,Road*> > & roadMap,std::map<std::string, Junction*> &junctionsMap);
    RoadReport(const std::string &startJunction, const std::string &endJunction, const std::string &carsList );
    virtual ~RoadReport();
    void writeReport();
    std::string getReportId();
    std::string getReportType();


private:

};

#endif	/* ROADREPORT_H */

