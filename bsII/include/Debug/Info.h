#ifndef DB_INFO_H
#define DB_INFO_H

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
} 

#endif //DB_INFO_H
