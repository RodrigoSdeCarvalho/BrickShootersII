#ifndef keyboardHandler_h
#define keyboardHandler_h

#include <iostream>
#include <queue>
#include <string>
#include <map>

#include <SFML/Graphics.hpp>

#include "Traits/Traits.h"

#include "Concurrency/semaphore.h"
#include "Concurrency/thread.h"

#include "Game/Control/Play.h"
#include "Game/Control/Clock.h"

#include "Game/Interface/window.h"

namespace BrickShooter
{
    using Concurrency::Semaphore;

    class BrickShooter;

    class KeyboardHandler
    {
    public:
        struct keys {
            Play::KeyPress moveKey;
            Play::KeyPress actionKey;
        };

        KeyboardHandler(Window *window);

        ~KeyboardHandler();

        typedef sf::Event Event;

        void run();

        static Semaphore *eventQueueSemaphore;
        static Semaphore *saveEventsSemaphore;

        keys getNextKey();

        bool saveEvents = true;

    private:
        static std::map<sf::Keyboard::Key, bool> keyStates;

        keys getPressedKey();

        Window *window;
        std::queue<keys> eventQueue;
        Clock actionClock;
    };
} // namespace BrickShooter

#endif
