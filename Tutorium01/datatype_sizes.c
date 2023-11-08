#include <stdio.h>

void print_size(char *name, int size) {
  printf("Size of %s: %d\n", name, size);
}

int main(int argc, char **argv) {
  (void)argc;
  (void)argv;
  print_size("char", sizeof(char));
  print_size("short", sizeof(short));
  print_size("int", sizeof(int));
  print_size("long", sizeof(long));
  print_size("long long", sizeof(long long));
  print_size("float", sizeof(float));
  print_size("double", sizeof(double));
  print_size("long double", sizeof(long double));

  int arr[5];
  print_size("int[5]", sizeof(arr));
  int *ptr = arr;
  print_size("int*", sizeof(ptr));
  return 0;
}
