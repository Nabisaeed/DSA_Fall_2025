#include <iostream>
using namespace std;

class Stack{

    public:
    int data;
    Stack *next;


};

Stack *top=NULL;


void Push(int value){

    Stack *newelement= new Stack;
    newelement->data=value;

    newelement->next=top;

    top=newelement;

}

bool IsEmpty(){

    return top==NULL;
}

void display(){

    if(IsEmpty()){

        cout<<"The Stack is empty"<<endl;
        return;
    }

    Stack *temp=top;

    while(temp!=NULL){

        cout<<temp->data<<endl;
        temp=temp->next;
    }

}

void Pop(){

        if(IsEmpty()){

            cout<<"Stack underflow occured "<<endl;

            return;
        }

        Stack *temp=top;

        top=top->next;

        cout<<"The popped element is :"<<temp->data<<endl;

        delete temp;




    }

    void Peek(){

        if(IsEmpty()){
            cout<<"The stack is Empty"<<endl;

            return;
        }

        else{
            
            cout<<"The last element is "<<top->data<<endl;

        }
    }



int main() {

    Push(100);
    Push(200);
    Push(300);
    Push(400);

    // Pop();
    // Pop();
    // Pop();
    // Pop();
    // Pop();

    Peek();



    // display();
    

    return 0;
}