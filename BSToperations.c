#include<stdio.h>
#include<stdlib.h>

//structure of each node
struct node{
int data;
struct node*left,*right;
};

//Function to create a new node,root node data  is inserted through this function
struct node*newNode(int value){
struct node*temp=(struct node*)malloc(sizeof(struct node));
temp->data=value;
temp->left=temp->right=NULL;
return temp;
};

//function to insert a node in bst
struct node*insert(struct node*root,int value){
if(root==NULL)
    return newNode(value);//return data of newNode function that we have created above
if(value<root->data)
    root->left=insert(root->left,value);
else if(value>root->data)
    root->right=insert(root->right,value);
return root;
};

//funcrion to search a node
struct node*search(struct node*root,int key){
if(root==NULL || root->data==key) //if any of one condition is true
    return root;//found at root or empty root
if(key<root->data)
    return search(root->left,key);
else
    return search(root->right,key);
};

//find minimum value  node
struct node*minValue(struct node*node){
struct node*current=node;
while(current && current->left!=NULL);
current=current->left;
return current;
};

//delete a nopde from BST
struct node*deleteNode(struct node*root,int key){
if(root==NULL)
    return root;
if(key<root->data)
    root->left=deleteNode(root->right,key);
else  if(key>root->data)
    root->right=deleteNode(root->left,key);
else{
    //node with 0 and 1 child
    if(root->left==NULL){
        struct node*temp=root->right;
    free(root);
    return temp;
    }
    else if(root->right=NULL){
        struct node*temp=root->left;
        free(root);
        return temp;
    }

//node with 2 children
struct node*temp=minValue(root->right);
root->data=temp->data;
root->right=deleteNode(root->right,temp->data);
}
return root;
};

//inorder traversal
void inorder(struct node*root){
if(root!=NULL){
    inorder(root->left);
    printf("%d",root->data);
    inorder(root->right);
}
}
//preorder traversal
void preorder(struct node*root){
if(root!=NULL){
    printf("%d",root->data);
    preorder(root->left);
    preorder(root->right);
}
}
//postorder trevrsal
void postorder(struct node*root){
if(root!=NULL){
    postorder(root->left);
    postorder(root->right);
    printf("%d",root->data);
    }
}

//main fucntion
int main(){
struct node*root=NULL;
int choice;
int value,key;
struct node*result;
do{
    printf("\n ----binary search tree---- \n");
    printf("1.insert\n2.search\n3.delete\n4.inorder\n5.preorder\n6.postorder\n7.exit");
    printf("---------------------------------\n");
    printf("Enter your choice:");
    scanf("%d",&choice);
    switch(choice){
    case 1: printf("Enter value to indert:");
    scanf("%d",&value);
    root=insert(root,value);
    printf("%dInserted element is:\n",value);
    break;
    case 2: printf("Enter value to search:");
    scanf("%d",&key);
    result=search(root,key);
    if(result!=NULL)
        printf("value %d found\n",key);
    else
        printf("value%dnot found\n",key);
    break;
    case 3: printf("Enter value to delete:");
    scanf("%d",&key);
    root=deleteNode(root,key);
    printf("If value%dexists,it has been deleted\n",key);
    break;
    case 4: printf("Inorder traversal:\t");
    inorder(root);
    printf("\n\t");
    break;
    case 5: printf("preorder treversal:\t");
    preorder(root);
    printf("\n\t");
    break;
    case 6: printf("postorder traversal:\t");
    postorder(root);
    printf("\n\t");
    break;
    case 7:printf("Exiting.....\n");
    break;
    default : printf("Invalid choice\n");
    break;
    }
}while(choice!=7);
return 0;
}
