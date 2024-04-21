#pragma once
#include "SFML/Graphics.hpp"


class Timer
{
    public:
    Timer();

    private:
        sf::Clock clock;
        float deltaTime;

    public:
        float GetDeltaTime();
};

