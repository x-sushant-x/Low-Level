#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int str_len(char* c);
void strcpy_v2(char* so, char* to);

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

    char name[] = "Sushant";
    char* surname = malloc(sizeof(char) * 7);
    strcpy(surname, "Dhiman");

    printf("Size of name: %d\n", str_len(name));
    printf("Size of surname: %d\n", str_len(surname));
    printf("Size of text: %d\n", str_len("text"));

    printf("name ptr: %p\n", name);

    // Doing name = new_name will only change pointer of name. This actually do
    // not copy values. So we will use strcpy function.
    char new_name[] = "Kevin";
    // name = new_name;

    strcpy_v2(new_name, name);

    printf("new name ptr: %p\n", new_name);
    printf("name: %s\n", name);
    printf("name ptr: %p\n", name);

    return 0;
}

int str_len(char* c) {
    int n = 0;
    int i;

    for (i = 0; c[i] != '\0'; i++) {
        n++;
    }

    return n;
}

void strcpy_v2(char* so, char* to) {
    int i = 0;

    while ((to[i] = so[i]) != '\0') {
        i++;
    }
}

int str_cmp(char* s, char* t) {
    int i;

    for (i = 0; s[i] == t[i]; i++) {
        if (s[i] == '\0') {
            return 0;
        }
    }

    return s[i] - t[i];
}