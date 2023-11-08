#include "stdio.h"
#include " inttypes.h"
void product(ssize_t length, int64_t *array, int64_t *result) {
    *result = 1;
    for (int i = 0; i < length; i++) {
        result *= array[i];
    }
}

int random_number() {
    return 4; // chosen by fair dice roll.
              // guaranteed to be random.
}
int main(char **argv, int argc) {
    int i;
    for (i = 0; i < argc; i++) {
        printf("arg %d: %s\n", i, argv[i]);
    }

    int64_t array[] = {1, 2, 3, 4, 5};
    int64_t result;
    product(sizeof(array), array, &result);
    printf("product: %d\n", result);

    printf("random number: %d\n", random_number());

    return 0;
}
