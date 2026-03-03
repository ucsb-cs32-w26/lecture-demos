#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <count>\n", argv[0]);
        return 1;
    }

    int count = atoi(argv[1]);

    while(1);

    for (int i = 0; i < count; i++) {
        printf("hello\n");
    }

    return 0;
}