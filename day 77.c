#include <stdio.h>

int n, m;
int adj[101][101];
int visited[101];

void dfs(int v)
{
    visited[v] = 1;
    for(int i = 1; i <= n; i++)
    {
        if(adj[v][i] && !visited[i])
            dfs(i);
    }
}

int main()
{
    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    dfs(1);

    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            printf("NOT CONNECTED");
            return 0;
        }
    }

    printf("CONNECTED");
    return 0;
}