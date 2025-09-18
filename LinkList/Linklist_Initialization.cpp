#include <iostream>
using namespace std;



class node{


    public:

    int data;

    node * next;
};

void Insert(int n, node *& head){

    node *newnode= new node;

    newnode->data=n;

    newnode->next=head;

    head=newnode;


}



int main() {

    node * head=nullptr;

    Insert(20, head);
    Insert(200, head);
    
    return 0;
}