#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* create(int x) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = x;
    n->left = NULL;
    n->right = NULL;
    return n;
}

struct node* insert(struct node* root, int x) {
    if (root == NULL)
        return create(x);
    if (x < root->data)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);
    return root;
}

void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct node* root = NULL;
    int n, x, i;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    inorder(root);
    return 0;
}