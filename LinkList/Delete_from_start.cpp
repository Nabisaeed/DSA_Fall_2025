#include <iostream>
using namespace std;

// Define a node structure for the singly linked list
class node {
public:
    int data;      // Data stored in the node
    node *next;    // Pointer to the next node
};

// Global pointer to the head of the list, initially NULL
node *head = NULL;

// Function to insert a new node at the beginning of the list
void Insert(int n) {
    node *newnode = new node;  // Create a new node
    newnode->data = n;         // Set data
    newnode->next = head;      // Point to current head
    head = newnode;            // Update head to new node
}

// Function to delete the first node of the list
void delete_first_node() {
    if (head == NULL) {  // Check if list is empty
        cout << "There is nothing to delete" << endl;
        return;
    }

    node *temp = head;    // Temporarily hold the first node
    head = head->next;    // Move head to the next node
    delete temp;          // Delete the original first node
}

// Function to delete the last node of the list
void delete_last_node() {
    if (head == NULL) {  // Empty list check
        cout << "There is nothing to delete" << endl;
        return;
    }

    if (head->next == NULL) {  // If there's only one node
        delete head;
        head = NULL;
        return;
    }

    node *temp = head;

    // Traverse until the second last node
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    delete temp->next;    // Delete the last node
    temp->next = NULL;    // Set second last node's next to NULL
}

int main() {
    // Inserting nodes at the beginning
    Insert(200);  // List: 200
    Insert(300);  // List: 300 -> 200
    Insert(400);  // List: 400 -> 300 -> 200
    Insert(500);  // List: 500 -> 400 -> 300 -> 200

    // Uncomment to test deleting the first node
    // delete_first_node();

    // Delete the last node
    delete_last_node();   // Should delete node with data = 200

    // Print the current list
    node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}
