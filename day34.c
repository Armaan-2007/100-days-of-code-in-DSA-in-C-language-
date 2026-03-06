#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node{
    int data;
    struct node* next;
};

struct node* top=NULL;

void push(int x){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=top;
    top=temp;
}

int pop(){
    struct node* temp=top;
    int x=temp->data;
    top=top->next;
    free(temp);
    return x;
}

int main(){
    char exp[100];
    int i=0;
    fgets(exp,100,stdin);

    while(exp[i]!='\0'){
        if(isdigit(exp[i])){
            push(exp[i]-'0');
        }
        else if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/'){
            int b=pop();
            int a=pop();
            int r;
            if(exp[i]=='+') r=a+b;
            if(exp[i]=='-') r=a-b;
            if(exp[i]=='*') r=a*b;
            if(exp[i]=='/') r=a/b;
            push(r);
        }
        i++;
    }

    printf("%d",pop());
    return 0;
}