#include<stdio.h>

int main(void) {
    int a = 15;
    a += 1; // a = a + 1
    a -= 1; // a = a - 1
    a *= 1; // a = a * 1
    a /= 1; // a = a / 1
    a %= 100; // a = a % 100 (a modulo (division remainder) 100)
    a &= 0xFF; // a = a & 0xFF (bitwise AND)
    a |= 0x0; // a = a | 0x0 (bitwise OR)
    a ^= 0x0; // a = a ^ 0x0 (bitwise XOR)
    a <<= 1; // a = a << 1 (bitwise left shift)
    a >>= 1; // a = a >> 1 (bitwise right shift)
    printf("a = %d\n", a); // a = 15
}
