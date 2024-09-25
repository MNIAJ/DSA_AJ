#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
};

void printLL(Node* n)
{
    while (n != nullptr)
    {
        cout << n->data << " ";  
        n = n->next;             
    }
    cout << endl; 
}

void freeLL(Node* head)
{
    Node* temp;
    while (head != nullptr)
    {
        temp = head;      
        head = head->next; 
        delete temp;      
    }
}

int main()
{
    int n, value;
    Node* head = nullptr; 
    Node* newNode = nullptr;
    Node* tail = nullptr;

    cout << "Enter the number of nodes: ";
    cin >> n;

    if (n <= 0) {
        cout << "The number of nodes must be positive." << endl;
        return 1; 
    }

    for (int i = 1; i <= n; i++)
    {
        newNode = new Node();
        cout << "Enter data for node " << i << ": ";
        cin >> newNode->data;   
        newNode->next = nullptr; 

        if (head == nullptr)  
        {
            head = newNode; 
            tail = head;     
        }
        else  
        {
            tail->next = newNode;  
            tail = newNode;       
        }
    }

    
    cout << "The linked list is: ";
    printLL(head);
    freeLL(head);

    return 0;
}
