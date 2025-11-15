//graph input using adjancy matrix
//this code representation by using manual value input of matrices
/*#include<stdio.h>
int main(){
int v,i,j;
int graph[10][10];//define 2d array for store matrix
printf("Enter number of vertices:");
scanf("%d",&v);
printf("Enter adjancy matrix%d%d\n",v,v);//mauual entry of matrix
for(i=0;i<v;i++)//loop for entering vertices
    for(j=0;j<v;j++)
    scanf("%d",& graph[i][j]);
printf("Adjancy matrix representation:\n");//printing of matrix
for(i=0;i<v;i++){//loop for printing matrix
    for(j=0;j<v;j++)
    printf("%d",graph[i][j]);
printf("\n");
}
getch();
return 1;
}*/

/*
//grapg representation using input number of edges
#include<stdio.h>
#include<conio.h>
int main(){
int e,v,u,i,n,j;
int A[10][10];
printf("Enter number of vertices:");
scanf("%d",&n);
printf("Enter number of edges:");
scanf("%d",&e);
//initialize adjancy matrix to 0
for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    A[i][j]=A[j][i]=0;

//read edges
    for(i=1;i<=e;i++){
        printf("Enter(u,v):");
        scanf("%d%d",&v,&u);
        A[v][u]=A[u][v]=1;//mark the code
    }
    //print matrix
    printf("Adjacency matrix:\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)
            printf("%3d",A[i][j]);
        printf("\n");
    }
    getch();
    return 1;
}
*/

/*
//graph representation using edge list(edge between vertices)
#include<stdio.h>
#include<conio.h>
struct edge{
int src;//starting vertex of edge
int dest;//ending vertex of edge
};
int main(){
int v,e;
//take number of edges
printf("ENnter number of edges:");
scanf("%d",&e);

//take number of vertices
printf("Enter number of vertices:");
scanf("%d",&v);

//create an array of edges
struct edge edges[e];
printf("\nEnter each edge:");
//input all edges
for(int i=0;i<e;i++){
    scanf("%d%d",&edges[i].src,&edges[i].dest);
}
//display the graph edge list
printf("\nGraph representation:\n");
for(int i=0;i<e;i++){
    printf("Edge%d:%d--%d\n",i+1,edges[i].src,edges[i].dest);
}
return 0;
}
*/
