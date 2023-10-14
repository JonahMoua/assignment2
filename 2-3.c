//Used chatGPT, Stackoverflow and github to do this assignment
#include <stdio.h>

int ge(float x, float y) {
    unsigned int ux = *((unsigned int*) &x); // convert x raw bits
    unsigned int uy = *((unsigned int*) &y); // convert y raw bits
    unsigned int sx = ux >> 31; // extract sign bit of ux
    unsigned int sy = uy >> 31; // extract sign bit of uy   
    ux &= 0x7FFFFFFF; // drop sign bit of ux
    uy &= 0x7FFFFFFF; // drop sign bit of uy
    // TODO: return using sx, sy, ux, uy

    // Calculate the sign difference
    unsigned int signDiff = sx ^ sy;

    // Calculate the result
    return ((!(signDiff | ux - uy)) | (sx & !(sy))) & 1;
}

int main() {
    float a, b;

    a = 0.0f;
    b = 0.0f;
    printf("ge(%f, %f): %d\n", a, b, ge(a, b));

    a = -0.0f;
    b = 0.0f;
    printf("ge(%f, %f): %d\n", a, b, ge(a, b));

    a = 0.0f;
    b = -0.0f;
    printf("ge(%f, %f): %d\n", a, b, ge(a, b));

    a = -0.0f;
    b = -0.0f;
    printf("ge(%f, %f): %d\n", a, b, ge(a, b));

    a = 1.0f;
    b = 1.0f;
    printf("ge(%f, %f): %d\n", a, b, ge(a, b));

    a = -1.0f;
    b = 1.0f;
    printf("ge(%f, %f): %d\n", a, b, ge(a, b));

    a = 1.0f;
    b = -1.0f;
    printf("ge(%f, %f): %d\n", a, b, ge(a, b));

    a = -1.0f;
    b = -1.0f;
    printf("ge(%f, %f): %d\n", a, b, ge(a, b));

    a = -1.0f;
    b = 0.0f;
    printf("ge(%f, %f): %d\n", a, b, ge(a, b));

    a = 0.0f;
    b = -1.0f;
    printf("ge(%f, %f): %d\n", a, b, ge(a, b));

    a = 1.0f;
    b = 0.0f;
    printf("ge(%f, %f): %d\n", a, b, ge(a, b));

    a = 0.0f;
    b = 1.0f;
    printf("ge(%f, %f): %d\n", a, b, ge(a, b));

    a = 1.0f;
    b = 2.0f;
    printf("ge(%f, %f): %d\n", a, b, ge(a, b));

    a = 2.0f;
    b = 1.0f;
    printf("ge(%f, %f): %d\n", a, b, ge(a, b));

    a = -1.0f;
    b = -2.0f;
    printf("ge(%f, %f): %d\n", a, b, ge(a, b));

    a = -2.0f;
    b = -1.0f;
    printf("ge(%f, %f): %d\n", a, b, ge(a, b));

    return 0;
}