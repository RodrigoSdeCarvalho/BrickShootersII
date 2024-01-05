#ifndef FUNCTION_HPP
#define FUNCTION_HPP

#include <string>

namespace Test
{
    typedef void (*FunctionPointer)();

    struct Function
    {
        FunctionPointer call;
        std::string name;

        Function(FunctionPointer func, const std::string& n) : call(func), name(n) {}

        void operator()() const
        {
            call();
        }
    };
}

#endif //FUNCTION_HPP
