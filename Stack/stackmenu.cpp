#include <iostream>
using namespace std;

#define MAX 100 // Define the maximum size of the stack

class Stack {
private:
    int stack[MAX]; // Array to store stack elements
    int top; // Index of the top element in the stack

public:
    // Constructor to initialize the stack
    Stack() : top(-1) {} // Initialize top as -1 indicating stack is empty

    // Function to push an element onto the stack
    void push(int item) {
        if (top < MAX - 1) { // Check if the stack is not full
            stack[++top] = item;
            cout << "Item " << item << " pushed onto the stack." << endl;
        } else {
            cout << "Stack overflow. Cannot push " << item << "." << endl;
        }
    }

    // Function to pop an element from the stack
    void pop() {
        if (!isEmpty()) { // Check if the stack is not empty
            cout << "Item " << stack[top--] << " popped from the stack." << endl;
        } else {
            cout << "Stack is empty. Nothing to pop." << endl;
        }
    }

    // Function to print the elements of the stack
    void printStack() {
        if (!isEmpty()) { // Check if the stack is not empty
            cout << "Stack contents: ";
            for (int i = top; i >= 0; --i) {
                cout << stack[i] << " ";
            }
            cout << endl;
        } else {
            cout << "Stack is empty." << endl;
        }
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }
};

// Function to display the menu
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
    menu(); // Call the menu function to start the program
    return 0;
}