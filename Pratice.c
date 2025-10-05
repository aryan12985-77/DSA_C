#include<stdio.h>
#include<conio.h>

struct node{//define structure of a node
int data;
struct node*add;
};struct node*start=NULL,*temp,*new1;//Declear global pointers

void main(){
    int choice;
do{
    printf("---linked list----");
    printf("1.create\n2.Insert on first\n3.insert on middle\n4.insert on last\n5.delete from first\n6.delete from last\n7.delete from last\n8.display\n9.exit");
    printf("_____________________________________\n");
    printf("Enter your choice:");
    scanf("%d",&choice);
    switch(choice){
    case 1:create();break;
    case 2:insertf();break;
    case 3:insertm();break;
    case 4:insertl();break;
    case 5:deletef();break;
    case 6:deletel();break;
    case 7:deletem();break;
    case 8:display();break;
    default:printf("invalid choice");
    }
}while(choice!=9);
}

void create(){
char ch;//to store user choice yes or no as y/n
int n;
do{
    new1=(struct node*)malloc(sizeof(struct node));//allocate memory for a new node
    printf("Enter element:");//ask user for data
    scanf("%d",&n);

    new1->data=n; //assign data to the new node
    new1->add=NULL; //new node points t o the null

    if(start==NULL){ //check if this is the  first node cause last node should be null
        start=new1; //first node becomes start
        temp=new1; //old last node points to the new1
    }else{ //link new node to the  list
    temp->add=new1; //old last node points to  the new1
    temp=new1; //update temp to new last node
    }
    printf("Want to continue(y/n)?"); //ask if user wants to add more nodes
    ch=getch(); //get single character without enter
    printf("\n");
}while(ch=='y'||ch=='Y'); //repeat if user says yes
}


void display(){
if(start==NULL)
    printf("List not found");
else{
    temp=start;
    while(temp!=NULL)
    {
        printf("\n%d",temp->data);
        temp=temp->data;
    }
}
}
