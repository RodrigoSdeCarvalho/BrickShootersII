#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H

#include <vector>
#include <memory>

#include "Concurrency/semaphore.h"
#include "Concurrency/thread.h"
#include "Traits/Traits.h"

#include "Game/Control/Clock.h"

#include "Game/Interface/Collidable.h"

namespace BrickShooter
{
    class BrickShooter;
    class Enemy;
    class Shot;
    class Player;
}

namespace BrickShooter
{
    using Concurrency::Semaphore;

    class CollisionHandler
    {
    public:
        CollisionHandler();

        ~CollisionHandler();

        static Semaphore *playerSemaphore;
        static Semaphore *enemySemaphore;
        static Semaphore *shotsSemaphore;

        void run();

        static void addEnemy(Enemy *enemy);

        static void addShot(Shot *shot);

        static void addPlayer(Player *player);

        static void removeEnemy(Enemy *enemy);

        static void removeShot(Shot *shot);

        static void removePlayer();

        void restart();

    private:
        static std::vector<Enemy *> enemies;
        static Player *player;
        static std::vector<Shot *> shots;
        static std::vector<Shot *> shotsToRemove;
        std::unique_ptr <Clock> enemyCollisionClock;

        void handleCollisions();

        void handlePlayerEnemyCollisions();

        void handleShotCollisions();

        void handleShotShotCollisions();

        void handleEnemyShotCollisions(Shot *shot);

        void handlePlayerShotCollisions(Shot *shot);

        bool hasCollided(Drawable *drawable1, Drawable *drawable2);

        template<typename T>
        static bool isPointerInVector(const std::vector<T *> &vec, const T *ptr) {
            for (const auto &element: vec) {
                if (element == ptr) {
                    return true;
                }
            }
            return false;
        }
    };
} // namespace BrickShooter

#endif //COLLISIONHANDLER_H
