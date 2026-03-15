#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d", &n);

    int *q = (int *)malloc(n * sizeof(int));
    int front = 0, rear = -1, count = 0;

    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        rear = (rear + 1) % n;
        q[rear] = x;
        count++;
    }

    scanf("%d", &m);

    for(int i = 0; i < m; i++) {
        if(count > 0) {
            front = (front + 1) % n;
            count--;
        }
    }

    for(int i = 0; i < count; i++) {
        int idx = (front + i) % n;
        printf("%d ", q[idx]);
    }

    for(int i = 0; i < m; i++) {
        int idx = (rear + 1 + i) % n;
        printf("%d ", q[idx]);
    }

    free(q);
    return 0;
}