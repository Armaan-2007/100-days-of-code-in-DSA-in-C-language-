#include <stdio.h>

int main() {
    int n, e;
    scanf("%d %d", &n, &e);

    int adj[100][100] = {0};
    int indeg[100] = {0};

    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        indeg[v]++;
    }

    int queue[100], front = 0, rear = 0;

    for (int i = 0; i < n; i++) {
        if (indeg[i] == 0) {
            queue[rear++] = i;
        }
    }

    while (front < rear) {
        int u = queue[front++];
        printf("%d ", u);

        for (int v = 0; v < n; v++) {
            if (adj[u][v]) {
                indeg[v]--;
                if (indeg[v] == 0) {
                    queue[rear++] = v;
                }
            }
        }
    }

    return 0;
}