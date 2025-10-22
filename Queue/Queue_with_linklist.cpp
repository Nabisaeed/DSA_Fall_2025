#include <iostream>
using namespace std;

class node{

    public:

    int data;
    node *next;


};

node *front=NULL, *rear=NULL;



bool IsEmpty(){

    return front==NULL;
}

void Enqueue(int value){

    node *newelement= new node;

    newelement->data=value;
    newelement->next=NULL;

    if(front==NULL){

        front=rear=newelement;
        return;
    }

    rear->next=newelement;
    rear=rear->next;

}

void display(){

    node* temp=front;

    while(temp!=NULL){

        cout<<temp->data<<" ";

        temp=temp->next;
    }

    cout<<endl;
}

void Dequeue(){

    node *temp=front;

    front=front->next;

    cout<<"The Dequeued element is :"<<temp->data<<endl;

    delete temp;
}

int main() {

    Enqueue(10);
    Enqueue(20);
    Enqueue(30);
    Enqueue(40);
    // Dequeue();
    display();
    

    return 0;
}