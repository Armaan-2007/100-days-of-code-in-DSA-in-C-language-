#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int hd;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->hd = 0;
    node->left = node->right = NULL;
    return node;
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* nodes[n];
    for (int i = 0; i < n; i++) {
        if (arr[i] != -1)
            nodes[i] = newNode(arr[i]);
        else
            nodes[i] = NULL;
    }

    int j = 1;
    for (int i = 0; i < n && j < n; i++) {
        if (nodes[i] != NULL) {
            if (j < n) nodes[i]->left = nodes[j++];
            if (j < n) nodes[i]->right = nodes[j++];
        }
    }
    return nodes[0];
}

struct Queue {
    struct Node* arr[1000];
    int front, rear;
};

void enqueue(struct Queue* q, struct Node* node) {
    q->arr[q->rear++] = node;
}

struct Node* dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    int min = 0, max = 0;
    int map[2000][200];
    int count[2000] = {0};

    struct Queue q;
    q.front = q.rear = 0;

    if (root) {
        root->hd = 0;
        enqueue(&q, root);
    }

    while (!isEmpty(&q)) {
        struct Node* temp = dequeue(&q);
        int hd = temp->hd + 1000;

        map[hd][count[hd]++] = temp->data;

        if (temp->hd < min) min = temp->hd;
        if (temp->hd > max) max = temp->hd;

        if (temp->left) {
            temp->left->hd = temp->hd - 1;
            enqueue(&q, temp->left);
        }
        if (temp->right) {
            temp->right->hd = temp->hd + 1;
            enqueue(&q, temp->right);
        }
    }

    for (int i = min; i <= max; i++) {
        int idx = i + 1000;
        for (int j = 0; j < count[idx]; j++) {
            printf("%d ", map[idx][j]);
        }
        printf("\n");
    }

    return 0;
}