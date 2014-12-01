/* 
 * File:   Road.h
 * Author: chen
 *
 * Created on November 15, 2014, 2:34 PM
 */

#ifndef ROAD_H
#define	ROAD_H
#include "Car.h"
#include "Junction.h"
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <iostream>

class Road {
    Junction _startingJunction;
    Junction _endJunction;
    int _length;
    int _baseSpeed;
    int _noOfCars;
    std::map<int,std::vector<Car*>> _faultyCarsOnRoad;
    int _timeSlice;
    std::queue<Car*> _waitingForGreenLightList;
    int _numOfWaitingCars;
    Car* _carToRemove;
    std::string _WaitingCarList;
    
public:
    Road();
    Road(const Junction &startingJunction, const Junction &endJunction, int length);
    virtual ~Road();
    Junction getSJunc();
    Junction getEJunc();
    int getLen();
    void baseSpeed();
    int getNoOfCars();
    void removeFaultyCar(Car& car);
    void addFaultyCar(Car& car);//implementation on CarFaultyCar
    void addCarToRoad();
    std::map<int,std::vector<Car*>> getFaultyCarsOnRoadMap();
    int getBaseSpeed();
    void addCarToWaitingList(Car* car);
    int removeCarFromWaitingList();
    int getTimeSlice();
    void setNumOfWaitingCars();
    int getNumOfWaitingCars();
    void setTimeSlice(int time);
    Car* getCarToRemove();
    std::queue<Car*> getWaitingList();
    std::string getWaitingCarList();

    
};

#endif	/* ROAD_H */
