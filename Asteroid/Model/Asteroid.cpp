//
// Created by JulesEfrei on 01/12/2023.
//
#include <string>
#include <random>
#include "Asteroid.hpp"
#include "FlyingObject.hpp"

Asteroid::Asteroid(double x, double y, double size, double xSpeed, double ySpeed, double angle)
        : FlyingObject(x, y, size), xSpeed(xSpeed), ySpeed(ySpeed), angle(angle) {}

        //déplacement
void Asteroid::Move() {}

void Asteroid::applyAcceleration(double angleDegrees, double accelerationFactor) {
    double angleR = (M_PI * (angleDegrees - 90)) / 180;
    double xSpeedTemp = xSpeed + cos(angleR) * accelerationFactor;
    double ySpeedTemp = ySpeed + sin(angleR) * accelerationFactor;
    double accelerationTotal = sqrt(pow(xSpeedTemp, 2) + pow(ySpeedTemp, 2));

    if (accelerationTotal < MAXSPEED) {
        xSpeed = xSpeedTemp;
        ySpeed = ySpeedTemp;
    }
}
bool Asteroid::Move(double screenWidth, double screenHeight) {
    SetX(GetX() > screenWidth ? 0 : (GetX() < 0 ? screenWidth : GetX()));
    SetY(GetY() > screenHeight ? 0 : (GetY() < 0 ? screenHeight : GetY()));

    SetX(GetX() + xSpeed);
    SetY(GetY() + ySpeed);
    return true;
}
double Asteroid::GetAngle() {
    return angle;
}



std::string Asteroid::GetTypeName() const {
    return "Asteroid";
}

