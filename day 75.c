#include <stdio.h>

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            if (sum == 0) {
                if (j - i + 1 > maxLen) {
                    maxLen = j - i + 1;
                }
            }
        }
    }

    printf("%d", maxLen);
    return 0;
}