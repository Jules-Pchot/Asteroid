cmake_minimum_required(VERSION 3.0.0)
project(SDLTEST VERSION 0.1.0 LANGUAGES C CXX)

set (SDL2_DIR .)

file(COPY bin/SDL2.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY images DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/images/)

set(
    SRCS
    main.cpp
        View/framework.cpp
        Model/Asteroid.cpp
)

set(
    HEADER
        View/framework.hpp
        Model/Asteroid.cpp
        Model/Asteroid.cpp
        Model/Asteroid.cpp
        Model/FlyingObject.cpp
        Model/Missile.cpp
        Model/Spaceship.hpp
        Model/SpaceShip.cpp
        View.hpp
        Controller.hpp
        Controller.cpp
        Controller.cpp
        Model.cpp
        View.cpp
)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(SDLTEST ${SRCS} ${HEADER}
        Model/Asteroid.cpp
        Model/Asteroid.cpp)
target_link_libraries(SDLTEST ${SDL2_LIBRARIES})
