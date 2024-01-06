#ifndef window_h
#define window_h

#include <iostream>
#include <png.h>
#include <vector>

#include <SFML/Graphics.hpp>

#include "Traits/Traits.h"

#include "Concurrency/semaphore.h"

#include "Game/Control/Clock.h"

#include "Game/Interface/Drawable.h"

namespace BrickShooter
{
    using Concurrency::Semaphore;

    class BrickShooter;

    class Window
    {
    public:
        Window();

        void run();

        void quit();

        void pause();

        void close();

        void drawElements(double d);

        static void addElementToDraw(Drawable *element);

        static void removeElementToDraw(Drawable *element);

        static Semaphore *toBeDrawnSemaphore;
        static Semaphore *infoSemaphore;

        sf::RenderWindow *getWindow() {
            return window;
        }

        ~Window();

    private:
        void drawInfo();

        void drawPause();

        void drawGameOver();

        void drawBackground();

        bool closed = false;
        float lastTime;
        sf::RenderWindow *window;
        static std::vector<Drawable *> toBeDrawn;
        bool paused = false;
        sf::Clock clock;
        sf::Texture maze_tex;
        sf::Sprite maze_sprite;
        sf::Font font;
    };
} // namespace BrickShooter

#endif