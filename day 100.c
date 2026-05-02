#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int val, idx;
} Pair;

int *ans;

void merge(Pair a[], Pair temp[], int l, int m, int r){
    int i = l, j = m + 1, k = l;
    int rightCount = 0;

    while(i <= m && j <= r){
        if(a[i].val <= a[j].val){
            ans[a[i].idx] += rightCount;
            temp[k++] = a[i++];
        } else {
            rightCount++;
            temp[k++] = a[j++];
        }
    }

    while(i <= m){
        ans[a[i].idx] += rightCount;
        temp[k++] = a[i++];
    }

    while(j <= r){
        temp[k++] = a[j++];
    }

    for(int x = l; x <= r; x++){
        a[x] = temp[x];
    }
}

void mergeSort(Pair a[], Pair temp[], int l, int r){
    if(l < r){
        int m = (l + r) / 2;
        mergeSort(a, temp, l, m);
        mergeSort(a, temp, m + 1, r);
        merge(a, temp, l, m, r);
    }
}

int main(){
    int n;
    scanf("%d", &n);

    Pair a[n], temp[n];
    ans = (int*)calloc(n, sizeof(int));

    for(int i = 0; i < n; i++){
        scanf("%d", &a[i].val);
        a[i].idx = i;
    }

    mergeSort(a, temp, 0, n - 1);

    for(int i = 0; i < n; i++){
        printf("%d ", ans[i]);
    }

    return 0;
}