#include <stdio.h>

#define MAXSIZE 10

int stack[MAXSIZE];
int top = -1;

void push();
void pop();
void display();

int main() {
    int choice;
    do {
        printf("\n____ Stack Menu ____");
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit");
        printf("\n____________________");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}

void push() {
    int n;
    if (top == MAXSIZE - 1) {
        printf("Stack Overflow\n");
    } else {
        printf("Enter element to push: ");
        scanf("%d", &n);
        stack[top] = n;
        top++;
        printf("%d pushed to stack\n", n);
    }
}

void pop() {
    int n;
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        n=stack[top];
        top--;
        printf("Popped element: %d\n", n);
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}


