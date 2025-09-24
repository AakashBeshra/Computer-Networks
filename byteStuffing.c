// Write a C program for byte stuffing
#include <stdio.h>
#include <string.h>
#define FLAG '~'
#define ESCAPE '}'
void byteStuffing(char data[], char stuffed[]) {
    int i, j = 0;
    stuffed[j++] = FLAG;
    for (i = 0; i < strlen(data); i++) {
        if (data[i] == FLAG || data[i] == ESCAPE) {
            stuffed[j++] = ESCAPE;
        }
        stuffed[j++] = data[i];
    }
    stuffed[j++] = FLAG;
    stuffed[j] = '\0';
}
int main() {
    char data[100], stuffed[200];
    printf("Enter the data to be transmitted: ");
    scanf("%s", data);
    byteStuffing(data, stuffed);
    printf("Data after Byte Stuffing: %s\n", stuffed);
    return 0;
}