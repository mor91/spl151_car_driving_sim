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
    Junction _startJunction;
    Junction _endJunction;
    std::string _carsList;
    std::string _reportId;
    int _time;
    std::string _type;
    boost::property_tree::ptree* _pt;
public:
    RoadReport();
    RoadReport(std::string& startJunction, std::string& endJunction, int time,std::string& typeOfReport, std::string & reportId);
    RoadReport(const std::string &startJunction, const std::string &endJunction, const std::string &carsList );
    virtual ~RoadReport();
    void writeReport();
    std::string getReportId();
    std::string getReportType();

    virtual void setPTree(boost::property_tree::ptree& pt);

    virtual boost::property_tree::ptree* getPTree();


private:

};

#endif	/* ROADREPORT_H */

