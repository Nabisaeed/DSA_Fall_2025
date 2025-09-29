#include <iostream>
using namespace std;

// Define the structure for a single node in the linked list.
class node {
public:
    int data;     // Data field to store the integer value.
    node* next;   // Pointer to the next node in the sequence, forming the link.
};

// Global pointer to the first node of the list. 
// Initialized to NULL, indicating an empty list.
node* head = NULL;

// Function to insert a new node at the beginning (Head) of the linked list.
// This is an O(1) time complexity operation.
void insert(int value) {
    // 1. Dynamically allocate memory for the new node on the heap.
    node* newnode = new node;

    // 2. Assign the given value to the data field of the new node.
    newnode->data = value;

    // 3. Link the new node to the existing list. 
    // The 'next' pointer of the new node is set to point to the current 'head'.
    newnode->next = head;

    // 4. Update the 'head' pointer to point to the newly created node, 
    // making it the new first node of the list.
    head = newnode;
}

// Function to search for a specific key value in the linked list.
// This is an O(n) time complexity operation, where 'n' is the number of nodes.
int search(int key) {
    int pos = 1;         // Initialize position counter to 1 (for 1-based indexing).
    node* temp = head;   // Start traversal from the head of the list.

    // Traverse the list until the end is reached (temp becomes NULL).
    while (temp != NULL) {
        
        // Check if the data in the current node matches the search key.
        if (temp->data == key) {
            // Key found: return the current 1-based position.
            return pos;
        }

        // Move to the next node by advancing the 'temp' pointer 
        // using the 'next' link of the current node.
        temp = temp->next;
        pos++;
    }

    // Key was not found after traversing the entire list.
    return -1; 
}

int main() {
    // Perform insertions. Since the 'insert' function adds to the head, 
    // the list is built in reverse order: 300 -> 200 -> 100 -> NULL
    insert(100);
    insert(200);
    insert(300);

    // Attempt to search for a value (1300) that is not in the list.
     // int index = search(1300);
    int index=search(200);
   

    // Create a temporary pointer for list traversal/printing later.
    node* temp = head;

    // Check the result of the search function.
    if (index >= 1) { // A return value of 1 or greater means the key was found.
        cout << "The position of the node is " << index << endl;
    } else { // A return value of -1 means the key was not found.
        cout << "The value is not found in linklist" << endl;
    }

    // --- List Traversal and Printing ---
    
    // Begin iteration from the 'head' of the list.
    while (temp != NULL) {
        // Print the data stored in the current node.
        cout << temp->data << " ";
        // Move the traversal pointer to the next node.
        temp = temp->next;
    }

    // Print a newline indicator and a final newline.
    cout << "endl" << endl;
    

    return 0;
}