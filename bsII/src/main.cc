#include "Game/Control/BrickShooter.h"
#include "Concurrency/system.h"
#include "Concurrency/traits.h"

__USING_API

int main()
{
    // Starts the game
    System::init(&BrickShooter::play);

    return 0;
}
