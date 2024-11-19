#include <stdio.h>
#define MAX 100

int queue[MAX]; 
int front = -1, rear = -1; 

void enqueue(int value) {
    if (rear == MAX - 1) { 
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = value;
    printf("%d added to queue\n", value);
}

void dequeue() {
    if (front == -1 || front > rear) { 
        printf("Queue Underflow\n");
        return;
    }
    printf("%d removed from queue\n", queue[front]);
    front++;
    if (front > rear) { 
        front = rear = -1;
    }
}

void printQueue() {
    if (front == -1) { 
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;

    do {
        printf("\nQueue operations:\n");
        printf("1. Add\n");
        printf("2. Delete\n");
        printf("3. Print\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to add: ");
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
