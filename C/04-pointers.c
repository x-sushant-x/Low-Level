#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    int x = 0;
    int* p = &x;

    printf("P1: %p\n", p);
    printf("V1: %d\n", *p);

    *p = 10;

    printf("\nP2: %p\n", p);
    printf("V1: %d\n", *p);

    int* y = malloc(sizeof(int) * 5);

    y[0] = 14;
    y[1] = 76;
    y[2] = 43;
    y[3] = 99;
    y[4] = 10;

    p = &y[0];
    printf("\nP3: %p\n", p);
    p = &y[1];
    printf("\nP4: %p\n", p);

    p++;  // This will increment pointer by 4 instead of 1 because we are
          // incementing by 1 int whose size if 4 byte in our system.
    printf("\nP5: %p\n", p);

    return 0;
}