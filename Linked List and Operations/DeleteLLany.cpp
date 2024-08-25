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

    int positionToDelete = 3;

    if (head == nullptr) {
        cout << "List is empty" << endl;
    } else if (positionToDelete == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
    } else {
        Node* current = head;
        for (int i = 0; current != nullptr && i < positionToDelete - 1; i++) {
            current = current->next;
        }

        if (current != nullptr && current->next != nullptr) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        } else {
            cout << "Position out of bounds" << endl;
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
