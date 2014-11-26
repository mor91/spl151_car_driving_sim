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


class JunctionReport:public Report {
    Junction _junction;
    std::string _timeSlices;
    std::vector<std::string> _inComingJunctionID;
    int _time;
    std::string reportId;
public:
    JunctionReport();
    JunctionReport(Junction &junction, int time);
    JunctionReport(const Junction &junction, const std::string &timeSlices, const std::vector<std::string> &inComingJunctionID );
    virtual ~JunctionReport();
    void writeReport();


};

#endif	/* JUNCTIONREPORT_H */

