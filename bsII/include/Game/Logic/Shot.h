#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Traits/Traits.h"

#include "Game/Control/Config.h"

#include "Game/Interface/Drawable.h"
#include "Game/Interface/window.h"

#include "Utils/Point.h"
#include "Utils/Vector.h"

namespace BrickShooter
{
    using Utils::Point;
    using Utils::Vector;

    class CollisionHandler;

    class Player;

    class Shot : public Drawable
    {
    public:
        enum Direction {
            LEFT = 0,
            RIGHT = 1,
            UP = 2,
            DOWN = 3
        };

        Shot(const Point &position, Direction direction, bool isPlayerShot);

        ~Shot() override = default;

        void draw(sf::RenderWindow &window, double diffTime) override;

        void update(double diffTime) override;

        void updateSprite();

        sf::FloatRect getGlobalBounds() override;

        int getSize() override;

        int getDamage() const { return this->damage; }

        void move(double diffTime);

        Point getPosition() override;

        bool getIsPlayerShot() const { return this->isPlayerShot; }

        void handleOutOfBounds();

        Vector getSpeed(Direction directionOfSHot);

        void removeFromGame();

        void loadAndBindTexture();

        void collide();

    private:
        Point position;
        Vector speed;

        bool isPlayerShot;
        int damage = 1;

        sf::Sprite sprite;
        sf::Texture texture;

        Direction direction;

        double speedFactor = 2.0;
    };
} // namespace BrickShooter

#endif //PROJECTILE_H
