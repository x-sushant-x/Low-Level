#include <stdio.h>

void print_int_arr(int* arr, int size) {
    int* p = arr;

    while (p < arr + size) {
        printf("%d\t:\t%p\n", *p, p);
        p++;
    }
    printf("\n");
}

void print_char_arr(char* arr, int size) {
    char* p = arr;

    while (p < arr + size) {
        printf("%c\t:\t%p\n", *p, p);
        p++;
    }
    printf("\n");
}

void print_string_arr(char* arr[], int size) {
    char** p = arr;

    while (p < arr + size) {
        printf("%s\t:\t%p\n", *p, p);
        p++;
    }
    printf("\n");
}

typedef enum { INT, CHAR, STRING } DataType;

void print_anything(void* arr, int size, DataType type) {
    for (int i = 0; i < size; i++) {
        if (type == INT) {
            int* p = (int*)arr;
            printf("%d\t:\t%p\n", p[i], &p[i]);
        }

        else if (type == CHAR) {
            char* p = (char*)arr;
            printf("%c\t:\t%p\n", p[i], &p[i]);
        }

        else if (type == STRING) {
            char** p = (char**)arr;
            printf("%s\t:\t%p\n", p[i], &p[i]);
        }
    }

    printf("\n");
}

int main() {
    int i_arr[] = {1, 2, 3, 4};
    print_int_arr(i_arr, sizeof(i_arr) / sizeof(i_arr[0]));

    char c_arr[] = {'a', 'b', 'c'};
    print_char_arr(c_arr, 3);

    char* s_arr[] = {"Hello", "World"};
    print_string_arr(s_arr, 2);

    print_anything(i_arr, 4, INT);
    print_anything(c_arr, 3, CHAR);
    print_anything(s_arr, 2, STRING);

    return 0;
}
