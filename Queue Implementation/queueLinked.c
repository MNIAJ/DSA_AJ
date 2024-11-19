#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* front = NULL; 
struct node* rear = NULL;  

void enqueue(int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Queue Overflow\n");
        return;
    }
    newnode->data = value;
    newnode->next = NULL;

    if (rear == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
    printf("%d added to queue\n", value);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow\n");
        return;
    }

    struct node* temp = front;
    printf("%d removed from the queue\n", front->data);
    front = front->next;

    if (front == NULL) { 
        rear = NULL;
    }
    free(temp);
}

void printQueue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct node* temp = front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, value;

    do {
        printf("\nQueue Operations:\n");
        printf("1. Add\n");
        printf("2. Delete\n");
        printf("3. Print\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to add: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                printQueue();
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice, try again.\n");
        }
    } while (choice != 4);

    return 0;
}
