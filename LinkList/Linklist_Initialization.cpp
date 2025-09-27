#include <iostream>
using namespace std;

// Singly linked list node structure
class node {
public:
    int data;      // Holds the value of the node
    node* next;    // Pointer to the next node in the list
};

// Inserts a new node with value 'n' at the beginning of the list
void Insert(int n, node*& head) {
    node* newnode = new node; // Allocate memory for the new node
    newnode->data = n;        // Initialize node's data
    newnode->next = head;     // Link new node to the current head
    head = newnode;           // Update head to the new node
}

int main() {
    node* head = nullptr; // Start with an empty list

    Insert(20, head);     // First insertion: head -> 20
    Insert(200, head);    // Second insertion: head -> 200 -> 20

    // No output or traversal implemented — list is built in memory only

    return 0;
}
