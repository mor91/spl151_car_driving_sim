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
#include <boost/property_tree/ini_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>

class Report {
    std::string _reportID;
    boost::property_tree::ptree _pt;
public:
    Report();
    Report(const std::string &reportID);
    virtual ~Report();
    virtual void writeReport()=0;
    void writeReports();
    virtual std::string getReportId()=0;
    virtual std::string getReportType()=0;
private:
    

};

#endif	/* REPORT_H */

