#include <stdio.h>

unsigned int extract(unsigned int x, int i) {
    // we calculate the shift amount. i << 3 is equivalent to i * 8
    unsigned int shift = i << 3;
    // This line extracts the desired byte from x. 
    // It first shifts x right by the calculated shift bits (which is i * 8) to position the byte of interest as the least significant byte. 
    // Then, it applies a bitmask 0xFF (which is 00000000 00000000 00000000 11111111 in binary) 
    // to extract only the least significant 8 bits, effectively isolating the desired byte.
    unsigned int result = (x >> shift) & 0xFF;

    // Calculate the sign bit and sign-extend
    // Here, we determine the sign bit of the extracted byte and create a sign extension mask. 
    // The expression (result & 0x80) checks if the most significant bit (the sign bit) of result is set. If it is, it returns 0xFFFFFF00, which is a sign extension for a negative number. 
    // If the sign bit is not set (indicating a positive or zero value), it returns 0x00, which signifies no sign extension
    unsigned int signBit = (result & 0x80) ? 0xFFFFFF00 : 0x00;
    return result | signBit;
}


int main() {
    unsigned int x;
    int i;

    // Test the extract function for value x = 0x12345678 and i value of 0.
    x = 0x12345678;
    i = 0;
    unsigned int result = extract(x, i);
    printf("extract(0x%08X, %d): 0x%08X\n", x, i, result);

    // Test the extract function for value x = 0xABCDEF00 and i value of 2.
    x = 0xABCDEF00;
    i = 2; // Set i to the desired value
    unsigned int result2 = extract(x, i);
    printf("extract(0x%08X, %d): 0x%08X", x, i, result2);

    return 0;
}
