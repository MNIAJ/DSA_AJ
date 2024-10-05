#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top; 
public:
    Stack() : top(nullptr) {} 
    void push(int item) {
        Node* newNode = new Node(); 
        newNode->data = item; 
        newNode->next = top;
        top = newNode; 
        cout << "Item " << item << " pushed onto the stack." << endl;
    }

    void pop() {
        if (!isEmpty()) {
            Node* temp = top; 
            cout << "Item " << top->data << " popped from the stack." << endl;
            top = top->next; 
            delete temp; 
        } else {
            cout << "Stack is empty. Nothing to pop." << endl;
        }
    }

    void printStack() {
        if (!isEmpty()) {
            cout << "Stack contents: ";
            Node* current = top; 
            while (current) {
                cout << current->data << " "; 
                current = current->next; 
            }
            cout << endl;
        } else {
            cout << "Stack is empty." << endl;
        }
    }

    bool isEmpty() {
        return top == nullptr;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop(); 
        }
    }
};

void menu() {
    Stack stack;
    int choice, item;

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Print Stack" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the item to push onto the stack: ";
                cin >> item;
                stack.push(item);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                stack.printStack();
                break;
            case 4:
                cout << "Exiting the program." << endl;
                return;
            default:
                cout << "Invalid choice. Please choose between 1-4." << endl;
                break;
        }
    }
}

int main() {
    menu(); 
    return 0;
}
