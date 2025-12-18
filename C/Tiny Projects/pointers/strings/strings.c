#include <stdio.h>

int main(int argc, char** argv) {
    // String literals are stored in Read Only Memory.
    // a is a pointer that points to the 1st character.
    // printf starts at a and print until it find '\0'
    // Layout in memory - 'H' 'e' 'l' 'l' 'o' '\0'
    char* a = "Hello";

    // b is not a string literal, instead it is a character array.
    // printf function will start printing it and go beyond array because there
    // is no '\0' at the end. this will print garbage value and eventually stops
    // when it find '\0' in memory.
    char b[] = {'H', 'e', 'l', 'l', 'o'};

    // Correct way to create b
    char c[] = "Hello";

    printf("%s\n", a);
    printf("%s\n", b);
    printf("%s\n", c);

    printf("%lu\n", sizeof(a));
    printf("%lu\n", sizeof(b));
    printf("%lu\n", sizeof(c));

    // Modification can't be done with a as it is string literal and stored in
    // read only memory.

    // a[0] = 'T'; // This will cause bus error.

    // Opposite in case of character arrays

    c[0] = 'T';

    printf("%s\n", c);

    return 0;
}
