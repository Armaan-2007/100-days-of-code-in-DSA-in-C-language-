#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int stack[1000];
    int top = -1;

    while(n--) {
        int op;
        scanf("%d", &op);

        if(op == 1) {
            int value;
            scanf("%d", &value);
            stack[++top] = value;
        }
        else if(op == 2) {
            if(top == -1)
                printf("Stack Underflow\n");
            else
                printf("%d\n", stack[top--]);
        }
        else if(op == 3) {
            if(top >= 0) {
                for(int i = top; i >= 0; i--)
                    printf("%d ", stack[i]);
                printf("\n");
            }
            else
                printf("\n");
        }
    }

    return 0;
}