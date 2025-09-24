// Write a C program for Cyclic Redundancy Test
#include <stdio.h>
#include <string.h>
void xor(char *dividend, char *divisor, int len) {
    for (int i = 1; i < len; i++)
        dividend[i] = (dividend[i] == divisor[i]) ? '0' : '1';
}
void crc(char *data, char *key, char *remainder) {
    int data_len = strlen(data);
    int key_len = strlen(key);
    char temp[100];
    strcpy(temp, data);
    for (int i = 0; i < key_len - 1; i++)
        temp[data_len + i] = '0';
    temp[data_len + key_len - 1] = '\0';
    for (int i = 0; i <= data_len; i++) {
        if (temp[i] == '1')
            xor(&temp[i], key, key_len);
    }
    strncpy(remainder, &temp[data_len], key_len - 1);
    remainder[key_len - 1] = '\0';
}
int main() {
    char data[100], key[20], remainder[20], codeword[120];
    printf("Enter data bits: ");
    scanf("%s", data);
    printf("Enter generator polynomial (key): ");
    scanf("%s", key);
    crc(data, key, remainder);
    strcpy(codeword, data);
    strcat(codeword, remainder);
    printf("CRC Remainder: %s\n", remainder);
    printf("Transmitted Codeword: %s\n", codeword);
    return 0;
}