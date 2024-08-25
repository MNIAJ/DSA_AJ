#include <iostream>
using namespace std;

struct Node {
    int data; 
    Node* next; 
    Node(int value) : data(value), next(nullptr) {}
};

int main() {
    
    Node* head = new Node(100); 
    head->next = new Node(222); 
    head->next->next = new Node(369);
    head->next->next->next= new Node(746);

    int insertData = 15;
    int insertPosition = 1;
    Node* newNode = new Node(insertData); 

    if (insertPosition == 0) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* current = head;
        for (int i = 0; current != nullptr && i < insertPosition - 1; i++) {
            current = current->next;
        }

        if (current != nullptr) {
            newNode->next = current->next;
            current->next = newNode;
        } else {
            cout << "Position out of bounds" << endl;
            delete newNode;
        }
    }

    Node* current = head;
    while (current != nullptr) { 
        cout << current->data << " ";
        current = current->next; 
    }
    cout << endl; 

    current = head; 
    while (current != nullptr) { 
        Node* nextNode = current->next;
        delete current; 
        current = nextNode; 
    }

    return 0;
}
