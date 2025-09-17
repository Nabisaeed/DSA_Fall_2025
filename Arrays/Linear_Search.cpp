#include <iostream>
using namespace std;

int LinearSearch(int A[], int n, int target){

    for(int i=0; i<n; i++){

        if(A[i]==target){

            return i;
        }
    }

    return -1;
}

int main() {

    int arr[]={12,120,34,56,78,89}, num;

    cout<<"Enter the value to search in an arry "<<endl;
    cin>>num;

    int index=LinearSearch(arr, 6, num);

    if(index>=0){

        cout<<"The element is found at position "<<index+1<<endl;
    }

    else{

        cout<<"The value is not found Sorry"<<endl;
    }


    
    return 0;
}