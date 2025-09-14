#include <iostream>
using namespace std;

int main() {

    int arr[100]={12,33,100,50},num;

    int size=4;

   
    cout<<"Enter the value to insert in the start "<<endl;
cin>>num;

for( int i=size;i>0;i--)
{

    arr[i]=arr[i-1];
}

arr[0]=num;

size++;

for(int i=0; i<size; i++){

    cout<<arr[i]<<"  ";


}

cout<<endl;

    
    return 0;
}