#include <stdio.h>

int main() {
    int n, i, j, s;
    scanf("%d", &n);

    int adj[n][n];
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

    scanf("%d", &s);

    int visited[n];
    for(i = 0; i < n; i++) visited[i] = 0;

    int q[n], front = 0, rear = 0;

    visited[s] = 1;
    q[rear++] = s;

    while(front < rear) {
        int v = q[front++];
        printf("%d ", v);

        for(i = 0; i < n; i++) {
            if(adj[v][i] && !visited[i]) {
                visited[i] = 1;
                q[rear++] = i;
            }
        }
    }

    return 0;
}