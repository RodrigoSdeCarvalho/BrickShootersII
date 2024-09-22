#ifndef controller_h
#define controller_h

#include <SFML/Graphics.hpp>

#include "Game/Control/keyboardController.h"
#include "Game/Control/Config.h"
#include "Game/Logic/Info.h"

#include "Game/Logic/Player.h"
#include "Game/Logic/Enemy.h"
#include "Game/Logic/CollisionHandler.h"

#include "Game/Interface/window.h"
#include "Game/Interface/Sounds.h"

namespace BrickShooter
{
    using Concurrency::Thread;

    class BrickShooter
    {
    public:
        BrickShooter() = default;

        ~BrickShooter() = default;

        static void play(void *name);

        static void init();

        static void restart();

        static void increaseScore();

        static void increaseLevel();

        static bool shouldLevelUp();

        static Info* info;

    private:

        //Objects
        static Player* player;
        static KeyboardHandler* keyboardHandler;
        static CollisionHandler* collisionHandler;
        static Window* window;
        static std::vector<Enemy*> enemies;

        //Threads
        static Thread* playerThread;
        static Thread* collisionHandlerThread;
        static Thread* keyboardHandlerThread;
        static Thread* windowThread;
        static std::vector<Thread*> enemiesThreads;

        static int killedEnemies;

        static void playerThreadFunction();

        static void collisionHandlerThreadFunction();

        static void keyboardHandlerThreadFunction();

        static void windowThreadFunction();

        static void enemiesThreadFunction(int index);
    };
} // namespace BrickShooter

#endif //controller_h
