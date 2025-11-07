#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node*next;
};
struct node*front=NULL;
struct node*rear=NULL;

int main(){
int choice;
do{
    printf("--Linked list using stack--\n");
    printf("1.push\n2.pop\n3.peek\n4.display\n5.exit\n");
    printf("--------------------\n");
    printf("Enter your choice:\n");
    scanf("%d",&choice);
    switch(choice){
    case 1:enqueue();break;
   case 2:dequeue();break;
    case 3:peek();break;
    case 4:display();break;
    default:printf("invalid choice");
    }
}while(choice!=5);
}

int enqueue(int x){
    //memory allocation for new node and create newNode also
struct node*newNode=(struct node*)malloc(sizeof(struct node));
//check if memory allocation success
if(newNode==NULL){
    printf("memoey allocation faileded\n");
}
//enter element to insert and store in x
printf("Enter element to insert:\n");
scanf("%d",&x);
newNode->data=x;//store input value in newNode data
newNode->next=NULL;//allocate new node address pert to null,that's make it last node

//these logics ensure proper lnking of nodes and maintain the queue structure FIFO
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

printf("%d enqued into\n",x);
}

void dequeue(){
if(front==NULL){
    printf("queue empty\n");
}
struct node*temp=front;
printf("Deleted element\n%d",temp->data);
front=front->next;
free(temp);
if(front==NULL)
    rear=NULL;
}

int peek(){
if(front==NULL){
    printf("Queue is empty");
    return -1;
}
return front->data;
}

void display(){
if(front==NULL){
    printf("Queue is empty\n");
    return;
}
struct node*p=front;
printf("Queue elements:\n");
while(p!=NULL){
    printf("%d",p->data);
    p=p->next;
}
printf("\n");
}

