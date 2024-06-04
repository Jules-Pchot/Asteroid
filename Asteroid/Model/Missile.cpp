//
// Created by JulesEfrei on 01/12/2023.
//
#include <cmath>
#include "Missile.hpp"

Missile::Missile(double x, double y, double size, double speed, double angle)
        : FlyingObject(x, y, size), speed(speed), angle(angle) {}

void Missile::Move() {

    double rad = M_PI * (angle - 90) / 180;// (M_PI*(this->angle-90))/180

    SetX(GetX() + speed * cos(rad));
    SetY(GetY() + speed * sin(rad));
}

bool Missile::Move(double screenWidth, double screenHeight) {
    if((GetX() < 0 || GetX() > screenWidth) || (GetY() < 0 || GetY() > screenHeight)){
        return true;
    }
    return false;
}
std::string Missile::GetTypeName() const {
    return "Missile";
}