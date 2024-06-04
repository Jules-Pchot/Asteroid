//
// Created by JulesEfrei on 01/12/2023.
//
#include <cmath>

#include "FlyingObject.hpp"

FlyingObject::FlyingObject(double x, double y, double size)
        : x(x), y(y), size(size) {}


double FlyingObject::GetX() { return x; }
double FlyingObject::GetY() { return y; }
double FlyingObject::GetSize()  { return size; }

void FlyingObject::SetX(double x) { this->x = x; }
void FlyingObject::SetY(double y) { this->y = y; }

void FlyingObject::Move() { }

bool FlyingObject::Move(double screenWidth, double screenHeight){
    return true;
}

bool FlyingObject::Collide(FlyingObject& o1, FlyingObject& o2){

    double  ratioDistance= sqrt(pow(o1.GetX()-o2.GetX(),2)+pow(o1.GetY()-o2.GetY(),2));

    double distanceMinCollision = (o1.GetSize()/2)+(o2.GetSize()/2);

    if(distanceMinCollision > ratioDistance){
        return true;
    }else return false;

}
