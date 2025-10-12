#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node*next;
};
struct node*top=NULL;

int main(){
int choice;
do{
    printf("--Linked list using stack--\n");
    printf("1.push\n2.pop\n3.peek\n4.display\n5.exit\n");
    printf("--------------------\n");
    printf("Enter your choice:\n");
    scanf("%d",&choice);
    switch(choice){
    case 1:push();break;
    case 2:pop();break;
    case 3:peek();break;
    case 4:display();break;
    default:printf("invalid choice");
    }
}while(choice!=5);
}

void push(int x){
    int n;
struct node*new1;
new1=(struct node*)malloc(sizeof(struct node));
printf("enter element to push:");
scanf("%d",&n);
new1->data=n;
new1->next=top; //link new node to previous top
top=new1; //move the top tp new node
printf("%d pushed into stack\n",x);
}

void pop(){
if(top==NULL){
    printf("Stack underflow");
}else{
struct node*temp=top;
printf("%d popped element is;\n",temp->data);
top=top->next;
free(temp);
}
}

void peek(){
if(top==NULL)
printf("linked list is empty\n");
else
    printf("top element is:\n",top->data);
}

void display(){
if(top==NULL)
    printf("linked liswt is empty\n");
else{
    struct node*temp=top;
    printf("elements are:\n");
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}
}
