#ifndef CONFIGS_H
#define CONFIGS_H

#include <iostream>
#include <ucontext.h>

#include "Concurrency/semaphore.h"

#include "Traits/Traits.h"

namespace BrickShooter
{
    using Concurrency::Semaphore;

    class Config
    {
    public:
        static Semaphore *finishedSemaphore;
        static Semaphore *pausedSemaphore;
        static Semaphore *gameOverSemaphore;

        static int windowWidth;
        static int windowHeight;
        static int playableAreaWidth;
        static int playableAreaHeight;
        static int infoAreaWidth;
        static int fps;
        static int lives;
        static int enemiesPerLevel;
        static int maxLevel;

        static bool getFinished();

        static bool getPaused();

        static bool getGameOver();

        static bool finished;
        static bool paused;
        static bool gameOver;

        static void deleteSemaphores();
    };
} // namespace BrickShooter

#endif //CONFIGS_H
