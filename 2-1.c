//Used chatGPT, Stackoverflow and github to do this assignment
#include <stdio.h>

unsigned int mask(int n) { //mask is the function
    return ((1u << n) - 1u);
    // shift 1 to the left by n then subtract 1 
    // creates a binary with specific pattern of 1 and 0
}

int main() {
    int n;
    
    for (n = 1; n <= 31; n++) {
        //n= keeps track of how many time we loop
        //runs a loop as long as n is equal or less then 31 then it ends
        // n++ means each time it loops n increases
        
        unsigned int result = mask(n);
        
        //calculates results using the function and stores it in the variable
        // allows us to perform the loop from 1-31 without having to chanbge the input everytime. 
     
        printf("mask(%d): 0x%X\n", n, result);
        //prints results in a specfic format, with the results inserted in specfic spots
    }

    return 0;
}
