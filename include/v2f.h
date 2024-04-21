#pragma once
#include "SFML/Graphics.hpp"
#include <math.h>
#include <iostream>


class v2f : public sf::Vector2f
{
public:
    // use default vector2f constructor
    // v2f(float x, float y) : sf::Vector2f(x, y){};
    using sf::Vector2f::Vector2f;

    // Conversion operator to convert v2f to sf::Vector2f
    operator sf::Vector2f() const { return sf::Vector2f(x, y); }

    // Overloaded operators to allow arithmetic operations with v2f
    v2f operator+(const v2f &other) const { return v2f(x + other.x, y + other.y); }
    v2f operator-(const v2f &other) const { return v2f(x - other.x, y - other.y); }
    v2f operator*(float scalar) const { return v2f(x * scalar, y * scalar); }
    v2f operator/(float scalar) const { return v2f(x / scalar, y / scalar); }

public:
    void Negate();
    void MakeUnitVector();
};
  