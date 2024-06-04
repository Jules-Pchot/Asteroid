//
// Created by JulesEfrei on 02/01/2024.
//

#ifndef SDLTEST_CONTROLLER_HPP
#define SDLTEST_CONTROLLER_HPP
#include "Model.hpp"
#include "View/framework.hpp"
#include "View.hpp"
#include "Model/FlyingObject.hpp"
#include <vector>



class Controller {
public :
    //paramètres
    Framework *TheFramework;
    Model *TheModel;
    View *TheView;

    //Methodes
    Controller(Framework *fw,Model *model,View *view);
    void LaunchGame();


};


#endif //SDLTEST_CONTROLLER_HPP
