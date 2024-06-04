//
// Created by JulesEfrei on 02/01/2024.
//

#include <chrono>
#include "Model.hpp"

Model::Model(Framework* fw,int screenWidth, int screenHeight) : fw(fw){
    // Initialiser les attributs en fonction des valeurs utilisées dans votre main()
    ScreenWidth = screenWidth;
    ScreenHeight = screenHeight;
    spaceship = new Spaceship(ScreenWidth/2-100,ScreenHeight/2-(ScreenWidth/4),60,0.0f,0,0);
    missile = nullptr;  // Initialiser à nullptr car le missile n'est pas encore tiré
    for(int i = 0; i < nombreAsteroids; i++){
        this->asteroids.push_back(GenerateRandomAsteroid());
    }
}
Asteroid* Model::GenerateRandomAsteroid(){
    auto seed = static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count());
    int screenWidth = ScreenWidth;
    int screenHeight = ScreenHeight;
    // génération de la seed avec le temps systeme
    std::default_random_engine randomEngine(seed);

    int screenPart = std::uniform_int_distribution<int>(0, 7)(randomEngine);
    double xmin=0;
    double xmax=0;
    double ymin=0;
    double ymax=0;
    switch(screenPart){
        case 0:
            xmin = 0.0;
            xmax = screenWidth / 3.0;
            ymin = 0.0;
            ymax = screenHeight / 3.0;
            break;
        case 1:
            xmin = screenWidth / 3.0;
            xmax = 2.0 * screenWidth / 3.0;
            ymin = 0.0;
            ymax = screenHeight / 3.0;
            break;
        case 2:
            xmin = 2.0 * screenWidth / 3.0;
            xmax = screenWidth;
            ymin = 0.0;
            ymax = screenHeight / 3.0;
            break;
        case 3:
            xmin = 0.0;
            xmax = screenWidth / 3.0;
            ymin = screenHeight / 3.0;
            ymax = 2.0 * screenHeight / 3.0;
            break;
        case 4:
            xmin = 2.0 * screenWidth / 3.0;
            xmax = screenWidth;
            ymin = screenHeight / 3.0;
            ymax = 2.0 * screenHeight / 3.0;
            break;
        case 5:
            xmin = 0.0;
            xmax = screenWidth / 3.0;
            ymin = 2.0 * screenHeight / 3.0;
            ymax = screenHeight;
            break;
        case 6:
            xmin = screenWidth / 3.0;
            xmax = 2.0 * screenWidth / 3.0;
            ymin = 2.0 * screenHeight / 3.0;
            ymax = screenHeight;
            break;
        case 7:
            xmin = 2.0 * screenWidth / 3.0;
            xmax = screenWidth;
            ymin = 2.0 * screenHeight / 3.0;
            ymax = screenHeight;
            break;
    }
    double x = std::uniform_real_distribution<double>(xmin, xmax)(randomEngine);
    double y = std::uniform_real_distribution<double>(ymin, ymax)(randomEngine);
    double xSpeed = std::uniform_real_distribution<double>(2, 5)(randomEngine);
    double ySpeed = std::uniform_real_distribution<double>(2, 5)(randomEngine);
    double angle = std::uniform_real_distribution<double>(0, 360)(randomEngine)-180;
    return new Asteroid(x, y, 100, xSpeed,ySpeed, angle);
}

void Model::ApplyAction(int input) {
    switch (input) {
        case SDLK_LEFT:
            RotateLeft();
            break;
        case SDLK_RIGHT:
            RotateRight();
            break;
        case SDLK_UP:
            Accelerate();
            break;
        case SDLK_DOWN:
            Decelerate();
            break;
        case SDLK_SPACE:
        if(!missile) {
            missile = new Missile(spaceship->GetX(), spaceship->GetY(), 10.0, 20, spaceship->GetAngle());
        }
        break;
        default:
            break;
    }
}
void Model::Accelerate() {
    spaceship->SpeedUp(0.2);
}
void Model::Decelerate() {
    spaceship->SpeedDown(0.5);
}

void Model:: RotateLeft() {
    spaceship->Rotate(-15);
}

void Model:: RotateRight() {
    spaceship->Rotate(15);
}

void Model:: FireMissile() {
    missile->Move();
    if(missile->Move(ScreenWidth,ScreenHeight)){
        delete missile;
        missile = nullptr;
    }
}

void Model:: UpdateSpace() {
        // Appelez la méthode sur l'élément actuel du vecteur
        for (auto asteroid: asteroids) {
            asteroid->applyAcceleration(asteroid->GetAngle(),3);
            asteroid->Move(this->ScreenWidth, this->ScreenHeight);
            if(missile!= nullptr){
                if(FlyingObject::Collide(*missile,*asteroid)){
                    delete missile;
                    missile = nullptr;
                    delete asteroid;
                    asteroid = nullptr;
                }
            }
        }
    if(missile){
        FireMissile();
        }
    spaceship->Move(ScreenWidth,ScreenHeight);
    fw->Update();
}

std::vector<FlyingObject*> Model:: GetAllFlyingObjects() {
    std::vector<FlyingObject*> FlyingObjects;

    // Ajouter le vaisseau, le missile (s'il est tiré) et l'astéroïde au vecteur
    FlyingObjects.push_back(spaceship);
    if (missile) {
        FlyingObjects.push_back(missile);
    }
    for (Asteroid* asteroid : asteroids) {
        FlyingObjects.push_back(asteroid);
    }
    return FlyingObjects;
}

// Ajoutez des destructeurs pour libérer la mémoire lorsque le modèle est détruit
Model::~Model()
    {
        delete spaceship;
        delete missile;
        for (auto asteroid: asteroids) {
            delete asteroid;
        }

    }