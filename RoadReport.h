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
    std::string _startJunction;
    std::string _endJunction;
    std::string _cars;
    std::string _reportId;
    int _time;
public:
    RoadReport();
    RoadReport(std::string startJunction, std::string endJunction, int time);
    RoadReport(const std::string &startJunction, const std::string &endJunction, const std::string &cars);
    virtual ~RoadReport();
    void writeReport();
private:

};

#endif	/* ROADREPORT_H */

