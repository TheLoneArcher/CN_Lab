#include <stdio.h>
#include <string.h> // for strlen and strcat and strcpy too
// syntaxes for strlen, strcat and strcpy:
// strlen(string) returns the length of the string
// strcat(destination, source) appends the source string to the destination string
// strcpy(destination, source) copies the source string to the destination string
// Note: strcat and strcpy are not safe functions, they do not check for buffer overflow
int main() {
    char originalData[50], stuffedFrame[100], destuffedFrame[50]; // get original data, then stuff and destuff it
    int i = 0, j = 0, dataLength; // i is the index for original data, j is the index for stuffed frame, and dataLength is the length of the original data
    // DLE STX and DLE ETX are the flags for start and end of the frame
    char d = 'D', l = 'L', e = 'E', s = 'S', t = 'T', x = 'X';
    printf("Enter the string in uppercase to transmit: ");
    scanf("%s", originalData);
    dataLength = strlen(originalData); // implicit conversion takes place to int
    printf("\nStuffing...\n");
    strcpy(stuffedFrame, "DLE STX");
    j = 7;
    while (i < dataLength) {
        if (originalData[i] == d && originalData[i + 1] == l && originalData[i + 2] == e ||
            originalData[i] == s && originalData[i + 1] == t && originalData[i + 2] == x ||
            originalData[i] == e && originalData[i + 1] == t && originalData[i + 2] == x) { // if the original data contains DLE, STX or ETX, I have to stuff it with DLE so that it doesn't get confused with the flags
            stuffedFrame[j++] = d;
            stuffedFrame[j++] = l;
            stuffedFrame[j++] = e;
        }
        stuffedFrame[j++] = originalData[i++]; // if no flags present then just copy the original data to the stuffed frame using the j index for stuffed and i for original data
    }
    strcat(stuffedFrame, "DLE ETX"); // append the end flag to the stuffed frame
    printf("Frame after stuffing: %s\n", stuffedFrame);
    printf("\nDestuffing...\n");
    i = 7; // skip the first 7 bits (the flags) of the stuffed frame
    j = 0; // for the destuffed frame
    dataLength = strlen(stuffedFrame); // get the length of the stuffed frame
    while (i < dataLength - 7) { // skip the last 7 bits (the flags) of the stuffed frame
        if (stuffedFrame[i] == d && stuffedFrame[i + 1] == l && stuffedFrame[i + 2] == e)
            i += 3;
        destuffedFrame[j++] = stuffedFrame[i++];
    }
    destuffedFrame[j] = '\0'; // null terminate the destuffed frame
    printf("Frame after destuffing: %s\n", destuffedFrame);
    return 0;
}