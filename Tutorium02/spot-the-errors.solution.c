#include<stdio.h>     // <> instead of ""
#include<inttypes.h>  //

void product(size_t length, /* size_t, not ssize_t */
        int64_t *array, int64_t *result) {
    *result = 1;
    // size_t instead of int
    for (size_t i = 0; i < length; i++) {
        *result *= array[i];
    }
}

int random_number(void) { //explicit void, else any number of arguments are allowed
    return 4; // chosen by fair dice roll.
              // guaranteed to be random.
}

#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))

#define MAX(a, b) ((a) > (b) ? (a) : (b))

// swapped argc and argv (c = count, v = vector)
int main(int argc, char **argv) {
    int i;
    for (i = 0; i < argc; i++) {
        printf("arg %d: %s\n", i, argv[i]);
    }

    int64_t array[] = {1, 2, 3, 4, 5};
    int64_t result;
    product(NELEMS(array), array, &result); //sizeof is not correct
    printf("product: %" PRId64 "\n", result); // Format specifier for int64_t

    printf("random number: %d\n", random_number());

    printf("max of 1 and 2: %d\n", MAX(3, random_number()));

    return 0;
}
