#include<stdio.h>
#include<inttypes.h>

struct A {
    char a;
    int b;
};

struct B {
    char *a;
    int c;
};

struct C {
    int a;
};

struct D {
    int8_t a;
    int16_t b;
    int32_t c;
    int64_t d;
};

struct E {
    int64_t a;
    int32_t b;
    int16_t c;
    int8_t d;
};

struct F {
    uint64_t a;
    uint64_t b;
    uint64_t c;
    uint64_t d;
};

#define PRINT_LAYOUT(x) \
    printf("sizeof(%1$s) = %2$zu\nalignof(%1$s) = %3$zu\n", #x, sizeof(x), _Alignof(x))

int main(void) {
    PRINT_LAYOUT(struct A);
    PRINT_LAYOUT(struct B);
    PRINT_LAYOUT(char *);
    PRINT_LAYOUT(struct C);
    PRINT_LAYOUT(struct D);
    PRINT_LAYOUT(struct E);
    PRINT_LAYOUT(struct F);
    return 0;
}

