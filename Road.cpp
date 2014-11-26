/* 
 * File:   Road.cpp
 * Author: chen
 * 
 * Created on November 15, 2014, 2:34 PM
 */

#include "Road.h"
#include <math.h>

Road::Road() {
}

Road::Road(const std::string &startingJunction, const std::string &endJunction, int length) {
    _startingJunction=startingJunction;
    _endJunction=endJunction;
    _length=length;
    _baseSpeed=0;
    _noOfCars=0;
}

Road::~Road() {
}
std::string Road::getSJunc(){
    return _startingJunction;
}
std::string Road::getEJunc(){
    return _endJunction;
}
int Road::getLen(){
    return _length;
}
void Road::baseSpeed(){
    _baseSpeed=ceil(_length/_noOfCars);
}
int Road::getNoOfCars(){
    return _noOfCars;
}
