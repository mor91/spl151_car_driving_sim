/* 
 * File:   Car.h
 * Author: chen
 *
 * Created on November 15, 2014, 2:27 PM
 */
#include "Road.h"
#include "CarReport.h"
#ifndef CAR_H
#define	CAR_H
#include <string>

class Car {
    std::string _carID;
    std::string _roadPlan;//change type
    bool _goodCondition;
    int _distanceFromBeginningOfRoad;
    int _speed;//constructor
    Road _currentRoad;//constructor
    CarReport _carReport;
public:

    Car(const std::string& carID,const std::string& roadPlan);
    virtual ~Car();
    void newSpeed();

};

#endif	/* CAR_H */


