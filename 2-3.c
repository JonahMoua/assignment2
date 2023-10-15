//Used chatGPT, Stackoverflow and github to do this assignment
#include <stdio.h>

int ge(float x, float y) {
    unsigned int ux = *((unsigned int*) &x); // convert x raw bits
    unsigned int uy = *((unsigned int*) &y); // convert y raw bits
    unsigned int sx = ux >> 31; // extract sign bit of ux
    unsigned int sy = uy >> 31; // extract sign bit of uy   
    ux &= 0x7FFFFFFF; // drop sign bit of ux
    uy &= 0x7FFFFFFF; // drop sign bit of uy

    // the first condition is to check if both x and y are 0 and return 1 if true
    // the second condition is to check if they are the same sign positive/negative and if x is greater than or equal to uy
    // the last condition is a simple check to see if x is positive and y is negative to make it declared 1 immediately
    return (ux == 0 && uy == 0) || (sx == sy && ux >= uy) || (sx == 0 && sy == 1);

}


int main() {
    float a, b;

    a = 0.0f;
    b = 0.0f;
    printf("ge(%.1f, %.1f): %d\n", a, b, ge(a, b));

    a = -0.0f;
    b = 0.0f;
    printf("ge(%.1f, %.1f): %d\n", a, b, ge(a, b));

    a = 0.0f;
    b = -0.0f;
    printf("ge(%.1f, %.1f): %d\n", a, b, ge(a, b));

    a = -0.0f;
    b = -0.0f;
    printf("ge(%.1f, %.1f): %d\n", a, b, ge(a, b));

    a = 1.0f;
    b = 1.0f;
    printf("ge(%.1f, %.1f): %d\n", a, b, ge(a, b));

    a = -1.0f;
    b = 1.0f;
    printf("ge(%.1f, %.1f): %d\n", a, b, ge(a, b));

    a = 1.0f;
    b = -1.0f;
    printf("ge(%.1f, %.1f): %d\n", a, b, ge(a, b));

    a = -1.0f;
    b = -1.0f;
    printf("ge(%.1f, %.1f): %d\n", a, b, ge(a, b));

    a = -1.0f;
    b = 0.0f;
    printf("ge(%.1f, %.1f): %d\n", a, b, ge(a, b));

    a = 0.0f;
    b = -1.0f;
    printf("ge(%.1f, %.1f): %d\n", a, b, ge(a, b));

    a = 1.0f;
    b = 0.0f;
    printf("ge(%.1f, %.1f): %d\n", a, b, ge(a, b));

    a = 0.0f;
    b = 1.0f;
    printf("ge(%.1f, %.1f): %d\n", a, b, ge(a, b));

    a = 1.0f;
    b = 2.0f;
    printf("ge(%.1f, %.1f): %d\n", a, b, ge(a, b));

    a = 2.0f;
    b = 1.0f;
    printf("ge(%.1f, %.1f): %d\n", a, b, ge(a, b));

    a = -1.0f;
    b = -2.0f;
    printf("ge(%.1f, %.1f): %d\n", a, b, ge(a, b));

    a = -2.0f;
    b = -1.0f;
    printf("ge(%.1f, %.1f): %d\n", a, b, ge(a, b));

    return 0;
}
