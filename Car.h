/* 
 * File:   Car.h
 * Author: chen
 *
 * Created on November 15, 2014, 2:27 PM
 */


#include "Report.h"
#ifndef CAR_H
#define	CAR_H
#include <string>
#include <map>


class Road; 

class Car {
    std::string _carID;
    std::map<int, Road*> *_roadPlan;
    int _distanceFromBeginningOfRoad;
    int _speed;
    std::string _history;
    int _numOfJunctionTheCarPass;
    Road* _currentRoad;
    int _remainingTimeToFault;
    int _currentRoadNumber;
public:
    
    Car(const std::string &carID, std::map<int , Road*>& roadPlan,int time);
    virtual ~Car();
    void newSpeed();
    void advanceCar(int time);  
    int getDistanceFromBeginningOfRoad();
    std::string getCarId();
    Road* getCurrentRoad();
    void setRemainingTimeToFault(int time);
    int getRemainingTimeOfFault();
    std::string getHistory();
    void setCurrentRoad(Road* road);
    int setNextRoad();
    
};

#endif	/* CAR_H */


