#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

int main() {
    int n, m, x;
    struct Node *l1 = NULL, *l2 = NULL, *tail = NULL;

    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        struct Node* temp = newNode(x);
        if(l1 == NULL) l1 = tail = temp;
        else { tail->next = temp; tail = temp; }
    }

    scanf("%d", &m);
    tail = NULL;
    for(int i = 0; i < m; i++) {
        scanf("%d", &x);
        struct Node* temp = newNode(x);
        if(l2 == NULL) l2 = tail = temp;
        else { tail->next = temp; tail = temp; }
    }

    struct Node dummy;
    tail = &dummy;
    dummy.next = NULL;

    while(l1 && l2) {
        if(l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    tail->next = (l1) ? l1 : l2;

    struct Node* temp = dummy.next;
    while(temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}