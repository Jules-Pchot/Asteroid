//
// Created by JulesEfrei on 14/12/2023.
//

#ifndef SDLTEST_SPACESHIP_HPP
#define SDLTEST_SPACESHIP_HPP
#include "FlyingObject.hpp"

class Spaceship: public FlyingObject {
public :
    Spaceship(double x, double y, double size, double angle, double xSpeed,double ySpeed);
    double GetAngle();
    void SpeedUp(double accelerationFactor);
    void SpeedDown(double decelerationFactor);
    void Rotate(double rAngle);
    bool Move(double screenWidth,double screenHeight);
    std::string GetTypeName() const;


private :
    double xSpeed;
    double ySpeed;
    constexpr static double MAXSPEED = 5 ;
    double angle;

};


#endif //SDLTEST_SPACESHIP_HPP
