/* 
 * File:   CarFaultEvent.h
 * Author: chen
 *
 * Created on November 15, 2014, 1:30 PM
 */

#ifndef CARFAULTEVENT_H
#define	CARFAULTEVENT_H
#include <string>
#include "Event.h"
#include "Car.h"

class CarFaultEvent : public Event{
    int _time;
    Car* _car;
    int _timeOfFault;
    std::map<std::string, Car*> _carsMap;
public:
    CarFaultEvent();
    CarFaultEvent(int time, const std::string carId, int timeOfFault);
    virtual ~CarFaultEvent();
    void performEvent();
    void setCarsMap(std::map<std::string, Car*> &carsMap);

private:
     
    

};

#endif	/* CARFAULTEVENT_H */

