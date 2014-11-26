/* 
 * File:   Report.h
 * Author: chen
 *
 * Created on November 15, 2014, 11:45 AM
 */

#ifndef REPORT_H
#define	REPORT_H
#include <string>

class Report {
    std::string _reportID;
public:
    Report();
    Report(const std::string &reportID);
    virtual ~Report();
    virtual void writeReport()=0;
private:

};

#endif	/* REPORT_H */

