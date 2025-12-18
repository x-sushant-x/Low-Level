#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE 8

int main(int argc, char** argv) {
    int* arr = malloc(sizeof(int) * INITIAL_SIZE);

    int curr_size = 0;
    int capacity = INITIAL_SIZE;

    for (int i = 0; i < 24; i++) {
        if (curr_size >= capacity) {
            printf("Increasing Capacity\n");

            capacity = capacity * 2;
            int* new_arr = realloc(arr, sizeof(int) * capacity);
            if (!new_arr) {
                free(arr);
                printf("Unable to allocate more memory\n");
                return 1;
            }

            arr = new_arr;

            printf("New Capacity: %d\n", capacity);
        }

        arr[curr_size] = i;
        curr_size++;
    }

    return 0;
}