#include <stdio.h>

const int N = 500000;
const int t = 2;
int tally;

void total(int N)
{
    for (int i = 0; i < N; ++i) {
        tally += 1;
    }
}

int main()
{
    tally = 0;

#pragma omp parallel for
    for (int i = 0; i < t; ++i) {
        total(N);
    }

    printf("%d (should be %d)\n", tally, t * N);

    return 0;
}
