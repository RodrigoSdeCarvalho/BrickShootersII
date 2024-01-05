#ifndef TRACE_HPP
#define TRACE_HPP

#include "Traits/Traits.h"
#include "Debug/Debug.h"

namespace Debug
{
    template <typename T, Visibility v>
    inline SelectDebug<v && Traits<T>::debugged && Traits<Debug>::trace && Traits<T>::trace> Trace()
    {
        if constexpr (v)
        {
            SelectDebug<v && Traits<T>::debugged && Traits<Debug>::trace && Traits<T>::trace>() << Debug::begl;
            return SelectDebug<v && Traits<T>::debugged && Traits<Debug>::trace && Traits<T>::trace>();
        }
        else
        {
            return SelectDebug<false>();
        }
    }
} // namespace Debug

#endif //TRACE_HPP
