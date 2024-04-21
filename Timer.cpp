#include "Timer.h"

Timer::Timer()
{
    deltaTime = 0;
    clock.restart();
}

float Timer::GetDeltaTime()
{
    deltaTime = clock.getElapsedTime().asSeconds();
    clock.restart();
    return deltaTime;
}