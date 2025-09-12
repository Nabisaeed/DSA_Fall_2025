#include <iostream>
using namespace std;

int main() {


    int arr[100]={12,34,50,100},pos,num;
    int n=4;
    
    cout<<"Enter the position at which you wanna insert an element "<<endl;
    cin>>pos;

     cout<<"Enter the number which you wanna insert "<<endl;
    cin>>num;


    for( int i=n; i>pos-1; i-- ){

        arr[i]=arr[i-1];
    }


    arr[pos-1]=num;


    n++;

    for( int i=0; i<n; i++){

        cout<<arr[i]<<"  ";

    }
    cout<<endl;




    
    return 0;
}