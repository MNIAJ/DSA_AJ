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

    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    temp = head;
    while (temp != nullptr) {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    return 0;
}
