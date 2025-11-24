//breadth first search
#include <stdio.h>
#include <conio.h>
#define MAX 10

int graph[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = -1, rear = -1;

//function to add element in queue
void enqueue(int vertex){
    if(rear == MAX - 1){
        printf("queue full\n");
    } else {
        if(front == -1)
            front = 0;
        queue[++rear] = vertex;
    }
}

//function to remove an element
int dequeue(){
    if(front == -1 || front > rear)
        return -1;
    else
        return queue[front++];
}

//function to perform BFS
void BSF(int start, int n){   // (you wrote BSF, so I kept it same)
    int i, current;

    //mark all nodes as unvisited
    for(i = 0; i < n; i++)
        visited[i] = 0;

    //start from the given vertex
    enqueue(start);
    visited[start] = 1;

    printf("BFS traversal starting from vertex %d: ", start);

    //process the queue until empty
    while(front != -1 && front <= rear){
        current = dequeue();   //take vertex from queue
        printf("%d ", current);

        //visit all adjacent vertices of current
        for(i = 0; i < n; i++){
            if(graph[current][i] == 1 && visited[i] == 0){
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main(){
    int n, i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    //input adjacency matrix
    printf("Enter matrix of graph\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &graph[i][j]);
        }
    }

    //get starting vertex
    printf("Starting vertex: ");
    scanf("%d", &start);

    BSF(start, n);
}

