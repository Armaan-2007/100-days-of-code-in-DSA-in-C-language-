#include <stdio.h>

int n, adj[100][100], visited[100], rec[100];

int dfs(int v) {
    visited[v] = 1;
    rec[v] = 1;

    for(int i = 0; i < n; i++) {
        if(adj[v][i]) {
            if(!visited[i]) {
                if(dfs(i)) return 1;
            } else if(rec[i]) {
                return 1;
            }
        }
    }

    rec[v] = 0;
    return 0;
}

int main() {
    int i, j;
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        int m;
        scanf("%d", &m);
        for(j = 0; j < n; j++) adj[i][j] = 0;
        for(j = 0; j < m; j++) {
            int x;
            scanf("%d", &x);
            adj[i][x] = 1;
        }
    }

    for(i = 0; i < n; i++) {
        visited[i] = 0;
        rec[i] = 0;
    }

    for(i = 0; i < n; i++) {
        if(!visited[i]) {
            if(dfs(i)) {
                printf("YES");
                return 0;
            }
        }
    }

    printf("NO");
    return 0;
}