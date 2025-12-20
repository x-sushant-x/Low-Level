#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE 2

int main(int argc, char** argv) {
    int arr[2][2] = {{1, 2}, {3, 4}};

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d\t", arr[i][j]);
        }

        printf("\n");
    }

    int rows, cols = 2;

    int (*new_arr)[rows] = malloc(rows * sizeof(*new_arr));

    return 0;
}