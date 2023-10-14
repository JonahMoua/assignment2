//Used chatGPT, Stackoverflow and github to do this assignment
#include <stdio.h>

unsigned int extract(unsigned int x, int i) {
    // Shift the byte i want to the right towards the least significant position 
    // FF is a placeholder which gents replaced 
    return (x >> (i * 8)) & 0xFF;
}

int main() {
    unsigned int x;
    int i;

    // Test the extract function for value x = 0x12345678 and i value of 0.
    x = 0x12345678;
    i = 0;
    unsigned int result = extract(x, i);
    if (result != 0) {
        printf("extract(0x%08X, %d): 0x%08X\n", x, i, result);
    }

    // Test the extract function for value x = 0xABCDEF00 and i value of 0 and 2.
    x = 0xABCDEF00;
    for (i = 0; i <= 2; i += 2) {
        unsigned int result = extract(x, i);
        if (result != 0) {
            printf("extract(0x%08X, %d): 0x%08X\n", x, i, result);
        }
    }

    return 0;
}
