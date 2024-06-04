//
// Created by JulesEfrei on 02/01/2024.
//

#include "View.hpp"

View::View(Framework* framework) {
    fw = framework;
}

void View::RefreshDisplay(const std::vector<FlyingObject*>& FlyingObjects) {
    // Parcourez le vecteur
    for (const auto& obj : FlyingObjects) {
        // Utilisez GetTypeName() pour déterminer le type de l'objet
        std::string typeName = obj->GetTypeName();

        // Affichez l'objet en conséquence
        if (typeName == "Spaceship") {
            // Transtypez vers Spaceship et utilisez le Framework pour afficher le vaisseau
            Spaceship* spaceship = dynamic_cast<Spaceship*>(obj);
            if (spaceship) {
                // Utilisez le Framework pour afficher le vaisseau
                fw->DrawShip(spaceship->GetX(), spaceship->GetY(), spaceship->GetAngle(),1.0f,false);
            }
        } else if (typeName == "Missile") {
            // Transtypez vers Missile et utilisez le Framework pour afficher le missile
            Missile* missile = dynamic_cast<Missile*>(obj);
            if (missile) {
                // Utilisez le Framework pour afficher le missile
                fw->DrawMissile(missile->GetX(), missile->GetY());
            }
        } else if (typeName == "Asteroid") {
            // Transtypez vers Asteroid et utilisez le Framework pour afficher l'astéroïde
            Asteroid* asteroid = dynamic_cast<Asteroid*>(obj);
            if (asteroid) {
                // Utilisez le Framework pour afficher l'astéroïde
                fw->DrawAsteroid(asteroid->GetX(), asteroid->GetY(), asteroid->GetSize());
            }
        }
    }
}