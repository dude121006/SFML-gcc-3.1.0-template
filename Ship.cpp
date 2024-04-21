#include "Ship.h"

Ship::Ship() : shipAcceleration(50.0f), shipDragLinear(0.988f)
{
    // vertArray attributes
    ship.setPrimitiveType(sf::PrimitiveType::LineStrip);
    ship.resize(6);

    // ship attributes
    shipPosition = v2f(400.0f, 400.0f);
    shipScale = 10.0f;
    shipVelocity = 0.0f;

    // setting thrust direction as None
    thrustDirection = ThrustDirection::None;

    // clock, time stuff
    deltaTime = 0.0f;

    // adjust position of ship
    SetPosition(v2f(400, 400));
}

void Ship::Move(v2f dir, float deltaTime)
{
    if (thrustDirection == ThrustDirection::Forward)
    {
        shipVelocity += shipAcceleration * deltaTime;
        shipPosition += v2f(shipVelocity, shipVelocity);
    }
    else
    {
        shipVelocity *= shipDragLinear;
        
    }
    UpdatePosition();
}

void Ship::SetPosition(v2f destination)
{
    shipPosition = destination;

    for (int i = 0; i < ship.getVertexCount(); i++)
    {
        // vertex Position adjusted with scale
        v2f vertPos = (vertexPosition[i] * shipScale + shipPosition);
        ship[i] = sf::Vertex(vertPos, sf::Color::White);
    }
}

void Ship::UpdatePosition()
{
    for (int i = 0; i < ship.getVertexCount(); i++)
    {
        // vertex Position adjusted with scale
        v2f vertPos = (vertexPosition[i] * shipScale + shipPosition);
        ship[i] = sf::Vertex(vertPos, sf::Color::White);
    }
}

void Ship::Render(sf::RenderWindow &window)
{
    window.draw(ship);
}

v2f Ship::GetRotation()
{
    // std::cout << (vertexPosition[0] - shipPosition).x << ", " << (vertexPosition[0] - shipPosition).y << std::endl;
    shipDirection = vertexPosition[0] - shipPosition;
    shipDirection.MakeUnitVector();
    return shipDirection;
}

void Ship::SetThrustDirection(ThrustDirection thrustDir)
{
    thrustDirection = thrustDir;
}
