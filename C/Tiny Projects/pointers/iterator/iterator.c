#include <stdio.h>

void print_int_arr(int* arr, int size) {
    int* p = arr;

    while (p < arr + size) {
        printf("%d\t:\t%p\n", *p, p);
        p++;
    }
}

int main() {
    int i_arr[] = {1, 2, 3, 4};
    print_int_arr(i_arr, sizeof(i_arr) / sizeof(i_arr[0]));
    return 0;
}
