/* 
 * File:   Junction.h
 * Author: chen
 *
 * Created on November 15, 2014, 1:36 PM
 */

#ifndef JUNCTION_H
#define	JUNCTION_H
#include <string>

class Junction {
    std::string _junctionID;

public:
    Junction();
    Junction(const std::string &junctionID);
    virtual ~Junction();

    
    

};

#endif	/* JUNCTION_H */

