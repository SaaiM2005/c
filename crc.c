#include <stdio.h>
#include <string.h>

void calculateCRC(char *data, char *poly, char *result) {
    int dataLen = strlen(data);
    int polyLen = strlen(poly);
    
    for (int i = 0; i < polyLen - 1; i++) {
        data[dataLen + i] = '0';
    }
    
    for (int i = 0; i < dataLen; i++) {
        if (data[i] == '1') {
            for (int j = 0; j < polyLen; j++) {
                data[i + j] = (data[i + j] == poly[j]) ? '0' : '1';
            }
        }
    }
    
    strncpy(result, data + dataLen, polyLen - 1);
    result[polyLen - 1] = '\0';
}

int main() {
    char data[100], poly[20], result[20];

    printf("Enter data in binary form: ");
    scanf("%s", data);

    printf("Enter polynomial in binary form: ");
    scanf("%s", poly);

    calculateCRC(data, poly, result);

    printf("CRC: %s\n", result);

    return 0;
}