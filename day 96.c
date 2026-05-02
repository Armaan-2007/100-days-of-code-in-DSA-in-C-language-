#include <stdio.h>
#include <stdlib.h>

long long merge(int a[], int temp[], int left, int mid, int right){
    int i = left, j = mid, k = left;
    long long inv = 0;

    while(i <= mid - 1 && j <= right){
        if(a[i] <= a[j]){
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
            inv += (mid - i);
        }
    }

    while(i <= mid - 1){
        temp[k++] = a[i++];
    }

    while(j <= right){
        temp[k++] = a[j++];
    }

    for(int x = left; x <= right; x++){
        a[x] = temp[x];
    }

    return inv;
}

long long mergeSort(int a[], int temp[], int left, int right){
    long long inv = 0;
    if(right > left){
        int mid = (left + right) / 2;
        inv += mergeSort(a, temp, left, mid);
        inv += mergeSort(a, temp, mid + 1, right);
        inv += merge(a, temp, left, mid + 1, right);
    }
    return inv;
}

int main(){
    int n;
    scanf("%d", &n);

    int a[n], temp[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    long long result = mergeSort(a, temp, 0, n - 1);
    printf("%lld", result);

    return 0;
}