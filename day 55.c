#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);

    if(n == 0 || arr[0] == -1) return 0;

    struct Node* nodes[n];
    for(int i = 0; i < n; i++) {
        if(arr[i] == -1) nodes[i] = NULL;
        else nodes[i] = newNode(arr[i]);
    }

    for(int i = 0, j = 1; j < n; i++) {
        if(nodes[i] != NULL) {
            if(j < n) nodes[i]->left = nodes[j++];
            if(j < n) nodes[i]->right = nodes[j++];
        }
    }

    struct Node* queue[n];
    int front = 0, rear = 0;
    queue[rear++] = nodes[0];

    while(front < rear) {
        int size = rear - front;
        for(int i = 0; i < size; i++) {
            struct Node* temp = queue[front++];
            if(i == size - 1) printf("%d ", temp->data);
            if(temp->left) queue[rear++] = temp->left;
            if(temp->right) queue[rear++] = temp->right;
        }
    }

    return 0;
}