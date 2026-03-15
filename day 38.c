#include <stdio.h>
#include <string.h>

#define MAX 1000

int dq[MAX];
int front = -1, rear = -1;

int isEmpty() {
    return front == -1;
}

int size() {
    if (isEmpty()) return 0;
    return rear - front + 1;
}

void push_front(int x) {
    if (front == -1) {
        front = rear = MAX / 2;
        dq[front] = x;
    } else {
        dq[--front] = x;
    }
}

void push_back(int x) {
    if (front == -1) {
        front = rear = MAX / 2;
        dq[rear] = x;
    } else {
        dq[++rear] = x;
    }
}

void pop_front() {
    if (isEmpty()) {
        printf("-1\n");
        return;
    }
    printf("%d\n", dq[front++]);
    if (front > rear) front = rear = -1;
}

void pop_back() {
    if (isEmpty()) {
        printf("-1\n");
        return;
    }
    printf("%d\n", dq[rear--]);
    if (front > rear) front = rear = -1;
}

void get_front() {
    if (isEmpty()) printf("-1\n");
    else printf("%d\n", dq[front]);
}

void get_back() {
    if (isEmpty()) printf("-1\n");
    else printf("%d\n", dq[rear]);
}

void clear() {
    front = rear = -1;
}

void reverse() {
    if (isEmpty()) return;
    int i = front, j = rear;
    while (i < j) {
        int t = dq[i];
        dq[i] = dq[j];
        dq[j] = t;
        i++;
        j--;
    }
}

void sort() {
    for (int i = front; i <= rear; i++) {
        for (int j = i + 1; j <= rear; j++) {
            if (dq[i] > dq[j]) {
                int t = dq[i];
                dq[i] = dq[j];
                dq[j] = t;
            }
        }
    }
}

int main() {
    int n, x;
    char op[30];
    scanf("%d", &n);

    while (n--) {
        scanf("%s", op);

        if (strcmp(op, "push_front") == 0) {
            scanf("%d", &x);
            push_front(x);
        } 
        else if (strcmp(op, "push_back") == 0) {
            scanf("%d", &x);
            push_back(x);
        } 
        else if (strcmp(op, "pop_front") == 0) {
            pop_front();
        } 
        else if (strcmp(op, "pop_back") == 0) {
            pop_back();
        } 
        else if (strcmp(op, "front") == 0) {
            get_front();
        } 
        else if (strcmp(op, "back") == 0) {
            get_back();
        } 
        else if (strcmp(op, "size") == 0) {
            printf("%d\n", size());
        } 
        else if (strcmp(op, "empty") == 0) {
            printf("%d\n", isEmpty());
        } 
        else if (strcmp(op, "clear") == 0) {
            clear();
        } 
        else if (strcmp(op, "reverse") == 0) {
            reverse();
        } 
        else if (strcmp(op, "sort") == 0) {
            sort();
        }
    }

    if (!isEmpty()) {
        for (int i = front; i <= rear; i++) {
            printf("%d ", dq[i]);
        }
    }

    return 0;
}