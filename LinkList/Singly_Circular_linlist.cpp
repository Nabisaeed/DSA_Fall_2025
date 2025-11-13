#include <iostream>
using namespace std;

// Node structure representing each element of the circular linked list
class node {
public:
    int data;
    node* next;
};

node* head = nullptr; // Global head pointer for the circular linked list

// Function to insert a new node at the beginning of the list
void insertAtStart(int value) {
    node* newnode = new node;
    newnode->data = value;

    // If the list is empty, make the node point to itself
    if (head == nullptr) {
        newnode->next = newnode;
        head = newnode;
        return;
    }

    // Traverse to the last node to maintain circular connection
    node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newnode;   // Link last node to new node
    newnode->next = head;   // New node now points to old head
    head = newnode;         // Move head to new node
}

// Function to insert a new node at the end of the list
void insertAtEnd(int value) {
    node* newnode = new node;
    newnode->data = value;

    if (head == nullptr) {
        newnode->next = newnode;
        head = newnode;
        return;
    }

    node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newnode;
    newnode->next = head;   // Maintain circular structure
}

// Function to insert a new node at a specific position (1-based index)
void insertAtPosition(int pos, int value) {
    if (pos <= 1) {
        insertAtStart(value);
        return;
    }

    node* newnode = new node;
    newnode->data = value;

    node* temp = head;
    int count = 1;

    // Traverse to the node before the desired position
    while (count < pos - 1 && temp->next != head) {
        temp = temp->next;
        count++;
    }

    // Insert between temp and temp->next
    newnode->next = temp->next;
    temp->next = newnode;
}

// Function to delete the first node of the list
void deleteAtStart() {
    if (head == nullptr) {
        cout << "List is empty!\n";
        return;
    }

    node* temp = head;

    // If only one node exists
    if (head->next == head) {
        delete head;
        head = nullptr;
        return;
    }

    // Move to the last node to update its next pointer
    node* last = head;
    while (last->next != head)
        last = last->next;

    last->next = head->next; // Connect last node to second node
    head = head->next;       // Move head forward
    delete temp;             // Delete old head
}

// Function to delete the last node of the list
void deleteAtEnd() {
    if (head == nullptr) {
        cout << "List is empty!\n";
        return;
    }

    node* temp = head;

    // If only one node exists
    if (head->next == head) {
        delete head;
        head = nullptr;
        return;
    }

    node* prev = nullptr;
    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = head;   // Connect second last node to head
    delete temp;         // Delete last node
}

// Function to delete a node from a specific position
void deleteAtPosition(int pos) {
    if (head == nullptr) {
        cout << "List is empty!\n";
        return;
    }

    // Delete from beginning if position is 1
    if (pos == 1) {
        deleteAtStart();
        return;
    }

    node* temp = head;
    node* prev = nullptr;
    int count = 1;

    // Traverse until reaching the desired position
    while (count < pos && temp->next != head) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    // If position exceeds the length of the list
    if (count < pos) {
        cout << "Invalid position!\n";
        return;
    }

    prev->next = temp->next; // Skip over the node to be deleted
    delete temp;
}

// Function to display the circular linked list
void display() {
    if (head == nullptr) {
        cout << "List is empty!\n";
        return;
    }

    node* temp = head;
    cout << "Circular Linked List: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

// Driver function to test all operations
int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtStart(5);
    insertAtPosition(3, 15);

    display();

    deleteAtStart();
    display();

    deleteAtEnd();
    display();

    deleteAtPosition(2);
    display();

    return 0;
}
