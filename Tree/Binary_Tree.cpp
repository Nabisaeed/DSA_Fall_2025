#include <iostream>
using namespace std;
class Node{

    public:

    int data;
    Node *Left;
    Node* Right;

    Node(int value){

        data=value;
        Left=Right=NULL;

    }
};

Node* BuildTree(int A[], int &index, int size){

    if(index>=size){
        return NULL;

    }

    if(A[index]==-1){

        index++;
        return NULL;
    }

    Node * root= new Node(A[index]);

    index++;

    root->Left=BuildTree(A,index,size);
    root->Right=BuildTree(A,index, size);

    return root;


}
void PrintTree(Node * root){

    if(!root) return;

    

    PrintTree(root->Left);
      cout<<root->data<<" ";
    PrintTree(root->Right);
  

}





int main() {

int arr[]={2,4,3,-1,-1,5,-1,-1,7,8,-1,-1,9,-1,-1};

int index=0;

int size= sizeof(arr)/sizeof(arr[0]);

Node* root= BuildTree(arr,index,size);

PrintTree(root);


    
    return 0;
}