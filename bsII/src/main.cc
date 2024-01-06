#include "Debug/Info.h"
#include "Concurrency/system.h"
#include "Game/Control/BrickShooter.h"

#define Game BrickShooter::BrickShooter // "using BrickShooter::BrickShooter" is ambiguous

int main()
{
    using Concurrency::System;

    // Starts the game
    Debug::Info<Game, SHOW>() << "INFO(GAME): " << "BRICK SHOOTER STARTED." << Debug::endl;
    System::init(&Game::play);

    return 0;
}
