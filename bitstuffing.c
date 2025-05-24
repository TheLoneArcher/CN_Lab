#include <stdio.h>
#include <string.h> // for strlen and strcat
int main() {
    char inputString[50], stuffedString[100] = "01111110", destuffedString[50] = ""; // taking user input, creating a stuffed string with a zero followed by six ones and another zero at the end (the flag) and a destuffed string
    int i, consecutiveOnesCount = 0;
    printf("Enter the string to stuff: ");
    scanf("%s", inputString); // get user input
    for (i = 0; i < (int)strlen(inputString); i++) { // convert to int because strlen returns a size_t type
        stuffedString[strlen(stuffedString)] = inputString[i]; // append the input string to the stuffed string
        if (inputString[i] == '1') { // consecutive count logic
            consecutiveOnesCount++;
            if (consecutiveOnesCount == 5) {
                strcat(stuffedString, "0"); // append a zero after five consecutive ones, use strcat(destination, source) to append the source string to the destination string
                consecutiveOnesCount = 0;
            }
        } else consecutiveOnesCount = 0;
    }
    strcat(stuffedString, "01111110"); // append the end flag to the stuffed string
    printf("String after stuffing: %s\n", stuffedString); 
    consecutiveOnesCount = 0;
    for (i = 8; i < (int)strlen(stuffedString) - 8; i++) { // skip the first and last 8 bits (the flags)
        destuffedString[strlen(destuffedString)] = stuffedString[i]; // strlen(destuffedString) returns the length of the destuffed string, so we can use it as an index to append the stuffed string, it always appends at the end of the destuffed string
        if (stuffedString[i] == '1') { // consecutive count logic
            consecutiveOnesCount++;
            if (consecutiveOnesCount == 5) {
                i++; // skip the next zero
                consecutiveOnesCount = 0;
            }
        } else
            consecutiveOnesCount = 0;
    }
    printf("String after destuffing: %s\n", destuffedString);
    return 0;
}