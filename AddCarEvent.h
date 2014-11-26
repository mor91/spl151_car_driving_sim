/* 
 * File:   AddCarEvent.h
 * Author: chen
 *
 * Created on November 15, 2014, 1:27 PM
 */

#ifndef ADDCAREVENT_H
#define	ADDCAREVENT_H
#include <string>
#include "Car.h"
#include "Event.h"

class AddCarEvent: public Event {
    int _time;
    std::string _carID;
    std::string _roadPlan;
    
public:
    AddCarEvent();
    virtual ~AddCarEvent();
    AddCarEvent(int time,const std::string &carID,const std::string &roadPlan);
    void performEvent();
    std::string getCarId();
    std::string getRoadPlan();
    int getTime();

};


#endif	/* ADDCAREVENT_H */

