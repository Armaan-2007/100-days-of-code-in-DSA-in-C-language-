#include <stdio.h>
#include <limits.h>

#define MAX 100

int n, m;
int graph[MAX][MAX];

int minDistance(int dist[], int visited[]) {
    int min = INT_MAX, index = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] <= min) {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u-1][v-1] = w;
    }

    int source;
    scanf("%d", &source);
    source--;

    int dist[MAX], visited[MAX];

    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[source] = 0;

    for (int i = 0; i < n - 1; i++) {
        int u = minDistance(dist, visited);
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    for (int i = 0; i < n; i++)
        printf("%d ", dist[i]);

    return 0;
}