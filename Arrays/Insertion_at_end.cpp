#include <iostream>
using namespace std;

int main() {

    int arr[100]={12,33,50,100}, value;

    int size=4;

    cout<<"Enter the value to insert at the end "<<endl;
    cin>>value;


    arr[size]= value;

    size++;


    for(int i=0; i<size; i++){

        cout<<arr[i]<<"  ";

    }

    cout<<endl;



    
    return 0;
}