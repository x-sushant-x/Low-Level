#include <fcntl.h>
#include <stdio.h>

int main(int argc, char** argv) {
    int fd = open("main.c", O_RDWR);

    return 0;
}