#include <iostream>
using namespace std;

class node {

    public:
    int data;
    node *next;
    node *prev;
};

node *head=NULL;


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

void Insert_at_specific_position(int data, int pos){

    node *newnode= new node;

    newnode->data=data;


    node *temp=head;

    if(head==NULL){

        cout<<"Invalid position"<<endl;

        return;
    }

    if(pos==1){

        Insert(data);
    }

    for(int i=1; i<pos-1 && temp->next!=NULL; i++){

        temp=temp->next;
    }

    newnode->next=temp->next;

    if(temp->next!=NULL){

        temp->next->prev=newnode;
    }

    newnode->prev=temp;

    temp->next=newnode;

    




}

int main() {

Insert(100);
Insert(200);
Insert(300);
Insert(400);
Insert(500);
Insert_at_specific_position(1000, 3);

node *temp=head;

while(temp!=NULL){

    cout<<temp->data<<" ";

    temp=temp->next;
}

cout<<endl;
   

    return 0;
}