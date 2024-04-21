#include "main.h"
#include "v2f.h"
#include "ship.h"
#include "Timer.h"
#include "Logger.h"
#include <iostream>
#include "SFML/Graphics.hpp"

#define LogVec(v2f) std::cout << v2f.x << ", " << v2f.y << std::endl;

//! Window  movement idea!!

int main()
{
    const sf::Vector2i windowPosition(700, 50);

    Ship ship;
    
    // timer related variables
    Timer timer;
    float deltaTime;

    // logger related variable
    Logger logger;

    //* Test Section -------------------------------------------
    //* Test Section Ends --------------------------------------

    // creating window and setting its values
    sf::RenderWindow window(sf::VideoMode(800, 800), "Asteroids");
    window.setPosition(windowPosition);
    window.setFramerateLimit(60);

    // main game loop
    while (window.isOpen())
    {
        
        deltaTime = timer.GetDeltaTime();
        // logger.Add(deltaTime);
        
        // poll events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed)
            {
                switch (event.key.code)
                {
                    case sf::Keyboard::Key::W:
                        ship.SetThrustDirection(Ship::ThrustDirection::Forward);
                        break;
                    case sf::Keyboard::Key::S:
                        ship.SetThrustDirection(Ship::ThrustDirection::Backward);
                        break;

                    default:
                        break;
                }
            }
            else if (event.type == sf::Event::KeyReleased)
            {
                switch (event.key.code)
                {
                    case sf::Keyboard::Key::W:
                        ship.SetThrustDirection(Ship::ThrustDirection::None);
                        break;
                    case sf::Keyboard::Key::S:
                        ship.SetThrustDirection(Ship::ThrustDirection::None);
                        break;

                    default: 
                        break;
                }
            }
        }

        // function:        
        ship.Move(ship.shipDirection, deltaTime );
 
        window.clear();

        // draw stuff to window
        ship.Render(window);

        window.display();
    }
}