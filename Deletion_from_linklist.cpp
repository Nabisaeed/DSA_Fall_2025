#include <iostream>
using namespace std;

// Define the structure for a single node in the linked list.
class node {
public:
    int data;     // Data field to store the integer value.
    node *next;   // Pointer to the next node, establishing the link.
};

// Global pointer to the first node of the list.
// Initialized to NULL, indicating an empty list.
node *head = NULL;

// Function to insert a new node at the beginning (Head) of the linked list.
// This is an O(1) time complexity operation.
void Insert(int n) {
    // 1. Dynamically allocate memory for the new node on the heap.
    node *newnode = new node;

    // 2. Assign the given value to the data field.
    newnode->data = n;

    // 3. Link the new node to the existing list: 
    // The 'next' pointer of the new node is set to point to the current 'head'.
    newnode->next = head;

    // 4. Update the 'head' pointer, making the new node the new first node.
    head = newnode;
}

// Function to traverse and print all elements in the linked list.
// This is an O(n) time complexity operation.
void display() {
    // Start traversal from the head of the list.
    node *temp = head;

    // Iterate until the end of the list is reached (temp becomes NULL).
    while (temp != NULL) {
        // Print the data of the current node.
        cout << temp->data << " ";
        // Move the traversal pointer to the next node using the 'next' link.
        temp = temp->next;
    }

    cout << endl;
}

// Function to delete the first node (head) of the list.
// Note: Assumes head is NOT NULL, but should ideally include a check. O(1) time.
void delete_first_node() {
    // Store a pointer to the current head (the node to be deleted).
    if (head == NULL) {
        return; // Handle empty list case gracefully.
    }
    node *temp = head;

    // 1. Update the head to point to the second node in the list.
    // If the list has one node, head becomes NULL.
    head = head->next;

    // 2. Deallocate the memory of the original first node to prevent a memory leak.
    delete temp;
}

// Function to delete the last node of the list.
// This is an O(n) operation as it requires traversal to the second-to-last node.
void delete_last_node() {
    // Check for list with 0 or 1 node (critical edge cases)
    if (head == NULL || head->next == NULL) {
        delete_first_node(); // Re-use the existing logic for 0 or 1 node.
        return;
    }

    node *temp = head;

    // Traverse the list until 'temp' points to the second-to-last node.
    // The condition 'temp->next->next != NULL' ensures we stop one node before the last.
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    // 1. Deallocate the memory of the last node (which is temp->next).
    delete temp->next;

    // 2. Set the 'next' pointer of the new last node (temp) to NULL, 
    // terminating the list correctly.
    temp->next = NULL;
}

// Function to delete a node at a specified 1-based position. O(n) time.
void Delete_from_specific_position(int pos) {
    node *temp = head; // Pointer for traversal

    // --- Critical Edge Case Handling ---

    if (head == NULL) {
        cout << "There is nothing to delete" << endl;
        return;
    }

    if (pos == 1) {
        // Delegate to the specialized function for head deletion.
        delete_first_node();
        return;
    }
    
    // --- Traversal to the Node *Before* the Target ---
    
    // Loop to move 'temp' to the (pos - 1)th node.
    // The loop condition 'i < pos - 1' stops 'temp' correctly.
    // The check 'temp != NULL' prevents segmentation fault if 'pos' is too large.
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    
    // --- Position Validation ---

    // If temp is NULL, it means 'pos' was too large (out of bounds).
    // If temp->next is NULL, it means pos points past the end of the current list.
    if (temp == NULL || temp->next == NULL) {
        cout << "Invalid Position Please enter valid position" << endl;
        return;
    }
    
    // --- Deletion and Link Re-wiring ---

    // 1. Store a pointer to the node *after* the one to be deleted (temp->next->next).
    // This maintains the link to the rest of the list.
    node *node_to_keep_link_to = temp->next->next;
    
    // 2. Deallocate the memory of the node at position 'pos' (which is temp->next).
    delete temp->next;

    // 3. Re-wire the list: The 'next' pointer of the (pos-1)th node (temp)
    // now skips the deleted node and points to the node_to_keep_link_to.
    temp->next = node_to_keep_link_to;
}


int main() {
    // Build the list: 500 -> 400 -> 300 -> 200 -> NULL
    Insert(200);
    Insert(300);
    Insert(400);
    Insert(500);

    // Initial List Display
    cout << "Original List: ";
    display(); // Output: 500 400 300 200

    // Example of calling the specific position deletion:
    // This call deletes the node at position 1 (the head node, value 500).
    Delete_from_specific_position(1); 

    // List after deletion
    cout << "List after deleting position 1: ";
    display(); // Output: 400 300 200

    /* // To test other deletions, uncomment them:
    
    // Delete the last node (value 200)
    // delete_last_node();
    // cout << "List after deleting last node: ";
    // display(); 
    
    // Delete from a middle position (e.g., pos 2, which is value 300 after the previous deletion)
    // Delete_from_specific_position(2);
    // cout << "List after deleting position 2: ";
    // display();
    */

    return 0;
}