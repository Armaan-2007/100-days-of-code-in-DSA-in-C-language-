#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    if(n == 1) {
        printf("1");
        return 0;
    }

    int degree[n+1];
    for(int i = 1; i <= n; i++) degree[i] = 0;

    for(int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        degree[u]++;
        degree[v]++;
    }

    int leaf = 0;
    for(int i = 1; i <= n; i++) {
        if(degree[i] == 1) leaf++;
    }

    printf("%d", leaf);
    return 0;
}