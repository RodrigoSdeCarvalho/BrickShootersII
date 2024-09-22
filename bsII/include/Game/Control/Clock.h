#ifndef CLOCK_H
#define CLOCK_H

#include "SFML/Graphics.hpp"

#include "Traits/Traits.h"

namespace BrickShooter
{
    class Clock
    {
    public:
        Clock();

        ~Clock() = default;

        void restart();

        double getElapsedTime();

    private:
        sf::Clock clock;
        int fps;
        double previousTime;
    };
} // namespace BrickShooter

#endif //CLOCK_H
