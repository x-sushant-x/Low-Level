#include <stdio.h>

// A union is a user-defined data type in C that allows different variables to
// share the same memory location.

// In struct each member have it's own memory. Total size of struct is total sum
// of members size + padding.

// But in case of union, size of union is size of largest member.

union U {
    int i;    // 4 bytes
    float f;  // 4 bytes
    char c;   // 1 byte
} U;

struct S {
    int i;    // 4 bytes
    float f;  // 4 bytes
    char c;   // 1 byte
} S;

union Number {
    int i;
    float f;
};

union Number arr[5];  // Size will be 5 * 4 bytes = 20. In case of struct it
                      // will be 5 * 8 bytes = 40

int main(int argc, char** argv) {
    printf("Size of struct: %lu\n", sizeof(S));
    printf("Size of union: %lu\n", sizeof(U));

    union U u;

    u.i = 10;
    u.f = 3.14;

    printf("union i: %d\n", u.i);  // Will print garbage value because u.f
                                   // = 3.14 overwrite previous written value.
    printf("union f: %f\n", u.f);

    printf("Size of array: %lu\n", sizeof(arr));

    arr[0].i = 10;
    arr[1].f = 3.14;

    return 0;
}