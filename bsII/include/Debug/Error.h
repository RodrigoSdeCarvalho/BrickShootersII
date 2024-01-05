#ifndef ERROR_HPP
#define ERROR_HPP

#include "Traits/Traits.h"
#include "Debug/Debug.h"

namespace Debug
{
    template <typename T, Visibility v>
    inline SelectDebug<v && Traits<T>::debugged && Traits<Debug>::error && Traits<T>::error> Error()
    {
        if constexpr (v)
        {
            SelectDebug<v && Traits<T>::debugged && Traits<Debug>::error && Traits<T>::error>() << Debug::begl;
            SelectDebug<v && Traits<T>::debugged && Traits<Debug>::error && Traits<T>::error>() << Debug::error;
            return SelectDebug<v && Traits<T>::debugged && Traits<Debug>::error && Traits<T>::error>();
        }
        else
        {
            return SelectDebug<false>();
        }
    }
} // namespace Debug

#endif //ERROR_HPP
