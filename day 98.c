#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Interval;

int cmp(const void *a, const void *b){
    Interval *x = (Interval*)a;
    Interval *y = (Interval*)b;
    return x->start - y->start;
}

int main(){
    int n;
    scanf("%d", &n);

    Interval arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    qsort(arr, n, sizeof(Interval), cmp);

    int i = 0;
    for(int j = 1; j < n; j++){
        if(arr[i].end >= arr[j].start){
            if(arr[j].end > arr[i].end){
                arr[i].end = arr[j].end;
            }
        } else {
            i++;
            arr[i] = arr[j];
        }
    }

    for(int k = 0; k <= i; k++){
        printf("%d %d\n", arr[k].start, arr[k].end);
    }

    return 0;
}