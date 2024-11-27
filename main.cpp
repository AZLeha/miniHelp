#include <iostream>
#define LOG_LVL LOG_LVL_VERBOSE
#include "log.h"
#include <version.h>


int main(void)
{
    log_i(BUILD_SYSTEMS_VERSION);

    return 0;
}
