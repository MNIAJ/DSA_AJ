#include <iostream>
using namespace std;
#define MAX 100 

class Stack {
private:
    int stack[MAX]; 
    int top; 

public:

    Stack() : top(-1) {} 

    void push(int item) {
        if (top < MAX - 1) { 
            stack[++top] = item;
            cout << "Item " << item << " pushed onto the stack." << endl;
        } else {
            cout << "Stack overflow. Cannot push " << item << "." << endl;
        }
    }

    void pop() {
        if (!isEmpty()) { 
            cout << "Item " << stack[top--] << " popped from the stack." << endl;
        } else {
            cout << "Stack is empty. Nothing to pop." << endl;
        }
    }

    void printStack() {
        if (!isEmpty()) { 
            cout << "Stack contents: ";
            for (int i = top; i >= 0; --i) {
                cout << stack[i] << " ";
            }
            cout << endl;
        } else {
            cout << "Stack is empty." << endl;
        }
    }

    bool isEmpty() {
        return top == -1;
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