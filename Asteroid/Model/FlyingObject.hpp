//
// Created by JulesEfrei on 01/12/2023.
//

#ifndef SDLTEST_FLYINGOBJECT_HPP
#define SDLTEST_FLYINGOBJECT_HPP
#include <string>


class FlyingObject {
public:
    FlyingObject(double x, double y, double size);
    double GetX() ;
    double GetY() ;
    double GetSize() ;

    void SetX(double x) ;
    void SetY(double y) ;
    // Méthodes de déplacement
    virtual void Move();
    virtual bool Move(double screenWidth, double screenHeight);
    //Methods
    static bool Collide(FlyingObject& o1, FlyingObject& o2);

    virtual std::string GetTypeName() const = 0;

private:
    //attribute
    double x;
    double y;
    double size;
};


#endif //SDLTEST_FLYINGOBJECT_HPP
