#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* last = NULL;

void create(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if (last == NULL) {
        last = newNode;
        last->next = last; 
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
    printf("Node with value %d added.\n", value);
}

void traverse() {
    if (last == NULL) {
        printf("The list is empty.\n");
        return;
    }
    
    struct Node* temp = last->next;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("(back to start)\n");
}

void insert_beg(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (last == NULL) {
        last = newNode;
        last->next = last;
    } else {
        newNode->next = last->next;
        last->next = newNode;
    }
    printf("Node with value %d inserted at the beginning.\n", value);
}

void insert_end(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    
    if (last == NULL) {
        last = newNode;
        last->next = last;
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
    printf("Node with value %d inserted at the end.\n", value);
}

void delete_beg() {
    if (last == NULL) {
        printf("The list is empty, cannot delete.\n");
        return;
    }
    
    struct Node* temp;
    if (last->next == last) { 
        temp = last;
        last = NULL;
    } else {
        temp = last->next;
        last->next = temp->next;
    }
    printf("Node with value %d deleted from the beginning.\n", temp->data);
    free(temp);
}

void delete_end() {
    if (last == NULL) {
        printf("The list is empty, cannot delete.\n");
        return;
    }

    struct Node* temp = last->next;
    if (last->next == last) { 
        free(last);
        last = NULL;
    } else {
        while (temp->next != last) {
            temp = temp->next;
        }
        temp->next = last->next;
        printf("Node with value %d deleted from the end.\n", last->data);
        free(last);
        last = temp;
    }
}

int main() {
    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Create Node\n");
        printf("2. Traverse List\n");
        printf("3. Insert at Beginning\n");
        printf("4. Insert at End\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from End\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                create(value);
                break;

            case 2:
                traverse();
                break;

            case 3:
                printf("Enter value to insert at the beginning: ");
                scanf("%d", &value);
                insert_beg(value);
                break;

            case 4:
                printf("Enter value to insert at the end: ");
                scanf("%d", &value);
                insert_end(value);
                break;

            case 5:
                delete_beg();
                break;

            case 6:
                delete_end();
                break;

            case 7:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 7);

    return 0;
}
