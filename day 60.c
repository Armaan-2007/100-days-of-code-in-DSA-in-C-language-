#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int a[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    for(int i = 0; i <= (n - 2) / 2; i++) {
        if(2*i + 1 < n && a[i] > a[2*i + 1]) {
            printf("NO");
            return 0;
        }
        if(2*i + 2 < n && a[i] > a[2*i + 2]) {
            printf("NO");
            return 0;
        }
    }
    
    printf("YES");
    return 0;
}