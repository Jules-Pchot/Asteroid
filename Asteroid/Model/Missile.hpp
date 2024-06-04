//
// Created by JulesEfrei on 01/12/2023.
//

#ifndef SDLTEST_MISSILE_HPP
#define SDLTEST_MISSILE_HPP

#include "FlyingObject.hpp"
#include "Spaceship.hpp"


class Missile : public FlyingObject {
public :
    Missile(double x, double y, double size, double speed, double angle);
    void Move() override;
    bool Move(double screenWidth, double screenHeight) override;
    std::string GetTypeName() const;

private :
    double angle;
    double speed;
};


#endif //SDLTEST_MISSILE_HPP
