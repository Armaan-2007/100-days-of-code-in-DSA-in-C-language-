#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void append(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

int findIntersection(Node* head1, Node* head2) {
    while (head1 != NULL) {
        Node* temp = head2;
        while (temp != NULL) {
            if (head1->data == temp->data)
                return head1->data;
            temp = temp->next;
        }
        head1 = head1->next;
    }
    return -1;
}

int main() {
    int n, m, x;
    Node *head1 = NULL, *head2 = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        append(&head1, x);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        append(&head2, x);
    }

    int result = findIntersection(head1, head2);

    if (result == -1)
        printf("No Intersection");
    else
        printf("%d", result);

    return 0;
}