#include "View/Framework.hpp"
#include "View.hpp"
#include "Model.hpp"
#include "Controller.hpp"

#include <iostream>

using namespace std;
int main(int argc, char* argv[]) {

// Créez une instance du Framework
    Framework *fw = new Framework(1000, 60, 20);
    int ScreenHeight = 2*fw->GetScreenHeight();
    int ScreenWidth = 2*fw->GetScreenHeight();
    View* view = new View(fw);

    Model* model = new Model(fw,ScreenHeight,ScreenWidth);

    Controller* controller = new Controller(fw,model, view);

    controller->LaunchGame();

    // Libérez la mémoire avant de quitter
    delete controller;
    delete model;
    delete view;
    delete fw;



    return 0;
}