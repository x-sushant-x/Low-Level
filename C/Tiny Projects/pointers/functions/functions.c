#include <stdio.h>

int add(int a, int b) { return a + b; }

int perform_math(int a, int b, int (*ops)(int, int)) { return ops(a, b); }

int main(int argc, char** argv) {
    printf("Resp: %d\n", perform_math(1, 2, add));

    return 0;
}