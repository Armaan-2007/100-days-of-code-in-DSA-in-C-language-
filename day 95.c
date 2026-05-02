#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    float x = *(float*)a;
    float y = *(float*)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

void bucketSort(float arr[], int n) {
    float* bucket[n];
    int size[n];

    for (int i = 0; i < n; i++) {
        bucket[i] = (float*)malloc(n * sizeof(float));
        size[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int idx = n * arr[i];
        bucket[idx][size[idx]++] = arr[i];
    }

    for (int i = 0; i < n; i++) {
        qsort(bucket[i], size[i], sizeof(float), cmp);
    }

    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < size[i]; j++) {
            arr[k++] = bucket[i][j];
        }
        free(bucket[i]);
    }
}

int main() {
    float arr[] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }

    return 0;
}