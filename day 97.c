#include <stdio.h>
#include <stdlib.h>

int cmpStart(const void* a, const void* b) {
    return ((int**)a)[0][0] - ((int**)b)[0][0];
}

int cmpEnd(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int minRooms(int** intervals, int n, int* colSize) {
    int start[n], end[n];

    for (int i = 0; i < n; i++) {
        start[i] = intervals[i][0];
        end[i] = intervals[i][1];
    }

    qsort(start, n, sizeof(int), cmpEnd);
    qsort(end, n, sizeof(int), cmpEnd);

    int rooms = 0, j = 0;

    for (int i = 0; i < n; i++) {
        if (start[i] < end[j]) {
            rooms++;
        } else {
            j++;
        }
    }

    return rooms;
}