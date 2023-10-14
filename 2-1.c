//Used chatGPT, Stackoverflow and github to do this assignment
#include <stdio.h>

unsigned int mask(int n) {
    return ((1u << n) - 1u);
}

int main() {
    int n;
    
    for (n = 1; n <= 31; n++) {
        unsigned int result = mask(n);
        printf("mask(%d): 0x%X\n", n, result);
    }

    return 0;
}