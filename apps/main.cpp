#include <cstdio>

#include "fib.h"

int main(int argc, char *argv[])
{
    int N = 10;
    int rel = fib(N);

    std::printf("Fib of %d: %d\n", N, rel);
    return 0;
}
