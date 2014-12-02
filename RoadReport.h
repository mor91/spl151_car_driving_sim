/* 
 * File:   RoadReport.h
 * Author: chen
 *
 * Created on November 15, 2014, 1:32 PM
 */

#ifndef ROADREPORT_H
#define	ROADREPORT_H

#include "Report.h"


class RoadReport:public Report {
    Junction _startJunction;
    Junction _endJunction;
    std::string _carsList;
    std::string _reportId;
    int _time;
    std::string _type;
public:
    RoadReport();
    RoadReport(std::string& startJunction, std::string& endJunction, int time,std::string& typeOfReport, std::string & reportId);
    RoadReport(const std::string &startJunction, const std::string &endJunction, const std::string &carsList );
    virtual ~RoadReport();
    void writeReport();
    std::string getReportId();
    std::string getReportType();
private:

};

#endif	/* ROADREPORT_H */

