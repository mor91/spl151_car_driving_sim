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
public:
    CarFaultEvent();
    CarFaultEvent(int time, const Car &car, int timeOfFault);
    virtual ~CarFaultEvent();
    void performEvent();

private:
     
    

};

#endif	/* CARFAULTEVENT_H */

