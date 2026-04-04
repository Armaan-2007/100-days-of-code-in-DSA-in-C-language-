#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct node* adj[n];

    for(int i = 0; i < n; i++) {
        adj[i] = NULL;
    }

    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        struct node* newNode1 = (struct node*)malloc(sizeof(struct node));
        newNode1->data = v;
        newNode1->next = adj[u];
        adj[u] = newNode1;

        struct node* newNode2 = (struct node*)malloc(sizeof(struct node));
        newNode2->data = u;
        newNode2->next = adj[v];
        adj[v] = newNode2;
    }

    for(int i = 0; i < n; i++) {
        printf("%d: ", i);
        struct node* temp = adj[i];
        while(temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }

    return 0;
}