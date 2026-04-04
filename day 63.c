#include <stdio.h>

int visited[100];

void dfs(int v, int n, int a[n][n]) {
    visited[v] = 1;
    printf("%d ", v);
    for(int i = 0; i < n; i++) {
        if(a[v][i] == 1 && visited[i] == 0) {
            dfs(i, n, a);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int a[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    int s;
    scanf("%d", &s);

    for(int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    dfs(s, n, a);

    return 0;
}