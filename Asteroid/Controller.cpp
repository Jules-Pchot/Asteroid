//
// Created by JulesEfrei on 02/01/2024.
//

#include "Controller.hpp"

Controller::Controller(Framework *fw,Model *model,View *view){
    // Initialiser le Framework avec les paramètres fournis
    TheFramework = fw;
    TheModel = model;
    TheView = view;
}

void Controller::LaunchGame() {
    while (true) {

        // 1. Lire l’entrée du joueur au clavier
        int input = TheFramework->GetInput();

        if(input==SDLK_ESCAPE){
            break;
        }
        // 2. Demander au Modèle d’appliquer l’input
       TheModel->ApplyAction(input);

        // 3. Model mettre à jour les données du Model
       TheModel->UpdateSpace();

        // 4. rafraichir l’affichage de la vue avec les objets du Model
        std::vector<FlyingObject*> FlyingObjects = TheModel->GetAllFlyingObjects();
       TheView->RefreshDisplay(FlyingObjects);


    }
}




