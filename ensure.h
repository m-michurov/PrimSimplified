#pragma once

#ifndef PRIM_ENSURE_H
#define PRIM_ENSURE_H


#include <stdio.h>
#include <stdlib.h>


#ifndef ensure
#define ensure(expression, message, func, data, exit_code) \
{ \
    if (!(expression)) { \
        if (func != NULL) \
            func(data); \
            printf("%s\n", message); \
            return exit_code; \
    } \
}
#endif

#endif
