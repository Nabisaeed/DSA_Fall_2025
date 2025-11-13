#include <iostream>
using namespace std;

// Define a class to represent a node in the linked list
class node {
public:
    int data;       // The data stored in the node
    node *next;     // Pointer to the next node in the list
};

// Global head pointer, initially set to NULL (empty list)
node *head = NULL;

// Function to insert a new node at the beginning of the list
void Insert(int n) {
    node *newnode = new node; // Create a new node

    newnode->data = n;        // Assign the input data to the node
    newnode->next = head;     // Point the new node to the current head
    head = newnode;           // Update the head to the new node
}

// Function to print all elements of the linked list
void print() {
    node *temp = head;        // Start from the head of the list

    while (temp != NULL) {    // Traverse until the end of the list
        cout << temp->data << " "; // Print the data of the current node
        temp = temp->next;         // Move to the next node
    }

    cout << endl; // Print a newline after all elements
}

int main() {
    // Insert elements at the beginning of the list
    Insert(200);   // List becomes: 200
    Insert(500);   // List becomes: 500 -> 200
    Insert(300);   // List becomes: 300 -> 500 -> 200
    Insert(700);   // List becomes: 700 -> 300 -> 500 -> 200
    Insert(800);   // List becomes: 800 -> 700 -> 300 -> 500 -> 200
    Insert(1000);  // List becomes: 1000 -> 800 -> 700 -> 300 -> 500 -> 200

    // Print the current linked list
    print();       // Output: 1000 800 700 300 500 200

    return 0;
}
