//
// Created by JulesEfrei on 01/12/2023.
//

#ifndef SDLTEST_ASTEROID_HPP
#define SDLTEST_ASTEROID_HPP


#include "FlyingObject.hpp"
#include "Missile.hpp"

class Asteroid : public FlyingObject {
public:
    // Constructeur
    Asteroid(double x, double y, double size, double xSpeed, double ySpeed,double angle);

    // Méthodes de déplacement
    void Move() override;
    bool Move(double screenWidth, double screenHeight) override;
    void applyAcceleration(double angleDegrees, double accelerationFactor);
    double GetAngle();


    std::string GetTypeName() const;


private:
    double xSpeed;
    double ySpeed;
    double angle;
    constexpr static double MAXSPEED = 2 ;

};


#endif //SDLTEST_ASTEROID_HPP
