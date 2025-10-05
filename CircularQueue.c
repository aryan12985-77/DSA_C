#include<stdio.h>
#include<conio.h>
#define MAXSIZE 10
int cq[MAXSIZE],rear=-1,front=-1;//cause of circular queue initialize rear and front as a same

int main(){
int choice;
do{
    printf("\n----queue-----\n");
    printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
    printf("----------------\n");
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


int insert()
{
int n;
if((rear+1)%MAXSIZE==front)//if rear is on 7 then front is on 8,thats this line tells
    printf("queue is overflow");
else{
    printf("enter an element:");
    scanf("%d",&n);
    if(rear==-1&&front==-1){
        rear=0;
        front=0;
}        else{
            rear=(rear+1)%MAXSIZE;
            cq[rear]=n;

    }

}
}

int delete1(){
    int n;
if(rear==-1&&front==-1)
    printf("Queue is empty");
else{
    n=cq[front];
    if(front==rear){
        front=-1;
        rear=-1;

    }else{
    front=(front+1)%MAXSIZE;
    printf("Deleted element is :%d",n);
    }

}
}

display(){//complete this display function,looks like incompleted
int i;
if(rear==-1&&front==-1)
    printf("Queue is empty");
else{
    printf("Elements of queue are:");
    for(i=front;i!=rear;i=(i+1)%MAXSIZE)
    {
        printf("%d",cq[i]);
    }
    printf("%d",cq[i]);
}
}
