#ifndef TRAITS_H
#define TRAITS_H

// Class forward declarations

namespace Concurrency
{
    class CPU;
    class Thread;
    class System;
    class Lists;
    class Semaphore;
}

namespace BrickShooter
{
    // Control
    class BrickShooter;
    class Clock;
    class Config;
    class KeyboardHandler;

    // Logic
    class CollisionHandler;
    class Player;
    class Enemy;
    class Info;
    class Shot;

    // Interface
    class Window;
    class Drawable;
    class Collidable;
    class Sounds;
}

namespace Utils
{
    class Path;
    class Point;
    class Vector;
}

class Benchmark;

namespace Test
{
    class Function;
    class RESULT;
    class run;
}

namespace Debug
{
    class Debug;
}


// Traits
template<typename T> struct Traits {
    static const bool debugged = true;
};

template <> struct Traits<Debug::Debug> : public Traits<void> {
    static const bool error = true;
    static const bool warning = true;
    static const bool info = true;
    static const bool trace = true;
};


// Concurrency Traits
template<> struct Traits<Concurrency::CPU> : public Traits<Debug::Debug> {
    static const int STACK_SIZE = 80*1024;
};

template<> struct Traits<Concurrency::Thread> : public Traits<Debug::Debug> {
};

template<> struct Traits<Concurrency::System> : public Traits<Debug::Debug> {
};

template<> struct Traits<Concurrency::Lists> : public Traits<Debug::Debug> {
};

template<> struct Traits<Concurrency::Semaphore> : public Traits<Debug::Debug> {
};


// BrickShooter Traits

// Control
template<> struct Traits<BrickShooter::BrickShooter> : public Traits<Debug::Debug> {
};

template<> struct Traits<BrickShooter::Clock> : public Traits<Debug::Debug> {
};

template<> struct Traits<BrickShooter::Config> : public Traits<Debug::Debug> {
};

template<> struct Traits<BrickShooter::KeyboardHandler> : public Traits<Debug::Debug> {
};

// Logic
template<> struct Traits<BrickShooter::CollisionHandler> : public Traits<Debug::Debug> {
};

template<> struct Traits<BrickShooter::Player> : public Traits<Debug::Debug> {
};

template<> struct Traits<BrickShooter::Enemy> : public Traits<Debug::Debug> {
};

template<> struct Traits<BrickShooter::Info> : public Traits<Debug::Debug> {
};

template<> struct Traits<BrickShooter::Shot> : public Traits<Debug::Debug> {
};

// Interface
template<> struct Traits<BrickShooter::Window> : public Traits<Debug::Debug> {
};

template<> struct Traits<BrickShooter::Drawable> : public Traits<Debug::Debug> {
};

template<> struct Traits<BrickShooter::Collidable> : public Traits<Debug::Debug> {
};

template<> struct Traits<BrickShooter::Sounds> : public Traits<Debug::Debug> {
};

// Utils Traits
template <> struct Traits<Utils::Path> : public Traits<Debug::Debug> {
};

template <> struct Traits<Utils::Point> : public Traits<Debug::Debug> {
};

template <> struct Traits<Utils::Vector> : public Traits<Debug::Debug> {
};


// Benchmark Traits
template <> struct Traits<Benchmark> : public Traits<Debug::Debug> {
};


// Test Traits
template <> struct Traits<Test::Function> : public Traits<Debug::Debug> {
};

template <> struct Traits<Test::RESULT> : public Traits<Debug::Debug> {
};

template <> struct Traits<Test::run> : public Traits<Debug::Debug> {
};

#endif //TRAITS_H
