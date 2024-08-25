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

    if (head != nullptr) {
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
        } else {
            Node* current = head;
            while (current->next->next != nullptr) {
                current = current->next; 
            }
            Node* lastNode = current->next; 
            current->next = nullptr; 
            delete lastNode;
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
