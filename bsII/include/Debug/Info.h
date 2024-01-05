#ifndef INFO_HPP
#define INFO_HPP

#include "Traits/Traits.h"
#include "Debug/Debug.h"

namespace Debug
{
    template <typename T, Visibility v>
    inline SelectDebug<v && Traits<T>::debugged && Traits<Debug>::info && Traits<T>::info> Info()
    {
        if constexpr (v)
        {
            SelectDebug<v && Traits<T>::debugged && Traits<Debug>::info && Traits<T>::info>() << Debug::begl;
            return SelectDebug<v && Traits<T>::debugged && Traits<Debug>::info && Traits<T>::info>();
        }
        else
        {
            return SelectDebug<false>();
        }
    }
} // namespace Debug

#endif //INFO_HPP
