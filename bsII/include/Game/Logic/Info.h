#ifndef INFO_H
#define INFO_H

#include "Traits/Traits.h"

#include "Concurrency/semaphore.h"

namespace BrickShooter
{
    using Concurrency::Semaphore;

    class Info
    {
    public:
        Info();

        ~Info();

        int score;
        int lives;
        int level;

        static Semaphore *scoreSemaphore;
        static Semaphore *livesSemaphore;
        static Semaphore *levelSemaphore;

        void incraseScore();

        void decreaseLives();

        void increaseLevel();

    };
} // namespace BrickShooter

#endif //INFO_H
