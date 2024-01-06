#ifndef DB_WARNING_H
#define DB_WARNING_H

#include "Traits/Traits.h"
#include "Debug/Debug.h"

namespace Debug
{
    template <typename T, Visibility v>
    inline SelectDebug<v && Traits<T>::debugged && Traits<Debug>::warning && Traits<T>::warning> Warning()
    {
        if constexpr (v)
        {
            SelectDebug<v && Traits<T>::debugged && Traits<Debug>::warning && Traits<T>::warning>() << Debug::begl;
            return SelectDebug<v && Traits<T>::debugged && Traits<Debug>::warning && Traits<T>::warning>();
        }
        else
        {
            return SelectDebug<false>();
        }
    }
} 

#endif //DB_WARNING_H
