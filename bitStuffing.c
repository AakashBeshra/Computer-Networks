// Write a C program for bit stuffing
#include <stdio.h>
#include <string.h>

void bitStuffing(char data[], char stuffed[]) {
    int i, j = 0, count = 0;
    int n = strlen(data);

    // Starting Flag (01111110)
    stuffed[j++] = '0';
    stuffed[j++] = '1';
    stuffed[j++] = '1';
    stuffed[j++] = '1';
    stuffed[j++] = '1';
    stuffed[j++] = '1';
    stuffed[j++] = '1';
    stuffed[j++] = '0';

    // Bit Stuffing Logic
    for (i = 0; i < n; i++) {
        stuffed[j++] = data[i];
        if (data[i] == '1') {
            count++;
            if (count == 5) {
                stuffed[j++] = '0';  // Stuff '0' after five consecutive '1's
                count = 0;
            }
        } else {
            count = 0;
        }
    }

    // Ending Flag (01111110)
    stuffed[j++] = '0';
    stuffed[j++] = '1';
    stuffed[j++] = '1';
    stuffed[j++] = '1';
    stuffed[j++] = '1';
    stuffed[j++] = '1';
    stuffed[j++] = '1';
    stuffed[j++] = '0';

    stuffed[j] = '\0';  // Null-terminate the stuffed string
}

int main() {
    char data[200], stuffed[400];
    int n, i;

    printf("Enter the number of bits: ");
    scanf("%d", &n);

    printf("Enter the bitstream (sequence of 0's and 1's): ");
    for (i = 0; i < n; i++) {
        scanf(" %c", &data[i]);
        if (data[i] != '0' && data[i] != '1') {
            printf("Invalid input! Only 0 and 1 are allowed.\n");
            return 1;
        }
    }
    data[n] = '\0';  // Null-terminate the input data

    bitStuffing(data, stuffed);

    printf("Data after Bit Stuffing: %s\n", stuffed);

    return 0;
}
