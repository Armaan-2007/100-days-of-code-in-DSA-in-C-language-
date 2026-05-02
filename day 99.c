#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pos;
    int speed;
} Car;

int cmp(const void *a, const void *b){
    Car *x = (Car*)a;
    Car *y = (Car*)b;
    return y->pos - x->pos;
}

int main(){
    int n, target;
    scanf("%d %d", &n, &target);

    Car cars[n];
    for(int i = 0; i < n; i++){
        scanf("%d %d", &cars[i].pos, &cars[i].speed);
    }

    qsort(cars, n, sizeof(Car), cmp);

    double stack[n];
    int top = -1;

    for(int i = 0; i < n; i++){
        double time = (double)(target - cars[i].pos) / cars[i].speed;

        if(top == -1 || time > stack[top]){
            stack[++top] = time;
        }
    }

    printf("%d", top + 1);
    return 0;
}