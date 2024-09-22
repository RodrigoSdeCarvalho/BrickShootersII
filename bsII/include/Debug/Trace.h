#ifndef DB_TRACE_H
#define DB_TRACE_H

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
} 

#endif //DB_TRACE_H
