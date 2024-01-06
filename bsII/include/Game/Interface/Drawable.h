#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <SFML/Graphics.hpp>

#include "Traits/Traits.h"

namespace Utils {
    class Point;
}

namespace BrickShooter
{
    class Drawable
    {
    public:
        virtual ~Drawable() = default;

        virtual void draw(sf::RenderWindow &window, double diffTime) = 0;

        virtual void update(double diffTime) = 0;

        virtual int getSize() = 0;

        virtual Utils::Point getPosition() = 0;

        virtual sf::FloatRect getGlobalBounds() = 0;
    };
} // namespace BrickShooter

#endif //DRAWABLE_H
