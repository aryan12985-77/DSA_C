#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node { //This defines the blueprint of a node in a doubly linked list
    int data;
    struct node* prev;
    struct node* next;
};

struct node* head = NULL; // global head pointer,first node

// Function prototypes //These tell the compiler that these functions will be defined later in the code.
struct node* createNode(int value);
void insert_begin(int value);
void insert_end(int value);
void delete_begin();
void delete_end();
void display();

// Main function
int main() {
    int choice, value;

    do {
        printf("\n-- Doubly Linked List Menu --\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("-----------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insert_begin(value);
                break;

            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insert_end(value);
                break;

            case 3:
                delete_begin();
                break;

            case 4:
                delete_end();
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 6);

    return 0;
}

// Create a new node,Allocates memory for a new node in the heap.
struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;  //Initially no links (so prev and next are NULL).
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning
void insert_begin(int value) {
    struct node* newNode = createNode(value);
    if (head == NULL) { //If list is empty, new node becomes the first node.
        head = newNode;
        return;
    }
    newNode->next = head; //connects the new node before the old head
    head->prev = newNode;
    head = newNode; //move haed to point to the new node
}

// Insert at end
void insert_end(int value) {
    struct node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct node* temp = head;
    while (temp->next != NULL) //move temp to the laast node
        temp = temp->next;

    temp->next = newNode; //links the new node at the end
    newNode->prev = temp;
}

// Delete from beginning
void delete_begin() {
    if (head == NULL) { //Checks if list is empty.
        printf("List is empty!\n");
        return;
    }

    struct node* temp = head; //Stores old head node temporarily for deletion.
    printf("Deleted element: %d\n", temp->data);

    if (head->next == NULL) {  //If only one node → list becomes empty.
        head = NULL; // only one node
    } else {  //Otherwise → move head to next node and break backward link.
        head = head->next;
        head->prev = NULL;
    }

    free(temp);
}

// Delete from end
void delete_end() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct node* temp = head; //store old head node temporarily for deletion
    while (temp->next != NULL)//move to lasr node
        temp = temp->next;

    printf("Deleted element: %d\n", temp->data);

    if (temp->prev == NULL) { //Adjusts pointers to remove the last node.
        head = NULL; // only one node
    } else {
        temp->prev->next = NULL;
    }

    free(temp);
}

// Display list
void display() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) { //print all nodes till last node
        printf("%d ", temp->data);
        temp = temp->next;//moving of nodes
    }
    printf("\n");
}
