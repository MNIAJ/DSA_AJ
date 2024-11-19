#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10

typedef struct Node {
    int key;
    struct Node* next;
} Node;

Node* hashTable[TABLE_SIZE];

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void insert(int key) {
    int index = hashFunction(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

int search(int key) {
    int index = hashFunction(key);
    Node* temp = hashTable[index];
    while (temp != NULL) {
        if (temp->key == key)
            return 1; 
        temp = temp->next;
    }
    return 0;
}

void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: ", i);
        Node* temp = hashTable[i];
        while (temp != NULL) {
            printf("%d -> ", temp->key);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }

    insert(10);
    insert(20);
    insert(30);
    insert(25);
    insert(35);

    printf("Hash Table:\n");
    display();

    printf("\nSearch 20: %s\n", search(20) ? "Found" : "Not Found");
    printf("Search 40: %s\n", search(40) ? "Found" : "Not Found");

    return 0;
}