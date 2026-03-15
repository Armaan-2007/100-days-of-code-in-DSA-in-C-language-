#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    int pq[1000];
    int size = 0;
    char op[20];

    for(int i = 0; i < n; i++) {
        scanf("%s", op);

        if(strcmp(op, "insert") == 0) {
            int x;
            scanf("%d", &x);
            int j = size - 1;
            while(j >= 0 && pq[j] > x) {
                pq[j + 1] = pq[j];
                j--;
            }
            pq[j + 1] = x;
            size++;
        }
        else if(strcmp(op, "delete") == 0) {
            if(size == 0) {
                printf("-1\n");
            } else {
                printf("%d\n", pq[0]);
                for(int j = 1; j < size; j++) {
                    pq[j - 1] = pq[j];
                }
                size--;
            }
        }
        else if(strcmp(op, "peek") == 0) {
            if(size == 0)
                printf("-1\n");
            else
                printf("%d\n", pq[0]);
        }
    }

    return 0;
}