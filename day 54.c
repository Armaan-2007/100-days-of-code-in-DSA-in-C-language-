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
    if(n == 0) return 0;

    int arr[n];
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct Node* nodes[n];
    for(int i = 0; i < n; i++) {
        if(arr[i] == -1) nodes[i] = NULL;
        else nodes[i] = newNode(arr[i]);
    }

    for(int i = 0; i < n; i++) {
        if(nodes[i] != NULL) {
            int l = 2*i + 1;
            int r = 2*i + 2;
            if(l < n) nodes[i]->left = nodes[l];
            if(r < n) nodes[i]->right = nodes[r];
        }
    }

    struct Node* root = nodes[0];

    struct Node* queue[n];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int leftToRight = 1;

    while(front < rear) {
        int size = rear - front;
        int level[size];

        for(int i = 0; i < size; i++) {
            struct Node* temp = queue[front++];
            int index = leftToRight ? i : size - i - 1;
            level[index] = temp->data;

            if(temp->left) queue[rear++] = temp->left;
            if(temp->right) queue[rear++] = temp->right;
        }

        for(int i = 0; i < size; i++) {
            printf("%d ", level[i]);
        }

        leftToRight = !leftToRight;
    }

    return 0;
}