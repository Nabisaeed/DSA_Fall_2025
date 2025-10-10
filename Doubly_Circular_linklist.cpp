#include <iostream>
using namespace std;

// Node structure for circular doubly linked list
class node {
public:
    int data;      // Data part of the node
    node* next;    // Pointer to the next node
    node* prev;    // Pointer to the previous node
};

// Global pointer to the head (starting node) of the list
node* head = nullptr;

// --------------------------- INSERTION OPERATIONS ---------------------------

// Insert a new node at the beginning of the list
void insertAtStart(int value) {
    node* newnode = new node;
    newnode->data = value;

    // Case 1: Empty list — new node points to itself in both directions
    if (head == nullptr) {
        newnode->next = newnode;
        newnode->prev = newnode;
        head = newnode;
        return;
    }

    // Case 2: Non-empty list — adjust previous and next links
    node* last = head->prev;   // Last node (tail) before insertion

    // Linking newnode between last and head
    newnode->next = head;
    newnode->prev = last;

    last->next = newnode;
    head->prev = newnode;

    // Update head to the new node
    head = newnode;
}

// Insert a new node at the end of the list
void insertAtEnd(int value) {
    node* newnode = new node;
    newnode->data = value;

    // If list is empty, this is same as inserting at start
    if (head == nullptr) {
        newnode->next = newnode;
        newnode->prev = newnode;
        head = newnode;
        return;
    }

    // Identify the last node (head->prev always points to the tail)
    node* last = head->prev;

    // Place newnode between last and head
    newnode->next = head;
    newnode->prev = last;

    last->next = newnode;
    head->prev = newnode;
}

// Insert a node at a specific position in the list
void insertAtPosition(int pos, int value) {
    if (pos <= 1) { // If position is 1 or less, insert at start
        insertAtStart(value);
        return;
    }

    node* newnode = new node;
    newnode->data = value;

    node* temp = head;
    int count = 1;

    // Traverse to the (pos-1)th node or stop if circular link reached again
    while (count < pos - 1 && temp->next != head) {
        temp = temp->next;
        count++;
    }

    // Insertion between temp and temp->next
    node* nextnode = temp->next;
    temp->next = newnode;
    newnode->prev = temp;
    newnode->next = nextnode;
    nextnode->prev = newnode;
}

// --------------------------- DELETION OPERATIONS ---------------------------

// Delete node from the beginning of the list
void deleteAtStart() {
    if (head == nullptr) {
        cout << "List is empty!\n";
        return;
    }

    // Case 1: Single node — simply delete and reset head
    if (head->next == head) {
        delete head;
        head = nullptr;
        return;
    }

    // Case 2: Multiple nodes — adjust circular connections
    node* last = head->prev; // Last node
    node* temp = head;       // Node to delete

    head = head->next;       // Move head to next node
    head->prev = last;       // Update new head’s prev pointer
    last->next = head;       // Maintain circular link

    delete temp;             // Delete old head
}

// Delete node from the end of the list
void deleteAtEnd() {
    if (head == nullptr) {
        cout << "List is empty!\n";
        return;
    }

    // Case 1: Single node
    if (head->next == head) {
        delete head;
        head = nullptr;
        return;
    }

    // Case 2: Multiple nodes
    node* last = head->prev;         // Last node
    node* secondLast = last->prev;   // Node before last

    secondLast->next = head;         // Bypass the last node
    head->prev = secondLast;         // Update head’s prev pointer

    delete last;
}

// Delete node from a specific position
void deleteAtPosition(int pos) {
    if (head == nullptr) {
        cout << "List is empty!\n";
        return;
    }

    // If position is 1, use deleteAtStart()
    if (pos == 1) {
        deleteAtStart();
        return;
    }

    node* temp = head;
    int count = 1;

    // Traverse to the desired position or stop if loop completes
    while (count < pos && temp->next != head) {
        temp = temp->next;
        count++;
    }

    // If position is invalid (larger than list size)
    if (count < pos) {
        cout << "Invalid position!\n";
        return;
    }

    // Connect neighboring nodes, skipping over the deleted one
    node* prevnode = temp->prev;
    node* nextnode = temp->next;

    prevnode->next = nextnode;
    nextnode->prev = prevnode;

    // Edge case: if deleting head node
    if (temp == head)
        head = nextnode;

    delete temp;
}

// --------------------------- DISPLAY OPERATION ---------------------------

// Traverses the circular doubly linked list once and prints data
void display() {
    if (head == nullptr) {
        cout << "List is empty!\n";
        return;
    }

    node* temp = head;
    cout << "List (circular): ";

    // Use do-while since circular list must print head at least once
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}

// --------------------------- DRIVER FUNCTION ---------------------------

int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtStart(5);
    insertAtPosition(3, 15);
    display();  // Expected: 5 10 15 20 30

    deleteAtStart();
    display();  // Expected: 10 15 20 30

    deleteAtEnd();
    display();  // Expected: 10 15 20

    deleteAtPosition(2);
    display();  // Expected: 10 20

    return 0;
}
