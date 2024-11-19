#include <stdio.h>
#define MAX 10  

int queue[MAX];
int front = -1, rear = -1;
int isEmpty() {
    return front == -1;
}

int isFull() {
    return (rear + 1) % MAX == front;
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue is Full (Overflow).\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;  
    } else {
        rear = (rear + 1) % MAX;  
    }
    queue[rear] = value;
    printf("Enqueued: %d\n", value);
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is Empty (Underflow).\n");
        return;
    }
    printf("Dequeued: %d\n", queue[front]);
    if (front == rear) {
        front = rear = -1;  
    } else {
        front = (front + 1) % MAX;  
    }
}

void peek() {
    if (isEmpty()) {
        printf("Queue is Empty.\n");
    } else {
        printf("Front Element: %d\n", queue[front]);
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is Empty.\n");
        return;
    }
    printf("Queue Elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\nCircular Queue Menu:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}