#include <iostream>

#include "Core.h"
#include "Log.h"

int main() {
    Snow::Log::init();
    SNOW_CORE_TRACE("Look! It started snowing!");

    return 0;
}
