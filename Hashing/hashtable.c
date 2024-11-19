#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10
#define EMPTY -1 

int hashTable[TABLE_SIZE];
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void insert(int key) {
    int index = hashFunction(key);

    while (hashTable[index] != EMPTY) {
        index = (index + 1) % TABLE_SIZE;
    }
    hashTable[index] = key;
    printf("Inserted key %d at index %d\n", key, index);
}

int search(int key) {
    int index = hashFunction(key);
    int originalIndex = index;

    while (hashTable[index] != EMPTY) {
        if (hashTable[index] == key) {
            return index; 
        }
        index = (index + 1) % TABLE_SIZE;

        if (index == originalIndex) {
            break;
        }
    }
    return -1; 
}

void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] == EMPTY) {
            printf("Index %d: EMPTY\n", i);
        } else {
            printf("Index %d: %d\n", i, hashTable[i]);
        }
    }
}

int main() {

    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = EMPTY;
    }

    int choice, key;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert a key\n");
        printf("2. Search for a key\n");
        printf("3. Display hash table\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                int index = search(key);
                if (index != -1) {
                    printf("Key %d found at index %d\n", key, index);
                } else {
                    printf("Key %d not found\n", key);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
