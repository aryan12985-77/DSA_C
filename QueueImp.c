#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10

int queue[MAXSIZE], rear = -1, front = 0;



int main() {
    int choice;
    do {
        printf("---- Queue Menu ----\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("---------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); break;
            case 2: delete1(); break;
            case 3: display(); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid choice\n");break;
        }
    } while (choice != 4);

    return 0;
}

void insert() {
    int n;
    if (rear == MAXSIZE - 1) {
        printf("Queue overflow\n");
    } else {
        printf("Enter element: ");
        scanf("%d", &n);
        rear++;
        queue[rear] = n;//for insertion
    }
}

void delete1() {
    int n;
    if (front > rear) {
        printf("Queue is empty\n");
    } else {
        n = queue[front];//for deletion
        printf("Deleted element is: %d\n", n);
        front++;
    }
}

void display() {
    int i;
    if (front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements:\n");
        for (i = front; i <= rear; i++) {
            printf("%d\n", queue[i]);
        }
    }
}


