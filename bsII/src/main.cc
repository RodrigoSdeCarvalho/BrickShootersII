#include "Game/Control/BrickShooter.h"
#include "Concurrency/system.h"
#include "Concurrency/traits.h"
#include "Game/Control/Config.h"

__USING_API

int main(void)
{
    // Starts the game
    System::init(&BrickShooter::play);

    return 0;
}
