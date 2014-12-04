/* 
 * File:   JunctionReport.h
 * Author: chen
 *
 * Created on November 15, 2014, 1:33 PM
 */

#ifndef JUNCTIONREPORT_H
#define	JUNCTIONREPORT_H
#include <string>
#include <vector>

#include "Report.h"
#include "Junction.h"
#include <vector>
#include <map>
#include <boost/property_tree/ini_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>


class JunctionReport:public Report {
    Junction _junction;
    std::string _timeSlices;
    std::vector<std::string> _inComingJunctionID;
    int _time;
    std::string _reportId;
    std::map<std::string,std::string> _junctionsWaitingCars;
    std::string _type;
    boost::property_tree::ptree* _pt;
    std::map<std::string, Junction*>* _junctionsMap;
    std::map<std::string, Car*>* _cars;
public:
    JunctionReport();
    JunctionReport(Junction &junction, int time,std::string &typeOfReport, std::string  &reportId,boost::property_tree::ptree &pt,std::map<std::string, Car*> &cars, std::map<std::string, Junction*> &junctionsMap);
    JunctionReport(const Junction &junction, const std::string &timeSlices, const std::vector<std::string> &inComingJunctionID );
    virtual ~JunctionReport();
    void writeReport();
    std::string getReportId();
    std::string getReportType();
    std::string getJunctionId();
    std::string getTimeSlices();
    std::vector <std::string> getInComingJunctions();

    virtual void setPTree(boost::property_tree::ptree& pt);

    virtual boost::property_tree::ptree* getPTree();


};

#endif	/* JUNCTIONREPORT_H */

