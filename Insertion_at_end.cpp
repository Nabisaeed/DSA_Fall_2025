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

    node *newnode= new node;
    newnode->data=value;
    newnode->next= head;
    newnode->prev=NULL;
    if(head!=NULL){

        head->prev=newnode;
    }

    head=newnode;
}

int main() {

    
Insert(100);
Insert(200);
Insert(300);    
Insert(400);    
Insert(500);

node *tail=head;

while(tail!=nullptr){
    cout<<tail->data<<" ";

    tail=tail->next;
}

cout<<endl;

node* temp=head;

while(temp!=NULL){

    temp=temp->next;
    if(temp->next==NULL){

        break;
    }
}

    while(temp!=head){

        cout<<temp->data<<" ";

        temp=temp->prev;
    }

    cout<<endl;





cout<<endl;
    return 0;
}