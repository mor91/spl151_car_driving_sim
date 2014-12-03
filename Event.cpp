/* 
 * File:   Event.cpp
 * Author: chen
 * 
 * Created on November 15, 2014, 11:43 AM
 */

#include "Event.h"
#include <iostream>

Event::Event() {
}

Event::Event(const std::string &eventID) {
    _eventID=eventID;
}

Event::~Event() {
        std::cout << "Event deleted"<< std::endl;

}


