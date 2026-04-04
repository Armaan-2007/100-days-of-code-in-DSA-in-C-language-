#include <stdio.h>

int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    int a[n][n];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            a[i][j] = 0;
        }
    }

    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        a[u][v] = 1;
        a[v][u] = 1;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}