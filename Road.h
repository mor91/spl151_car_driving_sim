/* 
 * File:   Road.h
 * Author: chen
 *
 * Created on November 15, 2014, 2:34 PM
 */

#ifndef ROAD_H
#define	ROAD_H
#include <string>

class Road {
    std::string _startingJunction;
    std::string _endJunction;
    int _length;
    int _baseSpeed;
    int _noOfCars;
    //std::vector<Car> _carsQueue;//maybe should be a queue
    //std::vector<Car> _faultyCars;
    //RoadReport::writeReport() _RoadReport;
public:
    Road();
    Road(const std::string &startingJunction, const std::string &endJunction, int length);
    virtual ~Road();
    std::string getSJunc();
    std::string getEJunc();
    int getLen();
    void baseSpeed();
    int getNoOfCars();

    //void  changeSpeed()
    
};

#endif	/* ROAD_H */
