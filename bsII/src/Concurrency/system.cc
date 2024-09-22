#include <iostream>
#include <ucontext.h>
#include <stdio.h>

#include "Debug/Info.h"

#include "Concurrency/system.h"
#include "Concurrency/thread.h"

namespace Concurrency
{
    void System::init(void (*main)(void *)) {
        Debug::Info<System, SHOW>() << "SYSTEM INICIADO." << Debug::endl;
        setvbuf(stdout, 0, _IONBF, 0); //setvbuf(FILE *stream, char *buf, int type, size_t size);

        Thread::init(main);
    }
}
