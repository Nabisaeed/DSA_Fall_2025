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
    }}


    void Insert_At_end(int n){

        node *newnode=new node;


        newnode->data=n;
        newnode->next=NULL;


        if(head==NULL){

            head=newnode;
        }

        node *temp=head;
        while(temp->next!=NULL){

            temp=temp->next;
        }

        temp->next=newnode;
    }
int main() {

Insert(100);

Insert(200);

Insert(300);

Insert_At_end(600);

print();

    return 0;
}