#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
int queue [MAXSIZE],rear=-1,front=0;

void insert();
void delete1();
void display();

int main(){
int choice;
do{
    printf("----queue-----");
    printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit");
    printf("----------------");
    printf("Enter your choice:");
    scanf("%d",&choice);
    switch(choice){
    case 1:insert();break;
    case 2:delete1();break;
    case 3:display();break;
    default : printf("Invalid choice");

    }
}while(choice!=4);
}

void insert(){
int n;
if(rear==MAXSIZE-1)
    printf("queue overflow");
else{
    printf("Enter element:");
    scanf("%d",&n);
    rear++;
    queue[rear]=n;
}
}

void delete1(){
int n;
if(front>rear)
    printf("queue is empty");
else{
    n=queue[front];//for deletion
    printf("Deleted element is:%d",n);
   front++;
}
}

void display(){
    int i;
if(front>rear)
    printf("queue is empty");
else{
    printf("queue elements:");
    for(i=rear;i>=front;i--)
        printf("%d\n",queue[i]);
}
}


