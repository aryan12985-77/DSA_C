#include<stdio.h>

int adj[10][10];
int visited[10],n;

void DFS(int v){
visited[v]=1; //make the curent vertex as visited
printf("%d",v);//print the vertex

for(int i=1;i<=n;i++){//check all vertices to find adjacency
    if(adj[v][i]==1 && visited[i]==0){ //if there is an edge from v to i,and i is not visited,then go deeper
        DFS(i);
    }
}
}

int main(){
int i,j,start;

printf("Enter number of vertujces:");
scanf("%d",&n);

printf("Enter adjacency matrix:\n");
for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
        scanf("%d",&adj[i][j]);
    }
}
for(i=1;i<=n;i++)
    visited[i]=0;

    printf("DFS traversal:");
    DFS(start);
    return 0;
}
