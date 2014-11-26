/* 
 * File:   Event.h
 * Author: chen
 *
 * Created on November 15, 2014, 11:43 AM
 */

#ifndef EVENT_H
#define	EVENT_H
#include <string>

class Event {
    std::string _eventID;
public:
    Event();
    Event(const std::string &eventID);
    virtual ~Event();
    virtual void performEvent()=0;
private:

};

#endif	/* EVENT_H */

