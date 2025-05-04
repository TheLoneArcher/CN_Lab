#include <stdio.h>
#include <string.h>
int main() {
    char originalData[50], stuffedFrame[100], destuffedFrame[50];
    int i = 0, j = 0, dataLength;
    char d = 'D', l = 'L', e = 'E', s = 'S', t = 'T', x = 'X';
    printf("Enter the string in uppercase to transmit: ");
    scanf("%s", originalData);
    dataLength = strlen(originalData);
    printf("\nStuffing...\n");
    strcpy(stuffedFrame, "DLE STX");
    j = 7;
    while (i < dataLength) {
        if (originalData[i] == d && originalData[i + 1] == l && originalData[i + 2] == e ||
            originalData[i] == s && originalData[i + 1] == t && originalData[i + 2] == x ||
            originalData[i] == e && originalData[i + 1] == t && originalData[i + 2] == x) {
            stuffedFrame[j++] = d;
            stuffedFrame[j++] = l;
            stuffedFrame[j++] = e;
        }
        stuffedFrame[j++] = originalData[i++];
    }
    strcat(stuffedFrame, "DLE ETX");
    printf("Frame after stuffing: %s\n", stuffedFrame);
    printf("\nDestuffing...\n");
    i = 7;
    j = 0;
    dataLength = strlen(stuffedFrame);
    while (i < dataLength - 7) {
        if (stuffedFrame[i] == d && stuffedFrame[i + 1] == l && stuffedFrame[i + 2] == e)
            i += 3;
        destuffedFrame[j++] = stuffedFrame[i++];
    }
    destuffedFrame[j] = '\0';
    printf("Frame after destuffing: %s\n", destuffedFrame);
    return 0;
}