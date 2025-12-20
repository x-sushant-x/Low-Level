#include <stdio.h>

#define N_KEYS 32

struct point {
    int x;
    int y;
};

struct rect {
    struct point p1;
    struct point p2;
};

struct point makepoint(int x, int y) {
    struct point temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

struct key {
    char* word;
    int count;
} keytab[N_KEYS] = {"auto",  0, "break",    0, "case",    0, "char",     0,
                    "const", 0, "continue", 0, "default", 0, "unsigned", 0,
                    "void",  0, "volatile", 0, "while",   0};

int main(int argc, char** argv) {
    struct rect screen;
    struct point makepoint(int, int);

    screen.p1 = makepoint(0, 0);
    screen.p2 = makepoint(5, 5);

    // Size of individual element is 16 not 12 (8 byte char + 4 byte int)
    // because of padding. CPU prefers data aligned to its natural boundaries.
    // Largest member = 8 bytes
    // Struct size must be a multiple of 8 So the compiler adds 4 bytes of
    // padding after count.
    printf("Keytab Size: %lu\n", sizeof(keytab[0]));

    printf("%s\t:\t%d\n", keytab[0].word, keytab[0].count);

    return 0;
}