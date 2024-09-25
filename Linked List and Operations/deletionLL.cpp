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

void freeLL(Node* head) {
    Node* temp;
    while (head != nullptr) {
        temp = head;      
        head = head->next; 
        delete temp;      
    }
}

void insertAtPosition(Node*& head, int position, int value) {
    Node* newNode = new Node(value);
    
    if (position == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

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

void deleteFromBeginning(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteFromEnd(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    
    Node* current = head;
    while (current->next->next != nullptr) {
        current = current->next;
    }
    delete current->next;
    current->next = nullptr;
}

void deleteAtPosition(Node*& head, int position) {
    if (head == nullptr) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }
    
    if (position == 1) {
        deleteFromBeginning(head);
        return;
    }

    Node* current = head;
    for (int i = 1; current != nullptr && i < position - 1; i++) {
        current = current->next;
    }

    if (current == nullptr || current->next == nullptr) {
        cout << "Position out of bounds. Nothing to delete." << endl;
        return;
    }

    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
}

int main() {
    Node* head = nullptr;
    int n, value, position;

    cout << "Enter the number of initial nodes: ";
    cin >> n;

    if (n <= 0) {
        cout << "The number of nodes must be positive." << endl;
        return 1; 
    }

    for (int i = 1; i <= n; i++) {
        cout << "Enter data for node " << i << ": ";
        cin >> value;
        Node* newNode = new Node(value);
        newNode->next = head; 
        head = newNode;
    }

    cout << "The linked list is: ";
    printLL(head);

    cout << "Deleting from the beginning." << endl;
    deleteFromBeginning(head);
    printLL(head);

    cout << "Deleting from the end." << endl;
    deleteFromEnd(head);
    printLL(head);

    cout << "Enter the position to delete a node: ";
    cin >> position;
    deleteAtPosition(head, position);
    printLL(head);

    freeLL(head);
    return 0;
}
