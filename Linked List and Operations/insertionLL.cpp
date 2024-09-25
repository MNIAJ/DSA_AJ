#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {} 
};

void printLL(const Node* n) {
    while (n != nullptr) {
        cout << n->data << " ";  
        n = n->next;             
    }
    cout << endl; 
}

void insertAtBeginning(Node*& head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}

void insertAtPosition(Node*& head, int position, int value) {
    if (position < 1) {
        cout << "Position must be 1 or greater." << endl;
        return;
    }
    
    if (position == 1) {
        insertAtBeginning(head, value);
        return;
    }

    Node* newNode = new Node(value);
    Node* current = head;
    for (int i = 1; current != nullptr && i < position - 1; i++) {
        current = current->next;
    }

    if (current == nullptr) {
        delete newNode; 
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

int main() {
    Node* head = nullptr;
    int n, value, position;

    cout << "Enter the number of initial nodes: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cout << "Enter data for node " << i << ": ";
        cin >> value;
        insertAtBeginning(head, value); 
    }

    cout << "The linked list is: ";
    printLL(head);

    cout << "Enter data to insert at the end: ";
    cin >> value;
    insertAtEnd(head, value);
    cout << "The linked list after inserting at the end is: ";
    printLL(head);

    cout << "Enter the position to insert a new node: ";
    cin >> position;
    cout << "Enter data for the new node: ";
    cin >> value;
    insertAtPosition(head, position, value);
    cout << "The linked list after insertion is: ";
    printLL(head);

    return 0;
}
