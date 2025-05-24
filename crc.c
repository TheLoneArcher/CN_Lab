#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 100
void performXOR(char *dividend, char *divisor, int keyLength) {
    for (int i = 0; i < keyLength; i++) dividend[i] = (dividend[i] == divisor[i]) ? '0' : '1'; // check if it's exclusive or (XOR)
}
void calculateCRC(char *data, int dataLength, char *key, int keyLength, char *quotient, char *remainder) {
    char temp[30]; 
    strcpy(temp, data); // use strcpy because assigment operator doesn't work for strings
    for (int i = 0; i < dataLength; i++) { 
        quotient[i] = temp[0]; // store the first bit of temp in quotient because it will be used for the XOR operation
        if (quotient[i] == '1') performXOR(temp, key, keyLength); // perform XOR operation if the first bit of temp is 1
        for (int j = 0; j < keyLength - 1; j++) temp[j] = temp[j + 1];
        temp[keyLength - 1] = data[i + keyLength];
    }
    strncpy(remainder, temp, keyLength - 1);
    remainder[keyLength - 1] = '\0';
}
int main() {
    char data[MAX_SIZE], key[30], quotient[MAX_SIZE], remainder[30], originalKey[30], received[MAX_SIZE];
    int i, dataLen, keyLen, error = 0;
    printf("Enter data: ");
    scanf("%s", data);
    printf("Enter key: ");
    scanf("%s", key);
    keyLen = strlen(key);
    dataLen = strlen(data);
    strcpy(originalKey, key);
    for (i = 0; i < keyLen - 1; i++) data[dataLen + i] = '0';
    data[dataLen + keyLen - 1] = '\0';
    calculateCRC(data, dataLen, originalKey, keyLen, quotient, remainder);
    printf("\nQuotient: %s", quotient);
    printf("\nRemainder (CRC): %s", remainder);
    printf("\nTransmitted Data: %s%s\n", data, remainder);
    printf("\nEnter received data: ");
    scanf("%s", received);
    calculateCRC(received, dataLen, originalKey, keyLen, quotient, remainder);
    printf("\nReceived Remainder: %s", remainder);
    for (i = 0; i < keyLen - 1; i++) {
        if (remainder[i] == '1') {
            error = 1;
            break;
        }
    }
    if (error == 0) printf("\nNo Error Detected\n");
    else printf("\nError Detected\n");
    return 0;
}