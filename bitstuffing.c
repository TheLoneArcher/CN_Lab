#include <stdio.h>
#include <string.h>
int main() {
    char inputString[50], stuffedString[100] = "01111110", destuffedString[50] = "";
    int i, consecutiveOnesCount = 0;
    printf("Enter the string to stuff: ");
    scanf("%s", inputString);
    for (i = 0; i < (int)strlen(inputString); i++) {
        stuffedString[strlen(stuffedString)] = inputString[i];
        if (inputString[i] == '1') {
            consecutiveOnesCount++;
            if (consecutiveOnesCount == 5) {
                strcat(stuffedString, "0");
                consecutiveOnesCount = 0;
            }
        } else consecutiveOnesCount = 0;
    }
    strcat(stuffedString, "01111110");
    printf("String after stuffing: %s\n", stuffedString);
    consecutiveOnesCount = 0;
    for (i = 8; i < (int)strlen(stuffedString) - 8; i++) {
        destuffedString[strlen(destuffedString)] = stuffedString[i];
        if (stuffedString[i] == '1') {
            consecutiveOnesCount++;
            if (consecutiveOnesCount == 5) {
                i++;
                consecutiveOnesCount = 0;
            }
        } else
            consecutiveOnesCount = 0;
    }
    printf("String after destuffing: %s\n", destuffedString);
    return 0;
}