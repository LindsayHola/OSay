#include <stdio.h>
#include <string.h>
#include<math.h>
#include <time.h>
#define LEN 1024

int tointshift(char* s, int len) {
    int acc = 0;
    for (int i = 0; i < len; i++) {
        acc =  (int)( acc << 1) +  (s[i] - '0');
    }
    return acc;
}

int tointpower(char* s, int len) {
    int sum =0;
    for (int i = 0; i < len; i++) {
        if (s[i] == '1') {
            sum += pow(2, len - i - 1);
        } else if (s[i] == '0') {
            sum += pow(2, len-1-i) * 0;
        }
    }
    return sum;
}
void tobinary(int num, char* binary){
    char result[LEN];
    int i = 0;
    while (num > 0) {
        result[i++] = (char)((num % 2) + 48);
        num = num / 2;
    }
    result[i] = '\0';
    for (int j = i - 1; j >= 0; j--) {
        binary[i - j - 1] = result[j];
    }
    binary[i] = '\0';
}


int main() {

    char str[LEN];

    int sum = 0;
    int num;
    scanf("%d", &num);
    int len = strlen(str);

    clock_t start_time, end_time;
    double cpu_time_used;

    /*start_time = clock(); // Record the start time
    int total = tointshift(str, len);
    printf("binary to denary(by shift): %d\n", total);
    end_time = clock(); // Record the end time
    cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Execution time: %f seconds\n", cpu_time_used);

    start_time = clock(); // Record the start time
    total = tointpower(str, len);
    printf("binary to denary(by power): %d\n", total);
    end_time = clock(); // Record the end time
    cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Execution time: %f seconds\n", cpu_time_used);*/

    start_time = clock(); // Record the start time
    tobinary(num, str);
    printf("denary to binary: %s\n", str);
    end_time = clock(); // Record the end time
    cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Execution time: %f seconds\n", cpu_time_used);

    return 0;
}
