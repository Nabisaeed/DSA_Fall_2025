#include <iostream>
using namespace std;

// Define a node structure for the linked list
class node {
public:
    int data;      // Data stored in the node
    node *next;    // Pointer to the next node
};

// Head pointer to the start of the linked list
node *head = NULL;

// Function to insert a node at the beginning of the list
void Insert(int n) {
    node *newnode = new node; // Allocate memory for the new node
    newnode->data = n;        // Set the data
    newnode->next = head;     // Point the new node to the current head
    head = newnode;           // Update head to point to the new node
}

// Function to print all elements of the linked list
void print() {
    node *temp = head;        // Start from the head
    while (temp != NULL) {
        cout << temp->data << " ";  // Print current node's data
        temp = temp->next;          // Move to the next node
    }
    cout << endl;
}

// Function to insert a node at the end of the linked list
void Insert_At_end(int n) {
    node *newnode = new node;   // Create a new node
    newnode->data = n;          // Assign data
    newnode->next = NULL;       // Last node's next is NULL

    if (head == NULL) {         // If the list is empty
        head = newnode;         // Make the new node the head
        return;
    }

    node *temp = head;
    while (temp->next != NULL) {  // Traverse to the end of the list
        temp = temp->next;
    }
    temp->next = newnode;         // Link the last node to the new node
}

// Function to insert a node at a specific position
void Insert_at_specific_pos(int pos, int data) {
    node *newnode = new node;   // Create a new node
    newnode->data = data;       // Set the data

    node *temp = head;

    if (pos == 1) {
        Insert(data);           // If position is 1, insert at the beginning
        return;
    }

    // Traverse to the node before the desired position
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {         // If position is invalid (too large)
        cout << "Invalid Position" << endl;
        return;
    }

    // Insert the new node in the desired position
    newnode->next = temp->next;
    temp->next = newnode;
}

int main() {
    // Insert elements at the beginning
    Insert(100);
    Insert(200);
    Insert(300);

    // Insert element at the end
    Insert_At_end(600);

    // Try inserting at an invalid position (12)
}
