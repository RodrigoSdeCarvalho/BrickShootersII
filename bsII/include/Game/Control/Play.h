#ifndef PLAY_H
#define PLAY_H

#include "Traits/Traits.h"

namespace BrickShooter
{
    namespace Play
    {
        enum KeyPress {
            UP = 0,
            DOWN = 1,
            RIGHT = 2,
            LEFT = 3,
            SHOOT = 4,
            QUIT = 5,
            RESTART = 6,
            PAUSE = 7,
            NONE = 8
        };
    } // namespace Play
} // namespace BrickShooter

#endif //PLAY_H
