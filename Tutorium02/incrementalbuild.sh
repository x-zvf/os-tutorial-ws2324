#!/bin/sh

gcc -E test.c -o test.i # Preprocess
gcc -S test.i -o test.s # Compile to assembly
gcc -c test.s -o test.o # Assemble
gcc test.o -o test      # Link

