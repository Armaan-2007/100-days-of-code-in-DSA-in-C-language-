#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

int main(){
    int n,k,x;
    scanf("%d",&n);

    struct Node *head=NULL,*tail=NULL,*temp;

    for(int i=0;i<n;i++){
        scanf("%d",&x);
        struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
        newNode->data=x;
        newNode->next=NULL;
        if(head==NULL) head=tail=newNode;
        else{
            tail->next=newNode;
            tail=newNode;
        }
    }

    scanf("%d",&k);

    if(n==0) return 0;

    k=k%n;
    if(k>0){
        tail->next=head;
        temp=head;
        for(int i=0;i<n-k-1;i++)
            temp=temp->next;
        head=temp->next;
        temp->next=NULL;
    }

    while(head){
        printf("%d ",head->data);
        head=head->next;
    }

    return 0;
}