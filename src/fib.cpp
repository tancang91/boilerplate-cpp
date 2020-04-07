int fib(int N) {
    if (N == 0)
        return 0;
    else if (N == 1)
        return 1;

    int rel, a, b;
    a = 0; b = 1;
    for(int i = 2; i <= N; ++i) {
        rel = a + b;
        a = b;
        b = rel;
    }
    return rel;
}
