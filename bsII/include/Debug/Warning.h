#ifndef WARNING_HPP
#define WARNING_HPP

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
} // namespace Debug

#endif //WARNING_HPP
