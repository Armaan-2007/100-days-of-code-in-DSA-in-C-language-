#include <stdio.h>

int max(int a, int b){
    return a > b ? a : b;
}

int sum(int arr[], int n){
    int s = 0;
    for(int i = 0; i < n; i++) s += arr[i];
    return s;
}

int isPossible(int arr[], int n, int m, int mid){
    int students = 1, pages = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] > mid) return 0;
        if(pages + arr[i] > mid){
            students++;
            pages = arr[i];
        } else {
            pages += arr[i];
        }
    }
    return students <= m;
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int arr[n];
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);

    int low = 0, high = sum(arr, n), ans = high;

    while(low <= high){
        int mid = (low + high) / 2;
        if(isPossible(arr, n, m, mid)){
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("%d", ans);
    return 0;
}