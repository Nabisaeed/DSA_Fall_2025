#include <iostream>
using namespace std;

class node{


    public:

    int data;
    node *next;
};

node *head=NULL;


void Insert(int n){


    node *newnode= new node;

    newnode->data=n;

    newnode->next=head;
    head=newnode;
}

void print(){

    node *temp=head;

    while(temp!=NULL){

        cout<<temp->data<<" ";

        temp=temp->next;
    }

    cout<<endl;
}

int main() {

    Insert(200);
    Insert(500);
    Insert(300);
    Insert(700);
    Insert(800);
    Insert(1000);

    print();
    

    return 0;
}