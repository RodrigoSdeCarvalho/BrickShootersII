#ifndef DEBUG_HPP
#define DEBUG_HPP

#include <iostream>
#include "Traits/Traits.h"
#include <string>

enum Visibility
{
    SHOW = true,
    HIDE = false
};

namespace Debug
{
    static std::string endl = "\n";

    class Debug
    {
    public:
        template<typename T>
        Debug & operator<<(T p) {
            std::cout << p;
            return *this;
        }

        struct Begl {};
        struct Err {};

        Debug & operator<<(const Begl & begl) {
            return *this;
        }

        Debug & operator<<(const Err & err) {
            _error = true;
            return *this;
        }

        static Begl begl;
        static Err error;

    private:
        volatile bool _error;
    };

    class NullDebug
    {
    public:
        template<typename T>
        NullDebug & operator<<(const T & o)
        {
            return *this;
        }

        template<typename T>
        NullDebug & operator<<(const T * o)
        {
            return *this;
        }
    };

    template<bool debugged>
    class SelectDebug: public Debug {};
    template<>
    class SelectDebug<false>: public NullDebug {};
}

#endif //DEBUG_HPP
