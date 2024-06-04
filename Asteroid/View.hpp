//
// Created by JulesEfrei on 02/01/2024.
//

#ifndef SDLTEST_VIEW_HPP
#define SDLTEST_VIEW_HPP
#include "View/Framework.hpp"
#include "Model.hpp"



class View {
public:
    View(Framework* framework);
    void RefreshDisplay(const std::vector<FlyingObject*>& FlyingObjects);

private:
    Framework* fw;  // Pointeur vers le Framework
};


#endif //SDLTEST_VIEW_HPP
