//
// Created by JulesEfrei on 02/01/2024.
//

#ifndef SDLTEST_MODEL_HPP
#define SDLTEST_MODEL_HPP

#include "Model/Asteroid.hpp"
#include "Model/Missile.hpp"
#include "Model/Spaceship.hpp"
#include "Model/FlyingObject.hpp"
#include "View/Framework.hpp"
#include <vector>
#include <random>




class Model {
public :
    //attribut

    std::vector<Asteroid *> asteroids;


    //Constructeur
    Model(Framework* fw,int screenWidth, int screenHeight);

    void ApplyAction(int input);

    void UpdateSpace();
    // Implémentez une méthode qui renvoie un vector de pointeurs vers les objets volants en jeu
    std::vector<FlyingObject*> GetAllFlyingObjects();

    // Ajoutez des destructeurs pour libérer la mémoire lorsque le modèle est détruit
    ~Model();


private:
    Spaceship* spaceship;
    Missile* missile;
    const int nombreAsteroids = 10;
    Framework* fw;
    int ScreenWidth;
    int ScreenHeight;

    //spaceship Commandes
    void Accelerate();
    void Decelerate();
    void RotateLeft();
    void RotateRight();
    Asteroid *GenerateRandomAsteroid();

    //Missile commandes
    void FireMissile();

};


#endif //SDLTEST_MODEL_HPP
