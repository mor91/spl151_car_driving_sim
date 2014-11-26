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


class CarReport:public Report {
    std::string _carID;
    std::string _history;
    int _faultyTimeLeft;
    std::string _reportId;
    int _timeOfReport;
public:
    CarReport();
    CarReport(std::string &carID, std::string &reportId, int timeOfReport);
    CarReport(const std::string &carID, const std::string &history,int faultyTimeLeft);
    void writeReport();
    virtual ~CarReport();
private:

};

#endif	/* CARREPORT_H */

