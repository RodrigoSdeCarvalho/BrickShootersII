#ifndef PLAYER_H
#define PLAYER_H

#include <memory>

#include "Traits/Traits.h"

#include "Game/Control/keyboardController.h"
#include "Game/Control/Config.h"
#include "Game/Control/Play.h"
#include "Game/Control/Clock.h"

#include "Game/Logic/CollisionHandler.h"
#include "Game/Logic/Shot.h"

#include "Game/Interface/Collidable.h"
#include "Game/Interface/window.h"

#include "Utils/Point.h"
#include "Utils/Vector.h"

namespace BrickShooter
{
    using Concurrency::Semaphore;

    using Utils::Point;
    using Utils::Vector;

    class CollisionHandler;

    class Enemy;

    class Player : public Collidable
    {
    public:
        Player(KeyboardHandler *keyboardHandler);

        ~Player() override;

        void run();

        void setInitialPosition(Point position);

        void draw(sf::RenderWindow &window, double diffTime) override;

        void collide(int damage) override;

        bool isDead() override;

        void update(double diffTime) override;

        bool isOutOfPlay();

        int getLife() const;

        int getSize() override;

        Point getPosition() override;

        void setPosition(const Point &position);

        Point getPreviousPosition();

        void insertInGame();

        sf::FloatRect getGlobalBounds() override;

        void removeFromGame();

        static Semaphore *lifeSemaphore;
        static Semaphore *invulnerabilitySemaphore;
        static Semaphore *moveSemaphore;

    private:
        friend class Enemy;
        friend class Shot;

        static int PLAYER_SIZE;
        static int PLAYER_SPEED;

        static float SHOT_COOLDOWN;
        static float HIT_ANIMATION_TIME;
        static float INVULNERABILITY_TIME;

        KeyboardHandler *keyboardHandler;
        std::unique_ptr<Clock> shotClock;

        int life = 3;
        bool invulnerable = false;
        float invulnerabilityTime; // in seconds

        Point previousPosition;

        void move(double diffTime);

        void handleOutOfBounds();

        void handleInvulnerability(double diffTime);

        void updateSprite();

        void processKeyboardInput();

        void processKey(Play::KeyPress key);

        void shoot(Shot::Direction direction);

        void loadAndBindTexture();

        std::unique_ptr<Clock> drawDamagedPlayerClock;

        sf::Sprite sprite;
        sf::Texture texture;

        Vector speed;
        Point position;

        Shot::Direction direction;
    };
} // namespace BrickShooter

#endif //PLAYER_H
