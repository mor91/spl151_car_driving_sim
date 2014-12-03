/* 
 * File:   CarReport.h
 * Author: chen
 *
 * Created on November 15, 2014, 1:31 PM
 */

#ifndef CARREPORT_H
#define	CARREPORT_H
#include <string>
#include "Report.h"
#include <boost/property_tree/ini_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>

class CarReport:public Report {
    std::string _carID;
    std::string _history;
    int _faultyTimeLeft;
    std::string _reportId;
    int _timeOfReport;
    std::string _type;
    boost::property_tree::ptree* _pt;
public:
    CarReport();
    CarReport(std::string &carID, int timeOfReport ,std::string& typeOfReport, std::string  &reportId);
    CarReport(const std::string &carID, const std::string &history,int faultyTimeLeft);
    void writeReport();
    virtual ~CarReport();
    std::string getReportId();
    std::string getReportType();
    std::string getCarId();
    std::string getHistory();
    std::string getFaultyTimeLeft();

    virtual void setPTree(boost::property_tree::ptree& pt);

    virtual boost::property_tree::ptree* getPTree();

private:

};

#endif	/* CARREPORT_H */

