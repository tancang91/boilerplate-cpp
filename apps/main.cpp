#include <cstdio>

#include "fib.h"

int main(int argc, char *argv[])
{
    int rel = fib(5);

    std::printf("Fib of 5: %d\n", rel);
    return 0;
}
