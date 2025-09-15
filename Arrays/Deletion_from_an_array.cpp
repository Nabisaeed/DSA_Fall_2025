#include <iostream>
using namespace std;

int main() {

    int arr[]={23,45,67,89,100}, pos;

    cout<<"Enter the position from which you want to remove an element"<<endl;
    cin>>pos;

    for(int i=pos-1; i<5; i++){

        arr[i]=arr[i+1];


    }

    for(int i=0; i<4; i++){

        cout<<arr[i]<<" ";
    }

    cout<<endl;


    
    return 0;
}