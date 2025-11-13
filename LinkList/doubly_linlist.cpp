#include <iostream>
using namespace std;

// Define the structure for a node in a Doubly Linked List
class node{

    public:

    int data;

    node *next;
    node *prev; // Pointer to the previous node, essential for a Doubly Linked List

};

node * head=NULL; // Global pointer to the head of the list, initialized to NULL (empty list)


// Function to insert a new node at the beginning of the list (Head Insertion)
void Insert(int value){

    node * newnode= new node;

    newnode->data=value;
    newnode->next=head; // New node's next points to the current head
    newnode->prev=NULL; // New node's prev is NULL, as it's the new first node

    // This block handles the "doubly-linked" part when the list is NOT empty
    if(head!=NULL){

        // The old head's 'prev' pointer must be updated to point to the new node
        head->prev=newnode;
    }

    head=newnode; // Update the head pointer to the new node
}


int main() {

    // Insertion calls populate the list (e.g., 700 -> 600 -> 500 -> 400)
    Insert(400);
    Insert(500);
    Insert(600);
    Insert(700);

    // Initialize a temporary pointer for list traversal
    node* temp=head;

    // Traversal loop: prints elements from head to tail
    while(temp!=NULL){

        cout<<temp->data<<" ";

        // Move the temporary pointer to the next node
        temp=temp->next;
    }

    cout<<endl;


    return 0;
}