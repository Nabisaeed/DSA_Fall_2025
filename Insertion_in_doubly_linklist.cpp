#include <iostream>
using namespace std;

// Node structure for a doubly linked list
class node {
public:
    int data;
    node* next;
    node* prev;
};

node* head = NULL; // Head pointer to keep track of the start of the list

// ================== INSERT AT BEGINNING ==================
void Insert(int value) {
    node* newnode = new node;
    newnode->data = value;

    // New node will always point to the current head
    newnode->next = head;
    newnode->prev = NULL; // Since this is the new first node

    // If list already has elements, link the previous head to this new node
    if (head != NULL)
        head->prev = newnode;

    // Update head to the new node
    head = newnode;
}

// ================== INSERT AT SPECIFIC POSITION ==================
void Insert_at_specific_position(int data, int pos) {
    node* newnode = new node;
    newnode->data = data;

    // Handle the case where the list is empty
    if (head == NULL) {
        cout << "List is empty.\n";
        if (pos == 1)
            Insert(data); // Only valid if position is 1
        else
            cout << "Invalid position!\n";
        return;
    }

    // Insert at the beginning
    if (pos == 1) {
        Insert(data);
        return;
    }

    // Traverse to the node before the desired position
    node* temp = head;
    for (int i = 1; i < pos - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }

    // Link the new node in between temp and temp->next
    newnode->next = temp->next;
    newnode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newnode; // Update the next node’s prev pointer

    temp->next = newnode;
}

// ================== INSERT AT END ==================
void Insert_at_end(int value) {
    node* newnode = new node;
    newnode->data = value;
    newnode->next = NULL;

    // If the list is empty
    if (head == NULL) {
        newnode->prev = NULL;
        head = newnode;
        return;
    }

    // Move to the last node
    node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    // Link the last node and the new node
    temp->next = newnode;
    newnode->prev = temp;
}

// ================== DELETE FIRST NODE ==================
void delete_First_node() {
    if (head == NULL) {
        cout << "There is nothing to delete.\n";
        return;
    }

    node* temp = head;

    // Case: only one node exists
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    // Move head to the next node and unlink the old first node
    head = head->next;
    head->prev = NULL;
    delete temp;
}

// ================== DELETE LAST NODE ==================
void delete_last_node() {
    if (head == NULL) {
        cout << "There is nothing to delete.\n";
        return;
    }

    node* temp = head;

    // Case: only one node exists
    if (temp->next == NULL) {
        delete temp;
        head = NULL;
        return;
    }

    // Traverse to the second-last node
    while (temp->next->next != NULL)
        temp = temp->next;

    delete temp->next;  // Delete the last node
    temp->next = NULL;  // Mark new end
}

// ================== DELETE AT SPECIFIC POSITION ==================
void delete_at_specific_position(int pos) {
    if (head == NULL) {
        cout << "There is nothing to delete.\n";
        return;
    }

    // Delete from beginning
    if (pos == 1) {
        delete_First_node();
        return;
    }

    node* temp = head;

    // Traverse to the node before the one we want to delete
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    // If position is invalid or out of range
    if (temp == NULL || temp->next == NULL) {
        cout << "Invalid position entered. Please retry.\n";
        return;
    }

    // Store the reference of the node to be deleted
    node* toDelete = temp->next;

    // Link the previous node with the next node of the one being deleted
    temp->next = toDelete->next;

    if (toDelete->next != NULL)
        toDelete->next->prev = temp;

    delete toDelete;
}

// ================== DISPLAY LIST ==================
void display() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    node* temp = head;
    cout << "Doubly Linked List (forward): ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// ================== MAIN FUNCTION ==================
int main() {
    Insert(100);
    Insert(200);
    Insert(300);
    Insert(400);
    Insert(500);

    delete_at_specific_position(3);
    delete_last_node();

    // Insert_at_end(1000);
    // delete_First_node();
    // Insert_at_specific_position(1000, 3);

    display();

    return 0;
}
