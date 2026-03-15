#include <stdio.h>
#include <string.h>

int heap[1000];
int size = 0;

void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}

void heapifyUp(int i){
    while(i>0 && heap[(i-1)/2] > heap[i]){
        swap(&heap[(i-1)/2],&heap[i]);
        i=(i-1)/2;
    }
}

void heapifyDown(int i){
    while(1){
        int l=2*i+1,r=2*i+2,small=i;
        if(l<size && heap[l]<heap[small]) small=l;
        if(r<size && heap[r]<heap[small]) small=r;
        if(small!=i){
            swap(&heap[i],&heap[small]);
            i=small;
        } else break;
    }
}

void insert(int x){
    heap[size]=x;
    heapifyUp(size);
    size++;
}

int extractMin(){
    if(size==0) return -1;
    int min=heap[0];
    heap[0]=heap[size-1];
    size--;
    heapifyDown(0);
    return min;
}

int peek(){
    if(size==0) return -1;
    return heap[0];
}

int main(){
    int n,x;
    char op[20];
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%s",op);
        if(strcmp(op,"insert")==0){
            scanf("%d",&x);
            insert(x);
        }
        else if(strcmp(op,"extractMin")==0){
            printf("%d\n",extractMin());
        }
        else if(strcmp(op,"peek")==0){
            printf("%d\n",peek());
        }
    }
    return 0;
}