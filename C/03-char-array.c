#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 100

int get_line(char s[], int limit);
void copy(char from[], char to[]);

int main() {
    int len, max = 0;

    char line[MAXLINE];
    char longest[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(line, longest);
        }
    }

    if (max > 0) {
        printf("Longest Line Length: %d\n", max);
        printf("Longest Line: %s\n", longest);
    }

    return 0;
}

int get_line(char s[], int limit) {
    int c, i;

    for (i = 0; i < limit - 1 && (c = getchar()) != EOF & c != '\n'; i++) {
        s[i] = c;
    }

    if (c == '\n') {
        s[i] = c;
        i++;
    }

    s[i] = '\0';

    return i;
}

void copy(char from[], char to[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\0') i++;
}
