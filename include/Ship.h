#pragma once
#include "SFML/Graphics.hpp"
#include "v2f.h"
#include <vector>
#include <math.h>
#include <iostream>



class Ship
{
private:
    sf::VertexArray ship;
    std::vector<v2f> vertexPosition{v2f(0.0f, -4.0f), // top
                                    v2f(-2.5f, 2.0f), // out left
                                    v2f(-1.0f, 1.0f), // in left
                                    v2f(1.0f, 1.0f),  // in right
                                    v2f(2.5f, 2.0f),  // out right
                                    v2f(0.0f, -4.0f),// top
                                    v2f(0.0f, 3.0f)}; // boost

public:
    v2f shipPosition;
    v2f shipDirection;
    float shipScale;
    enum class ThrustDirection {Forward, Backward, None};

private:
    float shipVelocity;
    const float shipAcceleration;
    const float shipDragLinear;
    ThrustDirection thrustDirection;
    sf::Clock clock;
    float deltaTime;

public:
    Ship();
    void Render(sf::RenderWindow& window);
    void SetPosition(v2f destination);
    void UpdatePosition();
    void SetThrustDirection(ThrustDirection thrustDir);
    void Move(v2f dir, float deltaTime);
    void Rotate();

    v2f GetRotation();

    float GetDeltaTime();
};
