#include<stdio.h>

void foo(int *addr) {
    printf("foo: %p\n", addr);
    printf("*foo: %d\n", *addr);
}


int main(int argc, char **argv) {
    (void) argc;
    (void) argv;
    int x = 1234;
    foo(&x);
}
