//
// Created by JulesEfrei on 14/12/2023.
//

#include "Spaceship.hpp"
#include <cmath>

Spaceship::Spaceship(double x, double y, double size, double angle, double xSpeed,double ySpeed)
        : FlyingObject(x, y, size), angle(angle), xSpeed(xSpeed), ySpeed(ySpeed){}

double Spaceship::GetAngle() {
    return angle;
}

bool Spaceship::Move(double screenWidth,double screenHeight){
    SetX(GetX() > screenWidth ? 0 : (GetX() < 0 ? screenWidth : GetX()));
    SetY(GetY() > screenHeight ? 0 : (GetY() < 0 ? screenHeight : GetY()));

    SetX(GetX() + xSpeed);
    SetY(GetY() + ySpeed);

    return true;
}
void Spaceship::SpeedUp(double accelerationFactor){
    double angleR =(M_PI*(this->angle-90))/180  ;
    double xSpeedTemp = xSpeed+cos(angleR)*accelerationFactor;
    double ySpeedTemp = ySpeed+sin(angleR)*accelerationFactor;
    double accelerationTotal = sqrt(pow(xSpeedTemp,2)+pow(ySpeedTemp,2));
    if(accelerationTotal<MAXSPEED){
        xSpeed =  xSpeedTemp;
        ySpeed = ySpeedTemp;
    }
}

void Spaceship::SpeedDown(double decelerationFactor){
    double angleR =(M_PI*(this->angle-90))/180  ;
    double xSpeedTemp = xSpeed-cos(angleR)*decelerationFactor;
    double ySpeedTemp = ySpeed-sin(angleR)*decelerationFactor;
    double accelerationTotal = sqrt(pow(xSpeedTemp,2)+pow(ySpeedTemp,2));
    if(accelerationTotal<MAXSPEED){
        xSpeed =  xSpeedTemp;
        ySpeed = ySpeedTemp;
    }
}

void Spaceship::Rotate(double rAngle) {
    angle = (angle+rAngle);
}

std::string Spaceship::GetTypeName() const {
    return "Spaceship";
}
