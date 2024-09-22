#ifndef DB_ERROR_H
#define DB_ERROR_H

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
} 

#endif //DB_ERROR_H
